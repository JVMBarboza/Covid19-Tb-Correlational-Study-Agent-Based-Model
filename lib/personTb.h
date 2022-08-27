#ifndef PERSONTB_H
#define PERSONTB_H

using namespace std;

class PersonTb{
    private:
        int ageOfDeath;
        int state;  
        int swap;     
        int stateTotalDays;
        int daysOnState;   
        int treatmTotalDays;
        int daysOnTreatm;


    public:

        /*** CLASS ATRIBUTES ***/
        static int total_S;
        static int total_LS;
        static int total_TS;

        //CONSTRUCTOR
        PersonTb(int, int, int, int, int, int, int, int, int);
        
        //DESTRUTOR
        ~PersonTb(void);

        //GETTERS
        int getAgeOfDeath(void);
        int getState(void);
        int getSwap(void);
        int getStateTotalDays(void);
        int getDaysOnState(void);
        int getTreatmTotalDays(void);
        int getDaysOnTreatm(void);

        //SETTERS
        void setAgeOfDeath(int);
        void setState(int);
        void setSwap(int);
        void setStateTotalDays(int);
        void setDaysOnState(int);
        void setTreatmTotalDays(int);
        void setDaysOnTreatm(int);

        //METHODS
        void death(int, int);
        void changeState(int, int);
        void update();
        
        void printAtributes();
        void printCount();

};
#endif