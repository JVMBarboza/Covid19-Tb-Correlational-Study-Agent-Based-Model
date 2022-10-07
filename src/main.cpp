#include <iostream>
#include <fstream>
#include <math.h>
#include <time.h>

using namespace std;

#include "../lib/variables.h"
#include "../lib/define.h"
#include "../lib/randomNumberGenerator.cpp"
#include "../lib/person.h"

Person *person[L+2][L+2];

#include "../lib/calcAgeDistribution.cpp"
#include "../lib/calcNaturalDeathDistribution.cpp"
#include "../lib/calcRecoveryProbabilities.cpp"
#include "../lib/studyInfectionInNeighborhood.cpp"
#include "../lib/calcTbAttributes.h"
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
int Person::total_tbDeath = 0;
int Person::total_coinfectionDeath = 0;

int Person::dailyDeathsByCovid = 0;
int Person::dailyDeathsByTb    = 0;
int Person::dailyDeathsByCoinfection = 0;

int Person::availableBeds = 0;
int Person::availableBedsICU = 0;

int Person::total_TBS  = 0;
int Person::total_TBLS = 0;
int Person::total_TBLSEXOGENOUS = 0;
int Person::total_TBTS = 0;



int main(int argc, char *argv[]){
    
    double rn;
    
    ////////////////////////////   FILE MANAGEMENT ////////////////////////////////////////

    if(PRINTCOUNTERSONFILE==TRUE){
        of.open("output.csv", ios::out);
        ofTB.open("outputTB.csv", ios::out);
    }

    if(PRINTLATTICEONFILEATSTART==TRUE){
        lf.open("lattice.csv", ios::out);
        lfTB.open("latticeTb.csv", ios::out);
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
    beginLatticeInfectionTb();
    updateLattice();

    printSettings();
    printTbOnScreen(0);

    if( of.is_open() ){
        printCountOnFile(TRUE);
    }

    if( ofTB.is_open() ){
        printTbCountOnFile(TRUE);
    }

    if( lf.is_open() ){
        printLatticeOnFile();
    }

    if( lfTB.is_open() ){
        printTbLatticeOnFile();
    }


    ////////////////////////// TB SPREADS IN POPULATION ///////////////////////////////////////
    for(int time=1; time<=TbSpreadingDays; time++){

        for(int i = 1; i <= L; i++){ //RUNNING TRHOUGH LATTICE IN GIVEN TIME
            for(int j = 1; j <= L; j++){
            
                if( person[i][j]->getAge() >= person[i][j]->getAgeOfDeath() ){
                    person[i][j]->death( NATURALCAUSES, sortPersonAge(), sortPersonAgeOfDeath(), sortPersonGender(), sortPopPorcentageInIsolation() );
                }
                else{
                    switch( person[i][j]->getTbState() ){
                        
                        case STB:
                            
                            if( veryfiesTbInfectionByNeighbors(i,j) ){ //contagion
                                person[i][j]->changeTbState(LSTB, NA);
                                checkTbActivation(i,j);
                            }
                            else{
                                person[i][j]->setTbSwap(STB);
                            }
                            break;

                        case LSTB:
                                                    
                            if( person[i][j]->getTypeOfTbInfection()==firstActivationNone ){
                                person[i][j]->setTbSwap( LSTB );
                            }
                            else if( (person[i][j]->getTypeOfTbInfection()==firstActivationSactive) && (person[i][j]->getAge()<(person[i][j]->getActiveTbDays()+fastProgression)) ){
                                
                                // verifies daily prob of fast progression to active TB
                                if( sortRandomNumber(&R) <= dailyProbOfFastProgr ){ 
                                    person[i][j]->changeTbState(TSTB, NA);
                                }
                                else{
                                    person[i][j]->setTbSwap( LSTB );
                                }
                            }
                            else if( (person[i][j]->getTypeOfTbInfection()==firstActivationSactive) && (person[i][j]->getAge()>=person[i][j]->getActiveTbDays()) ){
                                person[i][j]->changeTbState(TSTB, NA);
                            }
                            else{
                                person[i][j]->setTbSwap( LSTB );
                            }
                    
                            break;

                        case LSTBEXOGENOUS:
                            
                            if( person[i][j]->getTypeOfTbInfection() == secondActivationNone ){
                                newExposure(i,j);
                            }
                            else if( (person[i][j]->getTypeOfTbInfection()==secondActivationSactive) && (person[i][j]->getAge()<(person[i][j]->getStateTotalDays()+fastProgression)) ){
                                    
                                if( sortRandomNumber(&R) < dailyProbOfFastProgr2 ){ // fast progression to active TB
                                    person[i][j]->changeTbState(TSTB, NA);
                                }
                                else{
                                    newExposure(i,j);
                                }
                            }
                            else if( (person[i][j]->getTypeOfTbInfection()==secondActivationSactive) && (person[i][j]->getAge()>=person[i][j]->getActiveTbDays()) ){
                                person[i][j]->changeTbState(TSTB, NA);
                            }
                            else{
                                newExposure(i,j);
                            }
                            break;

                        case TSTB:
                            
                            probDeath         = MuS;
                            //probCureTreatment = 1.0;
                            
                            if( sortRandomNumber(&R) <= probDeath )
                                person[i][j]->death( TB, sortPersonAge(), sortPersonAgeOfDeath(), sortPersonGender(), sortPopPorcentageInIsolation() );
                            else
                                person[i][j]->setTbSwap( TSTB );
                            
                            break;

                        default:
                            break;
                    }
                }
            }
        }

        if(time != TbSpreadingDays)//se ultimo dia, realiza update na linha 326
            updateLattice();

        if( PRINTONSCREENTB==TRUE )
            printTbOnScreen(time);

        Person::dailyDeathsByTb = 0;

    }


    //////////////////////////  COVID EPIDEMICS STARTS ////////////////////////////////////////

    beginLatticeInfection();
    updateLattice();
    
    for(int time=1; time <= CovidEpidemyDays; time++){

        for(int i = 1; i <= L; i++){ //RUNNING TRHOUGH LATTICE IN GIVEN TIME
            for(int j = 1; j <= L; j++){

                if( person[i][j]->getAge() >= person[i][j]->getAgeOfDeath() ){
                    person[i][j]->death( NATURALCAUSES, sortPersonAge(), sortPersonAgeOfDeath(), sortPersonGender(), sortPopPorcentageInIsolation() );
                }
                else{
                    switch( person[i][j]->getState() ){
                        
                        case S:

                            if( veryfiesCovidInfectionByNeighbors(i,j) ) //contagion 
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
                                
                                if( person[i][j]->getTbState() == TSTB ){
                                    person[i][j]->changeState(ISSevere, sortTotalDaysOnState(minISSevere, maxISSevere)); 
                                }
                                else{

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
                                
                                if(person[i][j]->getTbState() == TSTB){
                                    probRecoveryCovid = 1.0 - 2.21*(1.0 - calcRecoveryProbH(i,j));
                                    if(probRecoveryCovid < 0.0)
                                        probRecoveryCovid = 0.0;
                                }
                                else{
                                    probRecoveryCovid = calcRecoveryProbH(i,j);
                                }

                                rn = sortRandomNumber(&R);
                                
                                if( rn < probRecoveryCovid ){
                                    person[i][j]->changeState(Recovered, -1); 
                                }
                                else if( Person::availableBedsICU > 0){
                                    person[i][j]->changeState(ICU, sortTotalDaysOnState(minICU, maxICU)); 
                                }
                                else{
                                    person[i][j]->death( COVID, sortPersonAge(), sortPersonAgeOfDeath(), sortPersonGender(), sortPopPorcentageInIsolation() ); 
                                }
                                
                            }
                            else{
                                person[i][j]->setSwap(H);
                            }
                            break;

                        case ICU:

                            if( person[i][j]->getDaysOnState() >= person[i][j]->getStateTotalDays() ){
                                
                                if(person[i][j]->getTbState() == TSTB){
                                    probRecoveryCovid = 1.0 - 2.21*(1.0 - calcRecoveryProbICU(i,j));
                                    if( probRecoveryCovid < 0.0 )
                                        probRecoveryCovid = 0.0;
                                }
                                else{
                                    probRecoveryCovid = calcRecoveryProbICU(i,j);
                                }

                                rn = sortRandomNumber(&R);

                                if( rn < probRecoveryCovid ){
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

                    }//covid switch case end

                    switch( person[i][j]->getTbState() ){
                        
                        case STB:
                            if( veryfiesTbInfectionByNeighbors(i,j) ){ //contagion
                                
                                person[i][j]->changeTbState(LSTB, NA);
                                checkTbActivation(i,j);
                            
                            }
                            else{
                                person[i][j]->setTbSwap(STB);
                            }
                            break;

                        case LSTB:
                        
                            if( (person[i][j]->getState()==ISSevere) || (person[i][j]->getState()==H) || (person[i][j]->getState()==ICU) ){
                                
                                if( person[i][j]->getDaysOnTbState() >= timeForActivateCoinfection ){ //COINFECTION TAKES PLACE
                                        person[i][j]->changeTbState(TSTB, NA);
                                }
                            }
                            else{ //no covid coinfection
                            
                                if( person[i][j]->getTypeOfTbInfection() == firstActivationNone ){
                                    person[i][j]->setTbSwap( LSTB ); //newExposure(i,j);
                                }
                                else if( (person[i][j]->getTypeOfTbInfection()==firstActivationSactive) && (person[i][j]->getAge()<(person[i][j]->getActiveTbDays()+fastProgression)) ){

                                    if( sortRandomNumber(&R) < dailyProbOfFastProgr ){ 
                                        person[i][j]->changeTbState(TSTB, NA);
                                    }
                                    else{
                                        person[i][j]->setTbSwap( LSTB );
                                    }
                                }
                                else if( (person[i][j]->getTypeOfTbInfection()==firstActivationSactive) && (person[i][j]->getAge()>=person[i][j]->getActiveTbDays()) ){
                                    person[i][j]->changeTbState(TSTB, NA);
                                }
                                else{
                                    person[i][j]->setTbSwap( LSTB );
                                }
                            
                            }
                            break;

                        case LSTBEXOGENOUS:

                            if( (person[i][j]->getState() == ISSevere) || (person[i][j]->getState() == H) || (person[i][j]->getState() == ICU) ){
                                
                                if( person[i][j]->getDaysOnTbState() >= timeForActivateCoinfection ){ //COINFECTION TAKES PLACE
                                        person[i][j]->changeTbState(TSTB, NA);
                                }
                            }
                            else{
                                if( person[i][j]->getTypeOfTbInfection() == secondActivationNone ){
                                    newExposure(i,j);
                                }
                                else if( (person[i][j]->getTypeOfTbInfection()==secondActivationSactive) && (person[i][j]->getAge()<(person[i][j]->getStateTotalDays()+fastProgression)) ){
                                    
                                    if( sortRandomNumber(&R) < dailyProbOfFastProgr2 ){ // fast progression to active TB
                                        person[i][j]->changeTbState(TSTB, NA);
                                    }
                                    else{
                                        newExposure(i,j);
                                    }
                                }
                                else if( (person[i][j]->getTypeOfTbInfection()==secondActivationSactive) && (person[i][j]->getAge()>=person[i][j]->getActiveTbDays()) ){
                                    person[i][j]->changeTbState(TSTB, NA);
                                }
                                else{
                                    newExposure(i,j);
                                }
                            }
                            break;

                        case TSTB:
                            if( (person[i][j]->getState() == ISSevere) || (person[i][j]->getState() == H) || (person[i][j]->getState() == ICU) ){
                                probDeath = MuS*2.17;
                            }
                            else{
                                probDeath = MuS;
                            }

                            if( sortRandomNumber(&R) <= probDeath ){
                                if((person[i][j]->getState() == ISSevere) || (person[i][j]->getState() == H) || (person[i][j]->getState() == ICU))
                                    person[i][j]->death( COINFECTION, sortPersonAge(), sortPersonAgeOfDeath(), sortPersonGender(), sortPopPorcentageInIsolation() );
                                else
                                    person[i][j]->death( TB, sortPersonAge(), sortPersonAgeOfDeath(), sortPersonGender(), sortPopPorcentageInIsolation() );
                            }
                            else
                                person[i][j]->setTbSwap( TSTB );
                            
                            break;

                        default:
                            break;
                    } //end of tb switch case
                }


            }//for j end
        }//for i end

        updateLattice();

        if( PRINTONSCREEN==TRUE )
            printOnScreen(time);

        if( PRINTONSCREENTB==TRUE )
            printTbOnScreen(time);

        if( of.is_open() )
            printCountOnFile(FALSE);
            
        if( ofTB.is_open() )
            printTbCountOnFile(FALSE);
        
        Person::dailyDeathsByCovid = 0;
        Person::dailyDeathsByTb    = 0;
        Person::dailyDeathsByCoinfection = 0;

    }//for time end


    ////////////////////////////   CLOSING CREATED FILES ////////////////////////////////////////
    if( of.is_open() )
        of.close();

    if( ofTB.is_open() )
        ofTB.close();

    if( lf.is_open() )
        lf.close();

    if( lfTB.is_open() )
        lfTB.close();

    ////////////////////////////   SIMULATION END   ////////////////////////////////////////
    return 0;

}