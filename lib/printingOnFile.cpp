void printCountOnFile(int printHeader){
    
    if(printHeader==TRUE){
        of << "S,E,IP,IA,ISLight,ISModerate,ISSevere,H,ICU,Recovered,Deaths by Covid,Natural Deaths,Daily Deaths,Available Hospital Beds,Available ICU Beds" << endl;
    }

    of << Person::total_S << "," 
       << Person::total_E << ","
       << Person::total_IP << ","
       << Person::total_IA << ","
       << Person::total_ISLight  << ","
       << Person::total_ISModerate << ","
       << Person::total_ISSevere << ","
       << Person::total_H << ","
       << Person::total_ICU << ","
       << Person::total_Recovered  << ","
       << Person::total_covidDeath << ","
       << Person::total_naturalDeath << ","
       << Person::dailyDeathsByCovid << ","
       << Person::availableBeds << ","
       << Person::availableBedsICU << endl;
    
}

void printTbCountOnFile(int printHeader){
    
    if(printHeader==TRUE){
        ofTB << "S,LS,LSEXOGENOUS,TS,Tb Daily Deaths,Coinfection Daily Deaths" << endl;
    }

    ofTB << Person::total_TBS << ","
       << Person::total_TBLS << ","
       << Person::total_TBLSEXOGENOUS << ","
       << Person::total_TBTS << ","
       << Person::dailyDeathsByTb << ","
       << Person::dailyDeathsByCoinfection << endl;
    
}

void printLatticeOnFile(){

    lf << "x-coord,y-coord,State\n" << endl;

    for(int x = 1; x<=L; x++){
        for(int y = 1; y<=L; y++){
            lf << x << "," 
               << y << "," 
               << person[x][y]->getState() << endl;
        }
    }

    cout << "Covid Lattice recorded!" << endl;
    
}

void printTbLatticeOnFile(){

    lfTB << "x-coord,y-coord,State\n" << endl;

    for(int x = 1; x<=L; x++){
        for(int y = 1; y<=L; y++){
            lfTB << x << "," 
               << y << "," 
               << person[x][y]->getTbState() << endl;
        }
    }

    cout << "TB Lattice recorded!" << endl;
    
}