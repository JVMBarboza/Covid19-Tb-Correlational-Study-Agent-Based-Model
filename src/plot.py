#!/usr/bin/env python
# coding: utf-8

import numpy as np
import matplotlib.pyplot as plt 

plt.rcParams['figure.figsize'] = 13, 7

plt.rc('xtick', labelsize=13.5)
plt.rc('ytick', labelsize=13.5)

fig_name="02.png"

##################### LOADING DATA FROM CSV FILE ########################################## 

data    = np.genfromtxt('results/02simulationCovidSoloLowDensity/result.csv', delimiter=',')
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
 
#mainPlot.plot(time, susceptible, color='#008000', lw=1.5, label="Susceptible")
#mainPlot.plot(time, exposed, color='#fec89a', lw=1.5, label="Exposed")
#mainPlot.plot(time, presymptomatic, color='#ec7627', lw=1.5, label="Presymptomatic")
#mainPlot.plot(time, asymptomatic, color='#ee5749', lw=1.5, label="Asymptomatic")
#mainPlot.plot(time, symptomaticMild, color='#f82e1b', lw=1.5, label="Symptomatic Mild", ls='dashed')
#mainPlot.plot(time, symptomaticModerate, color='#bb1102', lw=1.5, label="Symptomatic Moderate", ls='dotted')
#mainPlot.plot(time, symptomaticSevere, color='#870303', lw=1.5, label="Symptomatic Severe", ls='dashdot')
#mainPlot.plot(time, hospitalized, color='#a4133c', lw=1.5, label="Hospitalized")
#mainPlot.plot(time, icu, color='#a4133c', lw=1.5, label="ICU")
#mainPlot.plot(time, recovered, color='#006625', lw=1.5, label="Recovered")
mainPlot.plot(time, covidDeaths, color='#c84204', lw=1.5, label="Covid-19 deaths")
#mainPlot.plot(time, naturalDeaths, color='#0e2a18', lw=1.5, label="Natural deaths", ls="dotted")
#mainPlot.plot(time, dailyDeaths, color='#932f01', lw=1.5, label="Daily Covid-19 deaths", ls="dotted")
#mainPlot.plot(time, availableHospitalBeds, color='#f3722c', lw=2.5, label="Available Hospital Beds", ls="dotted")
#mainPlot.plot(time, availableICUBeds, color='#f3722c', lw=1.5, label="Available ICU Beds")


#mainPlot.set_title('Figure 1')
mainPlot.legend(fontsize=13)
mainPlot.grid(True,axis='both',alpha=0.35)
mainPlot.tick_params(axis='both',direction='in',bottom=1, top=0, left=1, right=0)

#X-AXIS
mainPlot.set_xlim([0,201])
mainPlot.set_xticks(np.arange(0, 201, step=20))
mainPlot.set_xlabel('Time(Days)', fontsize=15)


#mainPlot.fill_between(time, 0, susceptible, color='#38b000', lw=1.5)
#mainPlot.fill_between(time, 0, exposed, color='#f9dcc4', lw=1.5)
#mainPlot.fill_between(time, 0, presymptomatic, color='#ec7627', lw=1.5)
#mainPlot.fill_between(time, 0, asymptomatic, color='#ee5749', lw=1.5)
#mainPlot.fill_between(time, 0, symptomaticMild, color='#f82e1b', lw=1.5, ls='dashed')
#mainPlot.fill_between(time, 0, symptomaticModerate, color='#bb1102', lw=1.5, ls='dotted')
#mainPlot.fill_between(time, 0, symptomaticSevere, color='#870303', lw=1.5,  ls='dashdot')
#mainPlot.fill_between(time, 0, hospitalized, color='#c9184a', lw=1.5 )
#mainPlot.fill_between(time, 0, icu, color='#c9184a', lw=1.5)
#mainPlot.fill_between(time, 0, recovered, color='#006625', lw=1.5)
mainPlot.fill_between(time, 0, covidDeaths, color='#c84204', lw=1.5, ls="dotted")
#mainPlot.fill_between(time, 0, naturalDeaths, color='#0e2a18', lw=1.5)
#mainPlot.fill_between(time, 0, dailyDeaths, color='#932f01', lw=1.5)
#mainPlot.fill_between(time, 0, availableHospitalBeds, color='#02a19b', lw=1.5)
#mainPlot.fill_between(time, 0, availableICUBeds, color='#005aa8', lw=1.5)


#Y-AXIS
#mainPlot.set_ylim([0,1.0])
#mainPlot.set_yticks(np.arange(0,1.0001,step=0.1))
mainPlot.set_ylabel('Density in Population', fontsize=15)


############################ OUTPUT SETTINGS ########################################

plt.tight_layout() 
plt.savefig(fig_name, dpi=600, facecolor='w', edgecolor='w',
    orientation='portrait', papertype=None, format=None,
    transparent=False, bbox_inches=None, pad_inches=0.1,
    frameon=None)

plt.show()