#ifndef PERSONTB_H
#define PERSONTB_H

using namespace std;

class PersonTb{
    private:
        int typeOfInfection;
        int state;  
        int swap;     
        int stateTotalDays;
        int daysOnState;   
        int activeDays;
        int daysOnTreatm; // since treatm total days atribute was obsulete, daysOnTreatm will start as maximum and daily descrease until reaches zero 
        int reinfection; //if true and agent gets infective, it means that the same already had previous tb infection


    public:

        /*** CLASS ATRIBUTES ***/
        static int total_S;
        static int total_LS;
        static int total_LSEXOGENOUS;
        static int total_TS;

        //CONSTRUCTOR
        PersonTb(int, int, int, int, int, int, int, int, int, int);
        
        //DESTRUTOR
        ~PersonTb(void);

        //GETTERS
        int gettypeOfInfection(void);
        int getState(void);
        int getSwap(void);
        int getStateTotalDays(void);
        int getDaysOnState(void);
        int getActiveDays(void);
        int getDaysOnTreatm(void);
        int getReinfection(void);

        //SETTERS
        void settypeOfInfection(int);
        void setState(int);
        void setSwap(int);
        void setStateTotalDays(int);
        void setDaysOnState(int);
        void setActiveDays(int);    
        void setDaysOnTreatm(int);
        void setReinfection(int);

        //METHODS
        void death(int);
        void changeState(int, int, int);
        void update();
        
        void printAtributes();
        void printCount();

};
#endif