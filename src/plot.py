#!/usr/bin/env python
# coding: utf-8

import numpy as np
import matplotlib.pyplot as plt 

plt.rcParams['figure.figsize'] = 13, 7

plt.rc('xtick', labelsize=13.5)
plt.rc('ytick', labelsize=13.5)

fig_name="result03.png"

##################### LOADING DATA FROM CSV FILE ########################################## 

data   = np.genfromtxt('results/\
03simulationCoinfection\
/result.csv', delimiter=',')

tbdata = np.genfromtxt('results/\
03simulationCoinfection\
/result_tb.csv', delimiter=',')


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

timeTB        = tbdata[:,0] #index
susceptibleTB = tbdata[:,1]
exposedTB     = tbdata[:,2]
activatedTB   = tbdata[:,3]
dailyDeathsTB = tbdata[:,4]



########################### PLOT CONFIGURATION ###################################

#f, (mainPlot, stdPlot) = plt.subplots(2,1,sharex=True, gridspec_kw={'height_ratios': [4.8, 1]})
mainPlot = plt.figure().add_axes([0.1, 0.1, 0.8, 0.8])

########################### MAIN CURVE SETTINGS ##################################
 
#COVID-19
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
#mainPlot.plot(time, covidDeaths, color='#c84204', lw=1.5, label="Covid-19 deaths")
#mainPlot.plot(time, naturalDeaths, color='#0e2a18', lw=1.5, label="Natural deaths", ls="dotted")
#mainPlot.plot(time, dailyDeaths, color='#932f01', lw=1.5, label="Daily Covid-19 deaths", ls="dotted")
#mainPlot.plot(time, availableHospitalBeds, color='#f3722c', lw=2.5, label="Available Hospital Beds", ls="dotted")
#mainPlot.plot(time, availableICUBeds, color='#f3722c', lw=1.5, label="Available ICU Beds")

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
#mainPlot.fill_between(time, 0, covidDeaths, color='#c84204', lw=1.5, ls="dotted")
#mainPlot.fill_between(time, 0, naturalDeaths, color='#0e2a18', lw=1.5)
#mainPlot.fill_between(time, 0, dailyDeaths, color='#932f01', lw=1.5)
#mainPlot.fill_between(time, 0, availableHospitalBeds, color='#02a19b', lw=1.5)
#mainPlot.fill_between(time, 0, availableICUBeds, color='#005aa8', lw=1.5)


#TB
mainPlot.plot(timeTB, susceptibleTB, color='#008000', lw=1.5, label="Susceptible")
mainPlot.plot(timeTB, exposedTB, color='#fec89a', lw=1.5, label="Latent")
#mainPlot.plot(timeTB, activatedTB, color='#ec7627', lw=1.5, label="Activated")
#mainPlot.plot(timeTB, dailyDeathsTB, color='#932f01', lw=1.5, label="Daily TB deaths", ls="dotted")

#mainPlot.fill_between(timeTB, 0, susceptibleTB, color='#38b000', lw=1.5)
#mainPlot.fill_between(timeTB, 0, exposedTB, color='#f9dcc4', lw=1.5)
#mainPlot.fill_between(timeTB, 0, activatedTB, color='#ec7627', lw=1.5)
#mainPlot.fill_between(timeTB, 0, dailyDeathsTB, color='#932f01', lw=1.5)


#################################### GENERAL SETTINGS ###################################

#X-AXIS
minXPlot  = 0    # x-axis inferior limit
maxXPlot  = 3850 # x-axis superior limit
gridSteps = 400  # x-axis grid steps
dayOfCoinfectionStart = 3650

mainPlot.set_xlim([minXPlot,maxXPlot])
mainPlot.set_xticks(np.arange(minXPlot,maxXPlot, step=gridSteps))
mainPlot.set_xlabel('Time(Days)', fontsize=15)

#Y-AXIS
minYplot = 0
maxYplot = 80000 #317*317
plotVerticalLineAtCoinfectionDayZero = True

#mainPlot.set_ylim([0,1.0])
#mainPlot.set_yticks(np.arange(0,1.0001,step=0.1))
mainPlot.set_ylabel('Density in Population', fontsize=15)

if plotVerticalLineAtCoinfectionDayZero == True:
    mainPlot.vlines(x=dayOfCoinfectionStart, ymin=0, ymax=maxYplot, colors='purple', ls='--', lw=2, label='Coinfection day 0')


#mainPlot.set_title('Figure 1')
mainPlot.legend(fontsize=13)
mainPlot.grid(True,axis='both',alpha=0.35)
mainPlot.tick_params(axis='both',direction='in',bottom=1, top=0, left=1, right=0)

############################ OUTPUT SETTINGS ########################################
plt.tight_layout() 
plt.savefig(fig_name, dpi=600, facecolor='w', edgecolor='w',
    orientation='portrait', papertype=None, format=None,
    transparent=False, bbox_inches=None, pad_inches=0.1,
    frameon=None)

plt.show()

print("Successfully Plotted! #DAFTBA")