#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

#include "../lib/define.h"
#include "../lib/personTb.h"

//CONSTRUCTOR
//call: PersonTb[i][j] = new PersonTb(newAgeOfDeath, newState, newSwap, newStateTotalDays, newDaysOnState, newTreatmTotalDays, newDaysOnTreatm);
PersonTb::PersonTb(int i, int j, int newAgeOfDeath, int newState, int newSwap, int newStateTotalDays, int newDaysOnState, int newTreatmTotalDays, int newDaysOnTreatm){
    
    setAgeOfDeath(newAgeOfDeath);
    setState(newState);
    setSwap(newSwap);
    setStateTotalDays(newStateTotalDays);
    setDaysOnState(newDaysOnState);
    setTreatmTotalDays(newTreatmTotalDays);
    setDaysOnTreatm(newDaysOnTreatm);

    if( (i>=1 && i<=L) && (j>=1 && j<=L) ){
        total_S++;   //only count individuals on the real lattice
    }

}

//DESTRUCTOR
PersonTb::~PersonTb(void){}

//GETTERS
int PersonTb::getAgeOfDeath(void){ return ageOfDeath; }
int PersonTb::getState(void){ return state; }
int PersonTb::getSwap(void){ return swap; }
int PersonTb::getStateTotalDays(void){ return stateTotalDays; }
int PersonTb::getDaysOnState(void){ return daysOnState; }
int PersonTb::getTreatmTotalDays(void){ return treatmTotalDays; }
int PersonTb::getDaysOnTreatm(void){ return daysOnTreatm; }

//SETTERS
void PersonTb::setAgeOfDeath( int newAgeOfDeath ){           ageOfDeath = newAgeOfDeath; }
void PersonTb::setState( int newState ){                     state = newState; }
void PersonTb::setSwap( int newSwap ){                       swap = newSwap; }
void PersonTb::setStateTotalDays( int newStateTotalDays ){   stateTotalDays = newStateTotalDays; }
void PersonTb::setDaysOnState( int newDaysOnState ){         daysOnState = newDaysOnState; }
void PersonTb::setTreatmTotalDays( int newTreatmTotalDays ){ treatmTotalDays = newTreatmTotalDays; }
void PersonTb::setDaysOnTreatm( int newDaysOnTreatm ){       daysOnTreatm = newDaysOnTreatm; }

//METHODS

void PersonTb::printAtributes(){
            cout << "ageOfDeath: " << ageOfDeath << "\n" <<
                    "state: " << state << "\n" <<  
                    "swap: " << swap << "\n" <<     
                    "stateTotalDays: " << stateTotalDays << "\n" <<
                    "daysOnState: " << daysOnState << "\n" <<   
                    "treatmTotalDays: " << treatmTotalDays << "\n" <<
                    "daysOnTreatm: " << daysOnTreatm << "\n" << endl;
            
}

void PersonTb::death(int newAgeOfDeath){
        
    switch ( state ){   
        case STB:
            total_S--; //since total_S will be increased in the end of this function, it's necessary to decreased here first 
            break;
            
        case LSTB:
            total_LS--;
            break;

        case TSTB:
            total_TS--;
            break;

        default:
            break;

    } // end of switch case

    total_S++; //all dead in lattice will be replaced by an individual on S state
        
    //reset object atributes
    setAgeOfDeath(newAgeOfDeath);
    setState(S);
    setSwap(S);
    setStateTotalDays(-1);
    setDaysOnState(0);
    setTreatmTotalDays(-1);
    setDaysOnTreatm(-1);

}

//call: PersonTb[i][j]->changeState( nextState, sortTotalDaysOnState(minDays, maxDays) );
void PersonTb::changeState(int newState, int newStateTotalDays){

    setSwap(newState);
    setDaysOnState(0); // PersonTb[i][j].daysOnState = 0;    
    setStateTotalDays(newStateTotalDays);

    switch(newState){
        case STB:
            total_S++;
            break;

        case LSTB:
            total_LS++;
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
