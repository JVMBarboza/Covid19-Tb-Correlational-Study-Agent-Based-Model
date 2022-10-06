#ifndef PERSON_H
#define PERSON_H

using namespace std;

class Person{
    private:
        int age;           
        int ageOfDeath;
        int gender;   
        int state;  
        int swap;     
        int stateTotalDays;
        int daysOnState;   
        int treatmTotalDays;
        int daysOnTreatm;
        int isolation;

        int typeOfTbInfection;
        int tbState;  
        int tbSwap;     
        int tbStateTotalDays;
        int daysOnTbState;   
        int activeTbDays;
        int activation;  
        int tbExposures; //if true and agent gets infective, it means that the same already had previous tb infection


    public:

        /*** CLASS ATRIBUTES ***/

        static int total_S;
        static int total_E;               
        static int total_IP;               
        static int total_IA;               
        static int total_ISLight;
        static int total_ISModerate;    
        static int total_ISSevere;                
        static int total_H;               
        static int total_ICU;            
        static int total_Recovered;       
        
        static int total_naturalDeath;  
        static int total_covidDeath;  
        static int total_tbDeath;
        static int total_coinfectionDeath;

        static int dailyDeathsByCovid;
        static int dailyDeathsByTb;
        static int dailyDeathsByCoinfection;

        static int availableBeds;
        static int availableBedsICU;

        static int total_TBS;
        static int total_TBLS;
        static int total_TBLSEXOGENOUS;
        static int total_TBTS;


        //CONSTRUCTOR
        Person(int,int, int,int,int,int,int,int,int,int,int,int, int,int,int,int,int,int,int,int);
        
        //DESTRUTOR
        ~Person(void);

        //GETTERS

        //covid
        int getAge(void);
        int getAgeOfDeath(void);
        int getGender(void);
        int getState(void);
        int getSwap(void);
        int getStateTotalDays(void);
        int getDaysOnState(void);
        int getTreatmTotalDays(void);
        int getDaysOnTreatm(void);
        int getIsolation(void);
        //tb
        int getTypeOfTbInfection(void);
        int getTbState(void);
        int getTbSwap(void);
        int getTbStateTotalDays(void);
        int getDaysOnTbState(void);
        int getActiveTbDays(void);
        int getActivation(void);
        int getTbExposures(void);


        //SETTERS
        
        //covid
        void setAge(int);
        void setAgeOfDeath(int);
        void setGender(int);
        void setState(int);
        void setSwap(int);
        void setStateTotalDays(int);
        void setDaysOnState(int);
        void setTreatmTotalDays(int);
        void setDaysOnTreatm(int);
        void setIsolation(int);
        //tb
        void setTypeOfTbInfection(int);
        void setTbState(int);
        void setTbSwap(int);
        void setTbStateTotalDays(int);
        void setDaysOnTbState(int);
        void setActiveTbDays(int);
        void setActivation(int);
        void setTbExposures(int);


        //METHODS
        void death(int, int, int, int, int);
        void changeState(int, int);
        void changeTbState(int, int);
        void update();
        
        void manageAvailableBeds(int , int);
        
        void printAtributes();
        void printTbAtributes();
        void printCount();

};
#endif