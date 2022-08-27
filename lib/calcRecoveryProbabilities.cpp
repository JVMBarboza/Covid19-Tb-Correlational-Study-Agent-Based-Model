
double calcRecoveryProbISModerate(int i, int j){
    
    if( person[i][j]->getAge() <= 60*365 ){ //younger
        return ProbRecoveryYoungerISModerate;
    }
    else if( (person[i][j]->getAge() > 60*365) && (person[i][j]->getAge() <= 70*365 ) ){ //60-70
        return ProbRecovery_60_70_ISModerate;
    }
    else if( (person[i][j]->getAge() > 70*365) && (person[i][j]->getAge() <= 80*365) ){ //70-80
        return ProbRecovery_70_80_ISModerate;
    }
    else if( (person[i][j]->getAge() > 80*365) && (person[i][j]->getAge() <= 90*365) ){ //80-90
        return ProbRecovery_80_90_ISModerate;
    }
    else{
        //person[i][j]->getAge() > 90*365 ){ // >90
        return ProbRecoveryGreater90_ISModerate;
    }

}

double calcRecoveryProbISSevere(int i, int j){

    if( person[i][j]->getAge() <= 60*365 ){ //younger
        return ProbRecoveryYoungerISSevere;
    }
    else if( (person[i][j]->getAge() > 60*365) && (person[i][j]->getAge() <= 70*365 ) ){ //60-70
        return ProbRecovery_60_70_ISSevere;
    }
    else if( (person[i][j]->getAge() > 70*365) && (person[i][j]->getAge() <= 80*365) ){ //70-80
        return ProbRecovery_70_80_ISSevere;
    }
    else if( (person[i][j]->getAge() > 80*365) && (person[i][j]->getAge() <= 90*365) ){ //80-90
        return ProbRecovery_80_90_ISSevere;
    }
    else{
        //if( person[i][j]->getAge() > 90*365 ){ // >90
        return ProbRecoveryGreater90_ISSevere;
    }
}

double calcRecoveryProbH(int i, int j){

    if( person[i][j]->getAge() <= 20*365 ){ //younger
        return ProbRecoveryYoungerH;
    }
    else if( (person[i][j]->getAge() > 20*365) && (person[i][j]->getAge() <= 30*365 ) ){ //20-30
        return ProbRecovery_20_30_H;  
    }
    else if( (person[i][j]->getAge() > 30*365) && (person[i][j]->getAge() <= 40*365 ) ){ //30-40
        return ProbRecovery_30_40_H; 
    }
    else if( (person[i][j]->getAge() > 40*365) && (person[i][j]->getAge() <= 50*365 ) ){ //40-50
        return ProbRecovery_40_50_H;   
    }
    else if( (person[i][j]->getAge() > 50*365) && (person[i][j]->getAge() <= 60*365 ) ){ //50-60
        return ProbRecovery_50_60_H; 
    }
    else if( (person[i][j]->getAge() > 60*365) && (person[i][j]->getAge() <= 70*365 ) ){ //60-70
        return ProbRecovery_60_70_H;  
    }
    else if( (person[i][j]->getAge() > 70*365) && (person[i][j]->getAge() <= 80*365) ){ //70-80
        return ProbRecovery_70_80_H;  
    }
    else if( (person[i][j]->getAge() > 80*365) && (person[i][j]->getAge() <= 90*365) ){ //80-90
        return ProbRecovery_80_90_H;  
    }
    else{
        //if( person[i][j]->getAge() > 90*365 ){ // >90
        return ProbRecoveryGreater90_H; 
    }   

}

double calcRecoveryProbICU(int i, int j){
    
    if( person[i][j]->getAge() <= 60*365 ){ //younger
        return ProbRecoveryYoungerICU;
    }
    else if( (person[i][j]->getAge() > 60*365) && (person[i][j]->getAge() <= 70*365 ) ){ //60-70
        return ProbRecovery_60_70_ICU;
    }
    else if( (person[i][j]->getAge() > 70*365) && (person[i][j]->getAge() <= 80*365) ){ //70-80
        return ProbRecovery_70_80_ICU;
    }
    else if( (person[i][j]->getAge() > 80*365) && (person[i][j]->getAge() <= 90*365) ){ //80-90
        return ProbRecovery_80_90_ICU;
    }
    else{
        //if( person[i][j]->getAge() > 90*365 ){ // >90
        return ProbRecoveryGreater90_ICU;
    }

}
