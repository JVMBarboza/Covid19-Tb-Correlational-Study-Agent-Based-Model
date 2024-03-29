//SAME FUNCTION BUT FOR THE CASE OF JUST ONE INFECTIVE CASE, USUALLY USED IN THE BETA FIT CALCULATIONS.
int veryfiesInfectionByInfective(int i , int j){

  	int k,l,m,n;         
  	int RandomContacts;
  	int Randomi;
  	int Randomj;
  	int mute;
	int Contagion = 0;

  	int KI = 0; // counter for infected individuals in the neighborhood: 
	  			// KI = Random contacts + infectives near  */


  	double ProbContagion;         
	
	if( person[i][j]->getIsolation() == IsolationNo) // isolation only for random contacts
	{
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
		
				if(Randomi == xSorted && Randomj == ySorted)
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
				if( (i+k) == xSorted && (j+l) == ySorted )
				    KI++;
	}			
	#else
	{				
	/* Check 4 neighbors in the lattice */    
			if( (i-1) == xSorted && j == ySorted )
				KI++;
			else if( (i+1) == xSorted && j == ySorted )
				KI++;
			else if( i == xSorted && (j-1) == ySorted )
				KI++;
			else if( i == xSorted && (j+1) == ySorted )
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