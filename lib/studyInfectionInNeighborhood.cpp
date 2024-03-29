int veryfiesCovidInfectionByNeighbors(int i , int j){

  	int k,l,m,n, RandomContacts, Randomi, Randomj, mute, Contagion = 0;
  	int KI = 0; // counter for infected individuals in the neighborhood: 
	  			// KI = Random contacts + infectives near  */

  	double ProbContagion;         
	
	//Random contacts for non isolated individuals
	if( person[i][j]->getIsolation() == IsolationNo){

		RandomContacts = sortRandomNumberInteger(minRandomContacts, maxRandomContacts+1); 	
	
		mute = 0; /* Check random contacts */

		if(RandomContacts > 0){
			do{
				do{
					Randomi = sortRandomNumber(&R)*L + 1; //sort random i coordinate
				}while(Randomi==i);	

				do{
					Randomj = sortRandomNumber(&R)*L + 1; //sort random j coordinate
				}while(Randomj==j);
		
				if(person[Randomi][Randomj]->getState()==IP || person[Randomi][Randomj]->getState()==ISLight || person[Randomi][Randomj]->getState()==ISModerate || person[Randomi][Randomj]->getState()==ISSevere || person[Randomi][Randomj]->getState()==IA || person[Randomi][Randomj]->getState()==H || person[Randomi][Randomj]->getState()==ICU)
					KI++; 

				mute++;	
			}while(mute < RandomContacts);
		}
	} 
	
	
	#if(Density==HIGH)  // high demographic density
	{	 
		/* Check 8 neighbors in the lattice */    
		for(k=-1;k<=1;k++) 	
			for(l=-1;l<=1;l++)
				if(person[i+k][j+l]->getState()==IP || person[i+k][j+l]->getState()==ISLight || person[i+k][j+l]->getState()==ISModerate || person[i+k][j+l]->getState()==ISSevere  ||
				 person[i+k][j+l]->getState()==IA || person[i+k][j+l]->getState()==H || person[i+k][j+l]->getState()==ICU)
				KI++;
	}			
	#else
	{				
	/* Check 4 neighbors in the lattice */    
			if(person[i-1][j]->getState()==IP || person[i-1][j]->getState()==ISLight || person[i-1][j]->getState()==ISModerate || person[i-1][j]->getState()==ISSevere  || person[i-1][j]->getState()==IA || person[i-1][j]->getState()==H || person[i-1][j]->getState()==ICU)
				KI++;
			else if(person[i+1][j]->getState()==IP || person[i+1][j]->getState()==ISLight || person[i+1][j]->getState()==ISModerate || person[i+1][j]->getState()==ISSevere  || person[i+1][j]->getState()==IA || person[i+1][j]->getState()==H || person[i+1][j]->getState()==ICU)
				KI++;
			else if(person[i][j-1]->getState()==IP || person[i][j-1]->getState()==ISLight || person[i][j-1]->getState()==ISModerate || person[i][j-1]->getState()==ISSevere  || person[i][j-1]->getState()==IA  || person[i][j-1]->getState()==H  || person[i][j-1]->getState()==ICU)
				KI++;
			else if(person[i][j+1]->getState()==IP || person[i][j+1]->getState()==ISLight || person[i][j+1]->getState()==ISModerate || person[i][j+1]->getState()==ISSevere  || person[i][j+1]->getState()==IA || person[i][j+1]->getState()==H || person[i][j+1]->getState()==ICU)
				KI++;
	}			
	#endif
	
	if(KI > 0) // Calculate ProbContagion
		ProbContagion = 1.0 - pow(1.0 - Beta,(double)KI);
	else
		ProbContagion = 0.0;	

	if(KI==0)
		Contagion = 0; // No contagion
	else
	{
		if( sortRandomNumber(&R) <= ProbContagion )
			Contagion = 1;
		else
			Contagion = 0;
	}	

	return Contagion; //if 1 -> change state from S to E in (i,j) coordinates
}

int veryfiesTbInfectionByNeighbors(int i , int j){

  	int k,l,m,n, RandomContacts, Randomi, Randomj, mute, Contagion = 0;
  	int KI = 0; // counter for infected individuals in the neighborhood: 
	  			// KI = Random contacts + infectives near  */

  	double ProbContagion;         
	
	//Random contacts for non isolated individuals
	if( person[i][j]->getIsolation()==IsolationNo ){
		
		RandomContacts = sortRandomNumberInteger(minRandomContacts, maxRandomContacts+1); 	
	
		mute = 0; /* Check random contacts */

		if(RandomContacts > 0){
			do{
				do{
					Randomi = sortRandomNumber(&R)*L + 1; //sort random i coordinate
				}while(Randomi==i);	

				do{
					Randomj = sortRandomNumber(&R)*L + 1; //sort random j coordinate
				}while(Randomj==j);
		
				if( person[Randomi][Randomj]->getTbState()==TSTB )
					KI++; 

				mute++;	
			}while(mute < RandomContacts);
		}
	} 
	
	
	#if(Density==HIGH)  // high demographic density
	{	 
		/* Check 8 neighbors in the lattice */    
		for(k=-1;k<=1;k++) 	
			for(l=-1;l<=1;l++)
				if( person[i+k][j+l]->getTbState()==TSTB )
					KI++;
	}			
	#else
	{				
	/* Check 4 neighbors in the lattice */    
		if( person[i-1][j]->getTbState()==TSTB )
			KI++;
		else if(person[i+1][j]->getTbState()==TSTB )
			KI++;
		else if(person[i][j-1]->getTbState()==TSTB )
			KI++;
		else if(person[i][j+1]->getTbState()==TSTB )
			KI++;
	}			
	#endif
	
	if(KI > 0) // Calculate ProbContagion
		ProbContagion = 1.0 - pow(1.0 - BetaTB,(double)KI);
	else
		ProbContagion = 0.0;	

	if(KI==0)
		Contagion = 0; // No contagion
	else
	{
		if( sortRandomNumber(&R) <= ProbContagion )
			Contagion = 1;
		else
			Contagion = 0;
	}	

	return Contagion; //if 1 -> change state from TBS TO TBLS in (i,j) coordinates
}
