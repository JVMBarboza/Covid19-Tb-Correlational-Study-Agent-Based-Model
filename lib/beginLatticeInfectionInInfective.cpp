//SAME FUNCTION BUT FOR THE CASE OF JUST ONE INFECTIVE CASE, USUALLY USED IN THE BETA FIT CALCULATIONS.
void beginLatticeInfectionInInfective(){

    double rn, tmp=0.0;

    int key=0;
    double totalPop = L*L; //the "#define N = L*L" returns an int value which drops our accuracy      

    cout << "beginning lattice infection...";

    xSorted = sortRandomNumberInteger(1,L+1);
    ySorted = sortRandomNumberInteger(1,L+1);

    person[xSorted][ySorted]->changeState( IP, sortTotalDaysOnState(minIP, maxIP) );

    cout << "DONE" << endl;

}