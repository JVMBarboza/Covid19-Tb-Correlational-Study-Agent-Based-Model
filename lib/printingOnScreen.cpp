/*##################################################################################*/
/*##########################       Output Functions      ###########################*/
/*##################################################################################*/

void printOnScreen(int time){

    if(PRINTONSCREEN==TRUE){
        if(time==0)
            cout << "\n#################################### Simulation Dynamics Began #####################################################################################\n" << endl;


        cout << "Time:" << time 
            << " S:" << Person::total_S 
            << " E:" << Person::total_E
            << " IP:" << Person::total_IP
            << " IA:" << Person::total_IA
            << " ISL:" << Person::total_ISLight 
            << " ISM:" << Person::total_ISModerate
            << " ISS:" << Person::total_ISSevere
            << " H:" << Person::total_H
            << " ICU:" << Person::total_ICU
            << " Recovered:" << Person::total_Recovered 
            << " Available Bed:" << Person::availableBeds
            << " Available ICU Beds:" << Person::availableBedsICU
            << " Natural Deaths:" << Person::total_naturalDeath
            << " Covid Deaths:" << Person::total_covidDeath
            << " Daily Deaths:" << Person::dailyDeathsByCovid << endl;
    }
    
   
}

void printTbOnScreen(int time){

    if(PRINTONSCREEN==TRUE){
        if(time==0)
            cout << "\n#################################### Simulation Dynamics Began #####################################################################################\n" << endl;


        cout << "Time:" << time 
            << " S:" << PersonTb::total_S 
            << " LS:" << PersonTb::total_LS
            << " TS:" << PersonTb::total_TS << endl;
    }
    
   
}

void printSettings(){

    if(PRINTONSCREEN==TRUE){

        const time_t timer = time(NULL);

        cout << "\nSimulation perfomed at:" <<  ctime(&timer) << endl;
        
        cout << "############ Simulation Settings ############" << endl;

        cout << "LATTICE\nL = " << L << "\nN = " << L*L << "\nBeta = " << Beta << endl;
        
        cout << "PROBABILITIES:" << endl;

        cout << "ProbIPtoIA:" << ProbIPtoIA << endl;

        cout << "ProbToBecomeISLight:" << ProbToBecomeISLight << endl;
        cout << "ProbToBecomeISModerate:" << ProbToBecomeISModerate << endl;
        cout << "ProbToBecomeISSevere:" << ProbToBecomeISSevere << endl;

        cout << "ProbISLightToISModerate:" << ProbISLightToISModerate << endl;  /// NEW CHECK CHECK
        cout << "ProbHtoICU:" << ProbHtoICU << endl;

        // Probs of Recovery < 60
        cout << "ProbRecoveryYoungerISModerate:" << ProbRecoveryYoungerISModerate << endl;
        cout << "ProbRecoveryYoungerISSevere:" << ProbRecoveryYoungerISSevere << endl; // out of hospital
        cout << "ProbRecoveryYoungerH:" << ProbRecoveryYoungerH << endl;   ///NEW NEW < 20
        cout << "ProbRecoveryYoungerICU:" << ProbRecoveryYoungerICU << endl;

        // Probs Recovery IS Moderate for Elerdely 
        cout << "ProbRecovery_60_70_ISModerate:" << ProbRecovery_60_70_ISModerate << endl;
        cout << "ProbRecovery_70_80_ISModerate:" << ProbRecovery_70_80_ISModerate << endl;
        cout << "ProbRecovery_80_90_ISModerate:" << ProbRecovery_80_90_ISModerate << endl;
        cout << "ProbRecoveryGreater90_ISModerate:" << ProbRecoveryGreater90_ISModerate << endl;

        // Probs Recovery IS Severe for Elerdely 
        cout << "ProbRecovery_60_70_ISSevere:" << ProbRecovery_60_70_ISSevere << endl;
        cout << "ProbRecovery_70_80_ISSevere:" << ProbRecovery_70_80_ISSevere << endl;
        cout << "ProbRecovery_80_90_ISSevere:" << ProbRecovery_80_90_ISSevere << endl;
        cout << "ProbRecoveryGreater90_ISSevere:" << ProbRecoveryGreater90_ISSevere << endl;

        // Probs Recovery H for age > 20 
        cout << "ProbRecovery_20_30_H:" << ProbRecovery_20_30_H << endl;
        cout << "ProbRecovery_30_40_H:" << ProbRecovery_30_40_H << endl;
        cout << "ProbRecovery_40_50_H:" << ProbRecovery_40_50_H << endl;
        cout << "ProbRecovery_50_60_H:" << ProbRecovery_50_60_H << endl;
        cout << "ProbRecovery_60_70_H:" << ProbRecovery_60_70_H << endl;
        cout << "ProbRecovery_70_80_H:" << ProbRecovery_70_80_H << endl;
        cout << "ProbRecovery_80_90_H:" << ProbRecovery_80_90_H << endl;
        cout << "ProbRecoveryGreater90_H:" << ProbRecoveryGreater90_H << endl;


        // Probs Recovery ICU for Elerdely 
        cout << "ProbRecovery_60_70_ICU:" << ProbRecovery_60_70_ICU << endl;
        cout << "ProbRecovery_70_80_ICU:" << ProbRecovery_70_80_ICU << endl;
        cout << "ProbRecovery_80_90_ICU:" << ProbRecovery_80_90_ICU << endl;
        cout << "ProbRecoveryGreater90_ICU:" << ProbRecoveryGreater90_ICU << endl;

        cout << endl;
    }
    
}