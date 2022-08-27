/*##################################################################################*/
/*##########################  Sort Intervals Functions   ###########################*/
/*##################################################################################*/

int ageAux = 0; //global auxiliar variable

//returns random age in years based on the country distribution 
int sortPersonAge(){

    double rn = sortRandomNumber(&R);
    int  i=0, key=0, ans;


	do{
		if( rn <= SumProbBirthAge[i] ){
			key = 1;
			ans = sortRandomNumberInteger(AgeMin[i], AgeMax[i]+1); 
		}
        else{
            key = 0;
        }
		i++;
	}while( key < 1 );



    if(ans >= 80){
        ans = sortRandomNumberInteger(0,80);
    }

    ageAux = ans*365 + sortRandomNumberInteger(0,365); //bringing this variable into global make a possible access to the last sorted age and we wont need to pass the struct value to its own function in calcDeath just the last stored value in the variable 

	return ageAux; //returns the sorted years in days + random amount of days 0-365

}

//Gotta access age of individual so the algorithm can calculate
//age of death greater than current age of individual
int sortPersonAgeOfDeath(){

    double rn;
    int sortedAgeOfDeath, sortedAgeOfDeathInDays, key = 0;
		
    if(ageAux >= 79*365){
        sortedAgeOfDeathInDays = ageAux+sortRandomNumberInteger(1,366); 
    }
    else{
        do{
       
        rn = sortRandomNumber(&R);
        
		sortedAgeOfDeath = sortRandomNumberInteger(0,80); // sort age 0-79
		sortedAgeOfDeathInDays = sortedAgeOfDeath*365 + sortRandomNumberInteger(0,366); //convert years in days
        

        if( (ageAux < sortedAgeOfDeathInDays) && (rn < ProbNaturalDeath[sortedAgeOfDeath]) ){
            key = 1; // accept
        }
        else{
            key = 0; // reject
        }

	    }while(key==0);
    }
    
	
    return sortedAgeOfDeathInDays;

}

int sortPersonGender(){

    double rn = sortRandomNumber(&R);

    if(rn < proportionOfWomen)
        return FEMALE;
    else
        return MALE;

}

int sortPopPorcentageInIsolation(){
    double rn = sortRandomNumber(&R);

    if(rn < proportionIsolated)
        return IsolationYes; //Isolated
    else
        return IsolationNo; //Not in isolation

}

//call: sortTotalDaysOnNewState(minDays, maxDays);
int sortTotalDaysOnState(int minDays, int maxDays){
    return sortRandomNumberInteger(minDays,maxDays+1);
}
