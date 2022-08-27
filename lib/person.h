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
        //static int total_tbDeath;     
        static int dailyDeathsByCovid;

        static int availableBeds;
        static int availableBedsICU;


        //CONSTRUCTOR
        Person(int, int, int,int,int,int,int,int,int,int,int,int);
        
        //DESTRUTOR
        ~Person(void);

        //GETTERS
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

        //SETTERS
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

        //METHODS
        void death(int, int, int, int, int);
        void changeState(int, int);
        void update();
        
        void manageAvailableBeds(int , int);
        
        void printAtributes();
        void printCount();

};
#endif