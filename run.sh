#!/bin/bash
#############################################################################
# Script Name	: run.sh                                                                                             
# Description	: Start simulations based on chosen configurations                                                                                                                                                                          
# Author       	: João Victor M. Barboza                                                
# Email         : victorbarboza7657@gmail.com                                           
#############################################################################


############################# VARIABLES #####################################

simulationName="yourSimulationName"

numOfSimulations=50
numOfBetaFitSimulations=0

printSimulationOnScreen="TRUE"
printCountOnFile="TRUE"
printLatticeOnFileAtStart="FALSE"
printLatticeOnFileAtEnd="FALSE"

#AUTOMATIZATION COVID EPIDEMY ON OFF
#AUTOMATIZATION TB EPIDEMY ON OFF
#AUTOMATIZATION TO CHANGE POPULATION DENSITY LOW/HIGH
simulationBetaCalculated="TRUE"

beta=0.28
theoreticalRo=4.2

#R
ran=89329269
obtainedRO=0


############################# BETA FUNCTION ######################################

#if simulationBetaCalculated ==  False this step will calculate the optimized beta for your simulations 
if [ "$simulationBetaCalculated" = "FALSE" ]; then

    echo "############# FITTING BETA ################"

    while [ "$obtainedRO" -ne "$theoreticalRo" ];
    do
        for i in $(seq 1 "$numOfBetaFitSimulations");
        do
            root=$((ran+i)) #different R value for generate different pseudo random numbers 
            
            sed -i -e "s/\(R = \).*/\1$root/" lib/randomNumberGenerator.cpp
            sed -i -e "s/\(#define Beta \).*/\1$beta/" lib/define.h
            
            echo "##############  STEP $i/$numOfBetaFitSimulations   ###################" 
            
            make betaCalc
            
            ./betaCalc > output.txt      #./betaCalc prints the R number of infected by patient zero
            tail -1 output.txt >> RO.txt # we write R value into RO.txt file

            make clean
            
        done

        obtainedRO=$(python3 src/calculateRO.py) #obtainedRo = mean R value calculated from RO.txt
        echo "$obtainedRO"

        if [ "$obtainedRO" -gt "$theoreticalRo " ];
        then 
            beta=$( python3 src/betaDecrease.py $beta ); # decrease beta value
            echo "beta decreased"
        fi

        if [ "$obtainedRO" -lt "$theoreticalRo " ];
        then 
            beta=$( python3 src/betaIncrease.py $beta ); # increase beta value
            echo "beta increased"
        fi

        rm *.txt

    done

fi

echo "beta=$beta"


############################# MAIN SIMULATION FUNCTION ######################################

echo "####################### PERFORMING SIMULATIONS ####################################"

for i in $(seq 1 "$numOfSimulations");
do
    root=$((ran+i+1000)) #different R value for generate different pseudo random numbers 
    #cp src/*.py .  #copy codes and edit with different R value
    
    sed -i -e "s/\(R = \).*/\1$root/" lib/randomNumberGenerator.cpp
    if [ "$printSimulationOnScreen" = "TRUE" ]; then sed -i -e "s/\(#define PRINTONSCREEN \).*/\1"TRUE"/" lib/define.h; fi
    if [ "$printCountOnFile" = "TRUE" ]; then sed -i -e "s/\(#define PRINTCOUNTERSONFILE \).*/\1"TRUE"/" lib/define.h; fi
    if [ "$printLatticeOnFileAtStart" = "TRUE" ]; then sed -i -e "s/\(#define PRINTLATTICEONFILEATSTART \).*/\1"TRUE"/" lib/define.h; fi
    if [ "$printLatticeOnFileAtEnd" = "TRUE" ]; then sed -i -e "s/\(#define PRINTLATTICEONFILEATEND \).*/\1"TRUE"/" lib/define.h; fi

    echo "#######################################################"
    echo "###########  SIMULATION $i STARTED   ##################" 
    echo "#######################################################"
    
    make
    ./exec

    if [ -e output.csv ]; then  mv output.csv $simulationName-count$i.csv; fi
    if [ -e outputTB.csv ]; then  mv outputTB.csv $simulationName-TBcount$i.csv; fi

    if [ -e lattice.csv ]; then mv lattice.csv $simulationName-lattice$i.csv; fi

    make clean

    echo "#######################################################"
    echo "##########  SIMULATION $i PERFORMED  ##################" 
    echo "#######################################################"

done

############## MOVING DATA TO SIMULATION DIRECTORY ####################
mkdir $simulationName
mv *.csv $simulationName/
mv $simulationName/ results/

################## MANIPULATING DATA AND PLOT ########################
python3 src/fileManipulation.py
mv *.csv results/$simulationName/

#python3 src/plot.py
#mv *.png  results/$simulationName

########################### CLEANING #################################



echo "#######################################################"
echo "############### SIMULATION OUTPUT #####################" 
echo "#######################################################"

echo "fited beta=$beta"

#42