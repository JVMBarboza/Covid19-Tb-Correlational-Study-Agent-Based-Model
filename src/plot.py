#!/usr/bin/env python
# coding: utf-8

import numpy as np
import matplotlib.pyplot as plt 

plt.rcParams['figure.figsize'] = 13, 7

plt.rc('xtick', labelsize=13.5)
plt.rc('ytick', labelsize=13.5)

fig_name="simulationTest.png"

##################### LOADING DATA FROM CSV FILE ########################################## 

data    = np.genfromtxt('results/simulationTest/result.csv', delimiter=',')
#dataStd = np.genfromtxt('results/simulation01/result_standar_deviation.csv', delimiter=',')

#time = [ i for i in range(1,203) ] 

########################### STORE DATA TO PLOT ###################################

time                  = data[:,0] #index
susceptible           = data[:,1]
exposed               = data[:,2]
presymptomatic        = data[:,3]
asymptomatic          = data[:,4]
symptomaticMild       = data[:,5]
symptomaticModerate   = data[:,6]
symptomaticSevere     = data[:,7]
hospitalized          = data[:,8]
icu                   = data[:,9]
recovered             = data[:,10]
covidDeaths           = data[:,11]
naturalDeaths         = data[:,12]
dailyDeaths           = data[:,13]
availableHospitalBeds = data[:,14]
availableICUBeds      = data[:,15]  


########################### PLOT CONFIGURATION ###################################

#f, (mainPlot, stdPlot) = plt.subplots(2,1,sharex=True, gridspec_kw={'height_ratios': [4.8, 1]})
mainPlot = plt.figure().add_axes([0.1, 0.1, 0.8, 0.8])

########################### MAIN CURVE SETTINGS ##################################
 
mainPlot.plot(time, susceptible, color='#19f56a', lw=1.5, label="Susceptible")
mainPlot.plot(time, exposed, color='#f5d419', lw=1.5, label="Exposed")
mainPlot.plot(time, presymptomatic, color='#ec7627', lw=1.5, label="Presymptomatic")
mainPlot.plot(time, asymptomatic, color='#ee5749', lw=1.5, label="Asymptomatic")
mainPlot.plot(time, symptomaticMild, color='#f82e1b', lw=1.5, label="Symptomatic Mild", ls='dashed')
mainPlot.plot(time, symptomaticModerate, color='#bb1102', lw=1.5, label="Symptomatic Moderate", ls='dotted')
mainPlot.plot(time, symptomaticSevere, color='#870303', lw=1.5, label="Symptomatic Severe", ls='dashdot')
mainPlot.plot(time, hospitalized, color='#660000', lw=1.5, label="Hospitalized")
mainPlot.plot(time, icu, color='#1e0000', lw=1.5, label="ICU")
mainPlot.plot(time, recovered, color='#006625', lw=1.5, label="Recovered")
mainPlot.plot(time, covidDeaths, color='#c84204', lw=1.5, label="Covid-19 deaths", ls="dotted")
mainPlot.plot(time, naturalDeaths, color='#0e2a18', lw=1.5, label="Natural deaths")
mainPlot.plot(time, dailyDeaths, color='#932f01', lw=1.5, label="Daily Covid-19 deaths")
mainPlot.plot(time, availableHospitalBeds, color='#02a19b', lw=1.5, label="Available Hospital Beds")
mainPlot.plot(time, availableICUBeds, color='#005aa8', lw=1.5, label="Available ICU Beds")



#mainPlot.set_title('Figure 1')
mainPlot.legend(fontsize=13)
mainPlot.grid(True,axis='both',alpha=0.35)
mainPlot.tick_params(axis='both',direction='in',bottom=1, top=0, left=1, right=0)

#X-AXIS
mainPlot.set_xlim([0,201])
mainPlot.set_xticks(np.arange(0, 201, step=20))
mainPlot.set_xlabel('Time(Days)', fontsize=15)

#Y-AXIS
#mainPlot.set_ylim([0,1.0])
#mainPlot.set_yticks(np.arange(0,1.0001,step=0.1))
mainPlot.set_ylabel('Density in Population', fontsize=15)


####################### STANDARD DEVIATION CURVE SETTINGS ###############################

#stdPlot.plot(time, susceptible_Std , color='#19f56a', lw=1.30, ls='dashed', label="Susceptible Standard Deviation")
#stdPlot.plot(time, latent_Std      , color='#fafe06', lw=1.30, label="Latent")
#stdPlot.plot(time, stg1_Std        , color='#feaf06', lw=1.30, label="Stage 1 Infectives")
#stdPlot.plot(time, stg2_Std        , color='#59109e', lw=1.30, label="Stage 2 Infectives")
#stdPlot.plot(time, total_Std       , color='#bf1303', lw=1.30, ls='dashed', label="Total Infectives")
#stdPlot.plot(time, recov_Std       , color='#07b404', lw=1.30, label="Recovered")
#stdPlot.plot(time, in_treatm_Std   , color='#c516b7', lw=1.30, label="Treatment in Progress")

#stdPlot.legend(fontsize=13)
#stdPlot.grid(True,axis='both',alpha=0.35)
#stdPlot.tick_params(axis='both',direction='in',bottom=1, top=0, left=1, right=0)

#X-AXIS
#stdPlot.set_xlim([0,10])
#stdPlot.set_xticks(np.arange(0, 10.2, step=1))
#stdPlot.set_xlabel('Time(Years)', fontsize=15)

#Y-AXIS
#stdPlot.set_ylim([0,0.021])
#stdPlot.set_yticks(np.arange(0,0.021,step=0.01))
#stdPlot.set_ylabel('σ', fontsize=15)



############################ OUTPUT SETTINGS ########################################

plt.tight_layout() 
plt.savefig(fig_name, dpi=600, facecolor='w', edgecolor='w',
    orientation='portrait', papertype=None, format=None,
    transparent=False, bbox_inches=None, pad_inches=0.1,
    frameon=None)

plt.show()