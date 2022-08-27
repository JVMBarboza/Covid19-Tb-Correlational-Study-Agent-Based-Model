#include <iostream>
#include <fstream>
#include <math.h>
#include <time.h>

using namespace std;

ofstream of;
ofstream lf;

#include "../lib/define.h"
#include "../lib/randomNumberGenerator.cpp"

double maxRandomContacts;
double minRandomContacts;

double numberOfHospitalBeds;
double numberOfICUBeds;

#include "../lib/person.h"
#include "../lib/personTb.h"
Person *person[L+2][L+2];

#include "../lib/calcAgeDistribution.cpp"
#include "../lib/calcNaturalDeathDistribution.cpp"
#include "../lib/studyInfectionInNeighborhood.cpp"
#include "../lib/calcRecoveryProbabilities.cpp"
#include "../lib/sortPersonsAtributesFromDistributions.cpp"
#include "../lib/lattice.cpp"
#include "../lib/printingOnScreen.cpp"
#include "../lib/printingOnFile.cpp"


int Person::total_S = 0;
int Person::total_E = 0;               
int Person::total_IP = 0;               
int Person::total_IA = 0;               
int Person::total_ISLight = 0;
int Person::total_ISModerate = 0;    
int Person::total_ISSevere = 0;                
int Person::total_H = 0;               
int Person::total_ICU = 0;            
int Person::total_Recovered = 0;   

int Person::total_naturalDeath = 0;  
int Person::total_covidDeath = 0;       
int Person::dailyDeathsByCovid = 0;

int Person::availableBeds = 0;
int Person::availableBedsICU = 0;



int main(int argc, char *argv[]){
    
    double rn;
    
    ////////////////////////////   FILE MANAGEMENT ////////////////////////////////////////

    if(PRINTCOUNTERSONFILE==TRUE){
        of.open("output.csv", ios::out);
    }

    if(PRINTLATTICEONFILEATSTART==TRUE){
        lf.open("lattice.csv", ios::out);
    }


    /////////////  SETTING PARAMETERS DEPENDING ON DEMOGRAPHIC DENSITY //////////////////

    #if(Density==LOW)
    {
	    //printf("LOW demographic density\n");
	
        maxRandomContacts = 2.5;
        minRandomContacts = 2.5;
        
        numberOfHospitalBeds = 716;  
        numberOfICUBeds      = 66;

    }
    #else
    {
    	//printf("HIGH demographic density\n");
    
    	maxRandomContacts = 120.5;
    	minRandomContacts = 2.5;
    
    	numberOfHospitalBeds = 38;  
    	numberOfICUBeds      = 10;
    }
    #endif
    
    
    //////////////////////////  SIMULATION SETUP ////////////////////////////////////////

    beginAgeDistribution();
    beginNaturalDeathDistribution();
    beginLattice( numberOfHospitalBeds*(1 - AverageOcupationRateBeds) , numberOfICUBeds*(1 - AverageOcupationRateBedsICU) );
    //beginLatticeInfection();
    updateLattice();

    printSettings();
    printOnScreen(0);

    if( of.is_open() ){
        printCountOnFile(TRUE);
    }

    if( lf.is_open() ){
        printLatticeOnFile();
    }


    //////////////////////////  SIMULATION DYNAMICS ////////////////////////////////////////
    for(int time=1; time <= DAYS; time++){

        for(int i = 1; i <= L; i++){ //RUNNING TRHOUGH LATTICE IN A GIVEN TIME
            for(int j = 1; j <= L; j++){

                if( person[i][j]->getAge() >= person[i][j]->getAgeOfDeath() ){
                    person[i][j]->death( NATURALCAUSES, sortPersonAge(), sortPersonAgeOfDeath(), sortPersonGender(), sortPopPorcentageInIsolation() );
                }
                else{
                    switch( person[i][j]->getState() ){
                        
                        case S:

                            if( veryfiesInfectionByNeighbors(i,j) == 1 ) //contagion 
                                person[i][j]->changeState(E, sortTotalDaysOnState(minLatency, maxLatency) );
                            else                          
                                person[i][j]->setSwap(S);// no contagion, remains S

                            break;
                            
                        case E:

                            if( person[i][j]->getDaysOnState() >= person[i][j]->getStateTotalDays() )
                                person[i][j]->changeState(IP, sortTotalDaysOnState(minIP, maxIP));
                            else
                                person[i][j]->setSwap(E);

                            break;

                        case IP:
                            
                            if( person[i][j]->getDaysOnState() >= person[i][j]->getStateTotalDays() ){ 
                                
                                rn = sortRandomNumber(&R);
                                
                                if(rn < ProbIPtoIA){ // move to IA state
                                    person[i][j]->changeState(IA, sortTotalDaysOnState(minIA, maxIA) );
                                }
                                else{ // move to some type of IS
                                    
                                    rn = sortRandomNumber(&R);
                                    
                                    if( rn < ProbToBecomeISLight ){
                                        person[i][j]->changeState(ISLight, sortTotalDaysOnState(minISLight, maxISLight)); 
                                    }
                                    else if( (rn >= ProbToBecomeISLight) && (rn < ProbToBecomeISLight+ProbToBecomeISModerate) ){
                                        person[i][j]->changeState(ISModerate, sortTotalDaysOnState(minISModerate, maxISModerate)); 
                                    }
                                    else{
                                        person[i][j]->changeState(ISSevere, sortTotalDaysOnState(minISSevere, maxISSevere)); 
                                    }
                                }
                            }
                            else{
                                person[i][j]->setSwap(IP); 
                            }

                            break;

                        case IA:

                            if ( person[i][j]->getDaysOnState() >= person[i][j]->getStateTotalDays() ){
                                person[i][j]->changeState(Recovered, -1);
                            }
                            else{
                                person[i][j]->setSwap(IA);
                            }
                            
                            break;

                        case ISLight:

                            if ( person[i][j]->getDaysOnState() >= person[i][j]->getStateTotalDays() ){
                                
                                rn = sortRandomNumber(&R);

                                if( rn < ProbISLightToISModerate){
                                    person[i][j]->changeState(ISModerate, sortTotalDaysOnState(minISModerate, maxISModerate)); 
                                }
                                else{
                                    person[i][j]->changeState(Recovered, -1); 
                                }
                            }
                            else{
                                person[i][j]->setSwap(ISLight); 
                            }

                            break;

                        case ISModerate:

                            if ( person[i][j]->getDaysOnState() >= person[i][j]->getStateTotalDays() ){
                                
                                rn = sortRandomNumber(&R);
                                
                                if( rn < calcRecoveryProbISModerate(i,j) ){
                                    person[i][j]->changeState(Recovered, -1); 
                                }
                                else{
                                    person[i][j]->changeState(ISSevere, sortTotalDaysOnState(minISSevere, maxISSevere)); 
                                }

                            }
                            else{
                                person[i][j]->setSwap(ISModerate);
                            }

                            break;

                        case ISSevere:

                            if( person[i][j]->getDaysOnState() >= person[i][j]->getStateTotalDays() ){
                                
                                rn = sortRandomNumber(&R);
                                
                                if( rn < calcRecoveryProbISSevere(i,j) ){
                                    person[i][j]->changeState(Recovered, -1); 
                                }
                                else{
                                    person[i][j]->death( COVID, sortPersonAge(), sortPersonAgeOfDeath(), sortPersonGender(), sortPopPorcentageInIsolation()); 
                                }

                            }
                            else{
                                if( Person::availableBeds > 0 ){
                                    person[i][j]->changeState(H, sortTotalDaysOnState(minH, maxH)); 
                                }
                                else{
                                    person[i][j]->changeState(ISSevere, sortTotalDaysOnState(minISSevere, maxISSevere)); 
                                }
                                
                            }
                            break;

                        case H:

                            if( person[i][j]->getDaysOnState() >= person[i][j]->getStateTotalDays() ){
                                
                                rn = sortRandomNumber(&R);

                                if( rn < calcRecoveryProbH(i,j) ){
                                    person[i][j]->changeState(Recovered, -1); 
                                }
                                else if( Person::availableBedsICU > 0){
                                    person[i][j]->changeState(ICU, sortTotalDaysOnState(minICU, maxICU)); 
                                }
                                else{
                                    person[i][j]->death( COVID, sortPersonAge(), sortPersonAgeOfDeath(), sortPersonGender(), sortPopPorcentageInIsolation()); 
                                }
                                
                                
                            }
                            else{
                                person[i][j]->setSwap(H);
                            }
                            break;

                        case ICU:

                            if( person[i][j]->getDaysOnState() >= person[i][j]->getStateTotalDays() ){
                                
                                rn = sortRandomNumber(&R);

                                if( rn < calcRecoveryProbICU(i,j) ){
                                    person[i][j]->changeState( Recovered, -1);
                                }
                                else{
                                    person[i][j]->death( COVID, sortPersonAge(), sortPersonAgeOfDeath(), sortPersonGender(), sortPopPorcentageInIsolation() );
                                }

                            }
                            else{
                                person[i][j]->setSwap(ICU); 
                            }

                            break;

                        case Recovered:
                            
                            person[i][j]->setSwap(Recovered); 
                            
                            break;

                        default:
                            break;

                    }//switch case end
                }


            }//for j end
        }//for i end

        updateLattice();

        if( PRINTONSCREEN==TRUE )
            printOnScreen(time);

        if( of.is_open() )
            printCountOnFile(FALSE); 
        
        Person::dailyDeathsByCovid = 0;

    }//for time end    


    ////////////////////////////   CLOSING CREATED FILES ////////////////////////////////////////
    if( of.is_open() )
        of.close();

    if( lf.is_open() )
        lf.close();

    ////////////////////////////   SIMULATION END   ////////////////////////////////////////
    
    return 0;

}