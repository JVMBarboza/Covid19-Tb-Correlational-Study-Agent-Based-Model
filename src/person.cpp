#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

#include "../lib/define.h"
#include "../lib/person.h"

//CONSTRUCTOR
//call: Person[i][j] = new Person(newAge, newAgeOfDeath, newGender, newState, newSwap, newStateTotalDays, newDaysOnState, newTreatmTotalDays, newDaysOnTreatm, newIsolation);
Person::Person(int i, int j, int newAge, int newAgeOfDeath, int newGender, int newState, int newSwap, int newStateTotalDays, int newDaysOnState, int newTreatmTotalDays, int newDaysOnTreatm, int newIsolation, int newTypeOfTbInfection, int newTbState, int newTbSwap, int newTbStateTotalDays, int newDaysOnTbState, int newActiveTbDays, int newActivation, int newTbExposures){
    
    //setting covid attributes
    setAge(newAge);
    setAgeOfDeath(newAgeOfDeath);
    setGender(newGender);
    setState(newState);
    setSwap(newSwap);
    setStateTotalDays(newStateTotalDays);
    setDaysOnState(newDaysOnState);
    setTreatmTotalDays(newTreatmTotalDays);
    setDaysOnTreatm(newDaysOnTreatm);
    setIsolation(newIsolation);

    //setting tb attributes
    setTypeOfTbInfection(newTypeOfTbInfection);
    setTbState(newTbState);
    setTbSwap(newTbSwap);
    setTbStateTotalDays(newTbStateTotalDays);
    setDaysOnTbState(newDaysOnTbState);
    setActiveTbDays(newActiveTbDays);
    setActivation(newActivation);
    setTbExposures(newTbExposures);


    if( (i>=1 && i<=L) && (j>=1 && j<=L) ){
        total_S++;   //only count individuals on the real lattice
        total_TBS++;
    }

}

//DESTRUCTOR
Person::~Person(void){}

//GETTERS
//covid
int Person::getAge(void){ return age; }
int Person::getAgeOfDeath(void){ return ageOfDeath; }
int Person::getGender(void){ return gender; }
int Person::getState(void){ return state; }
int Person::getSwap(void){ return swap; }
int Person::getStateTotalDays(void){ return stateTotalDays; }
int Person::getDaysOnState(void){ return daysOnState; }
int Person::getTreatmTotalDays(void){ return treatmTotalDays; }
int Person::getDaysOnTreatm(void){ return daysOnTreatm; }
int Person::getIsolation(void){ return isolation; }

//tb
int Person::getTypeOfTbInfection(void){ return typeOfTbInfection; }
int Person::getTbState(void){ return tbState; }
int Person::getTbSwap(void){ return tbSwap; }
int Person::getTbStateTotalDays(void){ return tbStateTotalDays; }
int Person::getDaysOnTbState(void){ return daysOnTbState; }
int Person::getActiveTbDays(void){ return activeTbDays; }
int Person::getActivation(void){ return activation; }
int Person::getTbExposures(void){ return tbExposures; }


//SETTERS
//covid
void Person::setAge( int newAge ){                           age = newAge; }
void Person::setAgeOfDeath( int newAgeOfDeath ){             ageOfDeath = newAgeOfDeath; }
void Person::setGender( int newGender ){                     gender = newGender; }
void Person::setState( int newState ){                       state = newState; }
void Person::setSwap( int newSwap ){                         swap = newSwap; }
void Person::setStateTotalDays( int newStateTotalDays ){     stateTotalDays = newStateTotalDays; }
void Person::setDaysOnState( int newDaysOnState ){           daysOnState = newDaysOnState; }
void Person::setTreatmTotalDays( int newTreatmTotalDays ){   treatmTotalDays = newTreatmTotalDays; }
void Person::setDaysOnTreatm( int newDaysOnTreatm ){         daysOnTreatm = newDaysOnTreatm; }
void Person::setIsolation( int newIsolation ){               isolation = newIsolation; }
//tb
void Person::setTypeOfTbInfection(int newTypeOfTbInfection){ typeOfTbInfection = newTypeOfTbInfection; }
void Person::setTbState(int newTbState){                     tbState = newTbState; }
void Person::setTbSwap(int newTbSwap){                       tbSwap = newTbSwap; }
void Person::setTbStateTotalDays(int newTbStateTotalDays){   tbStateTotalDays = newTbStateTotalDays; }
void Person::setDaysOnTbState(int newDaysOnTbState){         daysOnTbState = newDaysOnTbState; }
void Person::setActiveTbDays(int newActiveTbDays){           activeTbDays = newActiveTbDays; }
void Person::setActivation(int newActivation){               activation = newActivation; }
void Person::setTbExposures(int newTbExposures){             tbExposures = newTbExposures; }


//METHODS
void Person::printAtributes(){
            cout << "age: " << age << "\n" <<           
                    "ageOfDeath: " << ageOfDeath << "\n" <<
                    "gender: " << gender << "\n" <<   
                    "state: " << state << "\n" <<  
                    "swap: " << swap << "\n" <<     
                    "stateTotalDays: " << stateTotalDays << "\n" <<
                    "daysOnState: " << daysOnState << "\n" <<   
                    "treatmTotalDays: " << treatmTotalDays << "\n" <<
                    "daysOnTreatm: " << daysOnTreatm << "\n" <<
                    "isolation: " << isolation << endl;
            
}

void Person::printTbAtributes(){
            cout << "typeOfInfection: " << typeOfTbInfection << "\n" <<
                    "state: " << tbState << "\n" <<  
                    "swap: " << tbSwap << "\n" <<     
                    "stateTotalDays: " << tbStateTotalDays << "\n" <<
                    "daysOnState: " << daysOnTbState << "\n" <<   
                    "activeDays: " << activeTbDays << "\n" <<
                    "activation: " << activation << "\n" << 
                    "exposures: " << tbExposures << "\n" << endl;           
}

void Person::death(int causeOfDeath, int newAge, int newAgeOfDeath, int newGender, int newIsolation){

    //RESTART COVID STATE   
    switch ( state ){   
        case S:
            total_S--; //since total_S will be increased in the end of this function, it's necessary to decreased here first 
            break;
            
        case E:
            total_E--;
            break;

        case IP:
            total_IP--;
            break;

        case IA:
            total_IA--;
            break;

        case ISLight:
            total_ISLight--;
            break;

        case ISModerate:
            total_ISModerate--;
            break;

        case ISSevere:
            total_ISSevere--;
            break;

        case H:
            total_H--;
            availableBeds++;
                    
            break;

        case ICU:
            total_ICU--;
            availableBedsICU++;

            break;

        case Recovered:
            total_Recovered--;
            break;

        default:
            break;
    } // end of switch case
    //RESTART TB STATE
    switch ( tbState ){   
        case STB:
            total_TBS--; //since total_S will be increased in the end of this function, it's necessary to decreased here first 
            break;
            
        case LSTB:
            total_TBLS--;
            break;

        case LSTBEXOGENOUS:
            total_TBLSEXOGENOUS--;
            break;

        case TSTB:
            total_TBTS--;
            break;

        default:
            break;

    } // end of switch case


    if ( causeOfDeath == NATURALCAUSES){
        total_naturalDeath++;
    }
    else if ( causeOfDeath == COVID){
        dailyDeathsByCovid++;
        total_covidDeath++;
    }
    else if ( causeOfDeath == TB){
        dailyDeathsByTb++;
        total_tbDeath++;
    }
    else if ( causeOfDeath == COINFECTION){
        dailyDeathsByCoinfection++;
        total_coinfectionDeath++;
    }

    total_S++; //all dead in lattice will be replaced by an individual on S state
    total_TBS++;
        
    //reset object atributes
    setAge(newAge);
    setAgeOfDeath(newAgeOfDeath);
    setGender(newGender);
    setState(S);
    setSwap(S);
    setStateTotalDays(-1);
    setDaysOnState(0);
    setTreatmTotalDays(-1);
    setDaysOnTreatm(-1);
    setIsolation(newIsolation);

    setTypeOfTbInfection(firstActivationNone);
    setTbState(STB);
    setTbSwap(STB);
    setTbStateTotalDays(NA);
    setDaysOnTbState(0);
    setActiveTbDays(NA);
    setActivation(FIRST);
    setTbExposures(0);

}

//call: person[i][j]->changeState( nextState, sortTotalDaysOnState(minDays, maxDays) );
void Person::changeState(int newState, int newStateTotalDays){

    setSwap(newState);
    setDaysOnState(0); // Person[i][j].daysOnState = 0;    
    setStateTotalDays(newStateTotalDays);

    switch(newState){
        case S:
            total_S++;
            break;
        
        case E:
            total_E++;
            break;

        case IP:
            total_IP++;
            break;

        case IA:
            total_IA++;
            break;

        case ISLight:
            total_ISLight++;
            break;

        case ISModerate:
            total_ISModerate++;
            break;

        case ISSevere:
            total_ISSevere++;
            break;

        case H:
            total_H++;
            availableBeds--;
            break;

        case ICU:
            total_ICU++;
            availableBedsICU--;
            break;

        case Recovered:
            total_Recovered++;
            break;

        default:
           break;
       
    }//switch case end 
           
    switch(state){
        case S:
            total_S--;
            break;
        case E:
            total_E--;
            break;
        case IP:
            total_IP--;         
            break;
        case IA:
            total_IA--;
            break;
        case ISLight:
            total_ISLight--;
            break;
        case ISModerate:
            total_ISModerate--;
            break;
        case ISSevere:
            total_ISSevere--;
            break;
        case H:
            total_H--;
            availableBeds++;
            break;
        case ICU:
            total_ICU--;
            availableBedsICU++;
            break;
        case Recovered:
            total_Recovered--;                            
            break;
        default:
            break;

    }//switch case end 
}

void Person::changeTbState(int newTbState, int newTbStateTotalDays){

    setTbSwap(newTbState);
    setDaysOnTbState(0);
    setTbStateTotalDays(newTbStateTotalDays);


    switch(newTbState){
        case STB:
            total_TBS++;
            break;

        case LSTB:
            total_TBLS++;
            setTbExposures(getTbExposures()+1);
            break;

        case LSTBEXOGENOUS:
            total_TBLSEXOGENOUS++;
            setTbExposures(getTbExposures()+1);
            break;

        case TSTB:
            total_TBTS++;
            break;

        default:
           break;
       
    }//switch case end  
           
    switch(tbState){
        case STB:
            total_TBS--;
            break;

        case LSTB:
            total_TBLS--;
            break;

        case LSTBEXOGENOUS:
            total_TBLSEXOGENOUS--;
            break;

        case TSTB:
            total_TBTS--;
            break;

        default:
           break;
       
    }//switch case end 

}

void Person::update(){

    setAge(++age);

    setState(swap);
    setDaysOnState(++daysOnState);
    
    setTbState(tbSwap);
    setDaysOnTbState(++daysOnTbState);

}

void Person::manageAvailableBeds(int newAvailableBeds, int newAvailableBedsICU){
    
    availableBeds = availableBeds + newAvailableBeds;
    availableBedsICU = availableBedsICU + newAvailableBedsICU;

}
