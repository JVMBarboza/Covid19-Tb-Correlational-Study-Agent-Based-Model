void checkTbActivation(int i, int j){

    int type, mute;

    double rn;

    if( person[i][j]->getActivation() == FIRST ){ // first infection
        
        rn = sortRandomNumber(&R);

        if(rn <= maxActivation){ //10% will develop activate cases
            person[i][j]->setTypeOfTbInfection( firstActivationSactive );
            person[i][j]->setActiveTbDays( sortRandomNumber(&R)*( person[i][j]->getAgeOfDeath() - person[i][j]->getAge() - fastProgression - 1) + person[i][j]->getAge() + fastProgression );
        }
        else{ //won't develop activate cases
            person[i][j]->setTypeOfTbInfection(firstActivationNone);
            person[i][j]->setActiveTbDays(NA);
        }

    }
    else if( person[i][j]->getActivation() == SECOND ){ // second infection
        
        if( person[i][j]->getTypeOfTbInfection()==firstActivationNone ){ //no activation in first infection
            
            rn = sortRandomNumber(&R);

            if(rn <= maxActivation){ //10% will develop activate cases
                person[i][j]->setTypeOfTbInfection(secondActivationSactive);
                person[i][j]->setActiveTbDays( sortRandomNumber(&R)*( person[i][j]->getAgeOfDeath() - person[i][j]->getAge() - fastProgression - 1) + person[i][j]->getAge() + fastProgression );
            }
            else{ //won't develop activate cases
                person[i][j]->setTypeOfTbInfection(secondActivationNone);
            }
        }
        else if( person[i][j]->getTypeOfTbInfection()==firstActivationSactive ){
            
            person[i][j]->setTypeOfTbInfection(secondActivationSactive);
            person[i][j]->setActiveTbDays( sortRandomNumber(&R)*( person[i][j]->getAgeOfDeath() - person[i][j]->getAge() - fastProgression - 1) + person[i][j]->getAge() + fastProgressionIncreased );

        }
        else{
            //do nothing, already calculated, just for error handling i wrote this
        }

    }

}

void newExposure(int i, int j){

    if( (person[i][j]->getTbExposures()<=2) && (person[i][j]->getActivation()==SECOND) )
        contagion = veryfiesTbInfectionByNeighbors(i,j);
    else
        contagion = 0;

    if( (contagion==1) && (person[i][j]->getTbExposures()<=2) ){
		
        checkTbActivation(i,j);

        if( person[i][j]->getTbState() == LSTB ){
            person[i][j]->changeTbState(LSTBEXOGENOUS, NA);
        }
        else if( person[i][j]->getTbState() == LSTBEXOGENOUS ){   
            person[i][j]->setTbSwap(LSTBEXOGENOUS);          
        }
        
    }
    else{
        if( person[i][j]->getTbState() == LSTB )
            person[i][j]->setTbSwap( LSTB );
        else if( person[i][j]->getTbState() == LSTBEXOGENOUS )
            person[i][j]->setTbSwap( LSTBEXOGENOUS );
    }

    contagion = 0;

}
