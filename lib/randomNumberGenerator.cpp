/*##################################################################################*/
/*####################### Pseudo Random Gen Functions ##############################*/
/*##################################################################################*/

#define max 4294967295.0 
unsigned s = 88912123;
unsigned 
R = 89330271
;

//Sort number between 0 and 1
//call: rn = sortRandomNumber(&R);
double sortRandomNumber(unsigned *R){
    *R=*R*s;
    return (*R/max);
}

//Sort int number between minNum and maxNum-1
//call: SortRandomNumberInteger(minNum, maxNum)
int sortRandomNumberInteger(int minNum, int maxNum){

    return ( sortRandomNumber(&R)*(maxNum-minNum)+minNum );
}

//Sort double number between minNum and maxNum-(≅0.00001)
//call: SortRandomNumberDouble(minNum, maxNum)
double sortRandomNumberDouble(double minNum, double maxNum){

    return ( sortRandomNumber(&R)*(maxNum-minNum)+minNum );
}