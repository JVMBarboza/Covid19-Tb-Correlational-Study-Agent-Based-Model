/*##################################################################################*/
/*##########################    SIMULATION CONSTANTS   #############################*/
/*##################################################################################*/
#define LOW 0
#define HIGH 1

#define ON 1
#define OFF 0

#define TRUE 1
#define FALSE 0

#define MALE 0
#define FEMALE 1

#define IsolationYes 1
#define IsolationNo  0

#define NATURALCAUSES 0
#define COVID         1


/*##################################################################################*/
/*############################ COVID STATES ########################################*/
/*##################################################################################*/
#define  S            1      /* Susceptible individuals */
#define  E            2      /* Exposed */
#define  IP           3      /* Infectious Presymptomatic */
#define  IA           4      /* Infectious Asymptomatic */
#define  IS           5      /* Infectious Symptomatic  */
#define  H            6      /* Hospitalized individual */
#define  ICU          7      /* Individiual in ICU */
#define  Recovered    8      /* Recovered from COVID-19 */
#define  DeadCovid    9      /* Dead due to covid */
#define  Dead         10     /* Dead due to natutal death */

/* Sub states */
#define ISLight 	12  /* Infectious Symptomatic Mild Symptons */
#define ISModerate	13  /* Infectious Symptomatic Moderate Symptons */
#define ISSevere    14  /* Infectious Symptomatic Severe Symptons */

/*##################################################################################*/
/*############################### TB STATES ########################################*/
/*##################################################################################*/
#define STB  20 
#define LSTB 21
#define TSTB 22



/*##################################################################################*/
/*#########################     SIMULATION  SETTINGS     ###########################*/
/*##################################################################################*/

/***** SIMULATION OUTPUT SETTINGS *****/
#define PRINTONSCREEN TRUE
#define PRINTCOUNTERSONFILE TRUE
#define PRINTLATTICEONFILEATSTART FALSE
#define PRINTLATTICEONFILEATEND FALSE


/********** SIMULATION PARAMETERS ************/
#define L 317       /* Linear size of the lattice */
#define N L*L

#define DAYS 200    /* Number of days simulated */

#define Beta 0.20   


/*****  DEMOGRAPHIC PARAMETERS****/
#define Density LOW

#define totalWomen 97348809
#define totalMen 93406990

#define proportionOfWomen 0.510332
#define proportionOfMen 0.489668

#define proportionIsolated 0.5
#define BeginOfIsolation OFF  // time to begin isolation
#define TimeTiggerIsolation  15 // days

#define AverageOcupationRateBeds 0.5     // average ocupation rate of hospital beds due to others diseases
#define AverageOcupationRateBedsICU 0.5      // average ocupation rate of hospital beds due to others diseases

/* Population parameters  - Initializion values */
#define  Eini          0
#define  IPini         5
#define  IAini         0
#define  ISLightini    0
#define  ISModerateini 0
#define  ISSevereini   0
#define  Hini          0
#define  ICUini        0
#define  Recoveredini  0


/*********** COVID DISEASE CONSTANT PARAMETERS **************/
/* Probs of evolution between states */
#define ProbIPtoIA 0.5

#define ProbToBecomeISLight 0.6
#define ProbToBecomeISModerate 0.2
#define ProbToBecomeISSevere 0.2

#define ProbISLightToISModerate 0.10  /// NEW CHECK CHECK

#define ProbHtoICU 0.25

/* Probs of Recovery < 60 */
#define ProbRecoveryYoungerISModerate 0.6
#define ProbRecoveryYoungerISSevere 0.01   // out of hospital
#define ProbRecoveryYoungerH 1.0   ///NEW NEW < 20
#define ProbRecoveryYoungerICU 0.5

/* Probs Recovery IS Moderate for Elerdely */
#define ProbRecovery_60_70_ISModerate 0.21
#define ProbRecovery_70_80_ISModerate 0.15
#define ProbRecovery_80_90_ISModerate 0.13
#define ProbRecoveryGreater90_ISModerate 0.10

/* Probs Recovery IS Severe for Elerdely */
#define ProbRecovery_60_70_ISSevere 0.00357
#define ProbRecovery_70_80_ISSevere 0.00250
#define ProbRecovery_80_90_ISSevere 0.00125
#define ProbRecoveryGreater90_ISSevere 0.00167

/* Probs Recovery H for age > 20 */
#define ProbRecovery_20_30_H 0.959
#define ProbRecovery_30_40_H 0.962
#define ProbRecovery_40_50_H 0.938
#define ProbRecovery_50_60_H 0.897
#define ProbRecovery_60_70_H 0.842
#define ProbRecovery_70_80_H 0.678
#define ProbRecovery_80_90_H 0.457
#define ProbRecoveryGreater90_H 0.477

/* Probs Recovery ICU for Elerdely */
#define ProbRecovery_60_70_ICU 0.17857
#define ProbRecovery_70_80_ICU 0.12500
#define ProbRecovery_80_90_ICU 0.10417
#define ProbRecoveryGreater90_ICU 0.08333

/*  Periods on states */
#define minLatency 0.0           // days
#define maxLatency 27.5          // days

#define minIP 0.0          // days
#define maxIP 14.5        // days

#define minIA 0.0        // days
#define maxIA 7.5        // days

#define minISLight 0.0          // days
#define maxISLight 14.5        // days

#define minISModerate 0.0          // days
#define maxISModerate 28.0        // days

#define minISSevere 0.0          // days
#define maxISSevere 4.0        // days

#define minH 7.5
#define maxH 45.5

#define minICU 10.5
#define maxICU 60.5

/*********** TB DISEASE CONSTANT PARAMETERS **************/