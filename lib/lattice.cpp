
//copy data TO Person[x1][y1] FROM Person[x2][y2] 
//parameters: x1,y1 from local followed by x2,y2 from source
//call: copyData(x1,y1,x2,y2)
void copyData(int xone, int yone, int xtwo, int ytwo){

    person[xone][yone]->setAge( person[xtwo][ytwo]->getAge() );          
    person[xone][yone]->setAgeOfDeath( person[xtwo][ytwo]->getAgeOfDeath() );
    person[xone][yone]->setGender( person[xtwo][ytwo]->getGender() );   
    person[xone][yone]->setState( person[xtwo][ytwo]->getState() ); 
    person[xone][yone]->setSwap( person[xtwo][ytwo]->getSwap() );     
    person[xone][yone]->setStateTotalDays( person[xtwo][ytwo]->getStateTotalDays() ); 
    person[xone][yone]->setDaysOnState( person[xtwo][ytwo]->getDaysOnState() );       
    person[xone][yone]->setTreatmTotalDays( person[xtwo][ytwo]->getTreatmTotalDays() );
    person[xone][yone]->setDaysOnTreatm( person[xtwo][ytwo]->getDaysOnTreatm() );
    person[xone][yone]->setIsolation( person[xtwo][ytwo]->getIsolation() );

}

//update auxiliar lattice (copy data from real lattice)
void updateAuxiliarLattice(){

    //lattice edges
    copyData(0,0,L,L);
    copyData(L+1,0,1,L);
    copyData(0,L+1,L,1);
    copyData(L+1,L+1,1,1);

    //finally the rows and columns 
    for(int i = 1; i <= L; i++){
        //copy upper auxiliar from bottom real
        copyData(i,0,i,L);

        //copy bottom auxiliar from upper real
        copyData(i,L+1,i,1);
        
        //copy right auxiliar from left real
        copyData(L+1,i,1,i);

        //copy left auxiliar from right real
        copyData(0,i,L,i);

    }

}

void updateLattice(){
    
    //update real lattice
    for(int i = 1; i <= L; i++){
        for(int j = 1; j <= L; j++){

            person[i][j]->update();
                       
        }
    }

    updateAuxiliarLattice();

}

void beginLattice(int tmpAvailableBeds, int tmpAvailableBedsICU){
    

    cout << "beginning lattice..."; //START ENTIRE LATTICE WITH ZEROS

    for(int i = 0; i <= L+1; i++){
        for(int j = 0; j <= L+1; j++){

            person[i][j] = new Person( i, j, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);

        }
    }

    person[1][1]->manageAvailableBeds(tmpAvailableBeds, tmpAvailableBedsICU);

    cout << "DONE" << endl;


    cout << "calculating real lattice values...";

    for(int i = 1; i <= L; i++){
        for(int j = 1; j <= L; j++){
            
            person[i][j]->setAge( sortPersonAge() );
            person[i][j]->setAgeOfDeath( sortPersonAgeOfDeath() );
            person[i][j]->setGender( sortPersonGender() );
            person[i][j]->setState( S );
            person[i][j]->setSwap( S );
            person[i][j]->setStateTotalDays( -1 );
            person[i][j]->setDaysOnState( 0 );
            person[i][j]->setTreatmTotalDays( -1 );
            person[i][j]->setDaysOnTreatm( -1 );
            person[i][j]->setIsolation( sortPopPorcentageInIsolation() );

        }
    }

    cout << "DONE" << endl;


    cout << "updating auxiliar lattice..."; //UPDATE AUXILIAR LATTICE WITH VALUES CALCULATED IN THE PREVIOUS FOR LOOP
    
    updateAuxiliarLattice();
    
    cout << "DONE" << endl;


}

void beginLatticeInfection(){

    double rn, tmp=0.0;

    int key=0;
    double totalPop = L*L; //the "#define N = L*L" returns an int value which drops our accuracy      

    cout << "beginning lattice infection...";

    for(int i = 1; i <= L; i++){
        for(int j = 1; j <= L; j++){

            if( Eini != 0 ){

                tmp  = Eini/totalPop;
                rn = sortRandomNumber(&R);
                
                if( rn < tmp ){
                    person[i][j]->changeState(E, sortTotalDaysOnState(minLatency, maxLatency) ); // changePersonState(i,j,S,E);
                    key=1;
                }
            }
            
            if( (key==0) && (IPini != 0) ){ //if key == 0 -> person[i][j] still in S state
                
                tmp = IPini/totalPop;    
                rn = sortRandomNumber(&R);
                
                if( rn<tmp ){
                    person[i][j]->changeState(IP, sortTotalDaysOnState(minIP, maxIP) ); //changePersonState(i,j,S,IP);
                    key=1;
                }
            }

            if( (key==0) && (IAini != 0) ){ //if key == 0 -> person[i][j] still in S state
                
                tmp = IAini/totalPop;       
                rn = sortRandomNumber(&R);
                
                if( rn<tmp ){
                    person[i][j]->changeState( IA, sortTotalDaysOnState(minIA, maxIA) ); //changePersonState(i,j,S,IA);
                    key=1;
                }
            }

            if( (key==0) && (ISLightini != 0) ){ //if key == 0 -> person[i][j] still in S state
                
                tmp = ISLightini/totalPop;  
                rn = sortRandomNumber(&R);
                
                if( rn<tmp ){
                    person[i][j]->changeState( ISLight, sortTotalDaysOnState(minISLight, maxISLight) ); //changePersonState(i,j,S,ISLight);
                    key=1;
                }
            }

            if( (key==0) && (ISModerateini != 0) ){ //if key == 0 -> person[i][j] still in S state
                
                tmp = ISModerateini/totalPop;
                rn = sortRandomNumber(&R);

                if( rn<tmp ){
                    person[i][j]->changeState( ISModerate, sortTotalDaysOnState(minISModerate, maxISModerate) ); //changePersonState(i,j,S,ISModerate);
                    key=1;
                }
            }

            if( (key==0) && (ISSevereini != 0) ){ //if key == 0 -> person[i][j] still in S state
                
                tmp = ISSevereini/totalPop; 
                rn = sortRandomNumber(&R);
                
                if( rn<tmp ){
                    person[i][j]->changeState( ISSevere, sortTotalDaysOnState(minISSevere, maxISSevere) );//changePersonState(i,j,S,ISSevere);
                    key=1;
                }
            }

            if( (key==0) && (Hini != 0) ){ //if key == 0 -> person[i][j] still in S state
                
                tmp = Hini/totalPop;                 
                rn = sortRandomNumber(&R);

                if( rn<tmp ){
                    person[i][j]->changeState( H, sortTotalDaysOnState(minH, maxH) );//changePersonState(i,j,S,H);
                    key=1;
                }
            }

            if( (key==0) && (ICUini != 0) ){ //if key == 0 -> person[i][j] still in S state
                
                tmp = ICUini/totalPop;

                rn = sortRandomNumber(&R);
                
                if( rn<tmp ){
                    person[i][j]->changeState( ICU, sortTotalDaysOnState(minICU, maxICU) );//changePersonState(i,j,S,ICU);
                    key=1;
                }
            }

            key = 0; //set for the next person

        }
    }

    cout << "DONE" << endl;

}