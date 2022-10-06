#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

#include "../lib/define.h"
#include "../lib/personTb.h"

//CONSTRUCTOR
//call: PersonTb[i][j] = new PersonTb(newTypeOfInfection, newState, newSwap, newStateTotalDays, newDaysOnState, newactiveDays, newDaysOnTreatm);
PersonTb::PersonTb(int i, int j, int newTypeOfInfection, int newState, int newSwap, int newStateTotalDays, int newDaysOnState, int newActiveDays, int newDaysOnTreatm, int newReinfection){
    
    settypeOfInfection(newTypeOfInfection);
    setState(newState);
    setSwap(newSwap);
    setStateTotalDays(newStateTotalDays);
    setDaysOnState(newDaysOnState);
    setActiveDays(newActiveDays);
    setDaysOnTreatm(newDaysOnTreatm);
    setReinfection(newReinfection);

    if( (i>=1 && i<=L) && (j>=1 && j<=L) ){
        total_S++;   //only count individuals on the real lattice
    }

}

//DESTRUCTOR
PersonTb::~PersonTb(void){}

//GETTERS
int PersonTb::gettypeOfInfection(void){ return typeOfInfection; }
int PersonTb::getState(void){ return state; }
int PersonTb::getSwap(void){ return swap; }
int PersonTb::getStateTotalDays(void){ return stateTotalDays; }
int PersonTb::getDaysOnState(void){ return daysOnState; }
int PersonTb::getActiveDays(void){ return activeDays; }
int PersonTb::getDaysOnTreatm(void){ return daysOnTreatm; }
int PersonTb::getReinfection(void){ return reinfection; }

//SETTERS
void PersonTb::settypeOfInfection( int newTypeOfInfection ){           typeOfInfection = newTypeOfInfection; }
void PersonTb::setState( int newState ){                     state = newState; }
void PersonTb::setSwap( int newSwap ){                       swap = newSwap; }
void PersonTb::setStateTotalDays( int newStateTotalDays ){   stateTotalDays = newStateTotalDays; }
void PersonTb::setDaysOnState( int newDaysOnState ){         daysOnState = newDaysOnState; }
void PersonTb::setActiveDays( int newActiveDays ){ activeDays = newActiveDays; }
void PersonTb::setDaysOnTreatm( int newDaysOnTreatm ){       daysOnTreatm = newDaysOnTreatm; }
void PersonTb::setReinfection( int newReinfection){          reinfection = newReinfection; }



//METHODS
void PersonTb::printAtributes(){
            cout << "typeOfInfection: " << typeOfInfection << "\n" <<
                    "state: " << state << "\n" <<  
                    "swap: " << swap << "\n" <<     
                    "stateTotalDays: " << stateTotalDays << "\n" <<
                    "daysOnState: " << daysOnState << "\n" <<   
                    "activeDays: " << activeDays << "\n" <<
                    "daysOnTreatm: " << daysOnTreatm << "\n" << 
                    "reinfection: " << "\n" << endl;
            
}

void PersonTb::death(int newTypeOfInfection){
        
    switch ( state ){   
        case STB:
            total_S--; //since total_S will be increased in the end of this function, it's necessary to decreased here first 
            break;
            
        case LSTB:
            total_LS--;
            break;

        case LSTBEXOGENOUS:
            total_LSEXOGENOUS--;
            break;

        case TSTB:
            total_TS--;
            break;

        default:
            break;

    } // end of switch case

    total_S++; //all dead in lattice will be replaced by an individual on S state
        
    //reset object atributes
    settypeOfInfection(newTypeOfInfection);
    setState(STB);
    setSwap(STB);
    setStateTotalDays(-1);
    setDaysOnState(0);
    setActiveDays(-1);
    setDaysOnTreatm(-1);
    setReinfection(0);

}

//call: PersonTb[i][j]->changeState( nextState, new stateTotalDays: sort(min,max) or NA, reinfection TRUE, FALSE or NA);
void PersonTb::changeState(int newState, int newStateTotalDays, int reinfectionTrueOrFalse){

    if(reinfection == FALSE){ //there hasn't occured any previous infection
        typeOfInfection = firstActivationNone;
    }

    setSwap(newState);
    setDaysOnState(0);
    setStateTotalDays(newStateTotalDays);
    setReinfection(TRUE); //since reinfection occured, we set this as TRUE for next infection

    switch(newState){
        case STB:
            total_S++;
            break;

        case LSTB:
            total_LS++;
            break;

        case LSTBEXOGENOUS:
            total_LSEXOGENOUS++;
            break;

        case TSTB:
            total_TS++;
            break;

        default:
           break;
       
    }//switch case end  
           
    switch(state){
        case STB:
            total_S--;
            break;

        case LSTB:
            total_LS--;
            break;

        case LSTBEXOGENOUS:
            total_LSEXOGENOUS--;
            break;

        case TSTB:
            total_TS--;
            break;

        default:
           break;
       
    }//switch case end 

    
}

void PersonTb::update(){

    setDaysOnState(++daysOnState);
    setState(swap);

}
