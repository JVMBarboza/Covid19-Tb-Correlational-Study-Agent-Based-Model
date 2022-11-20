#!/usr/bin/env python
# coding: utf-8

import numpy as np
import matplotlib.pyplot as plt 

plt.rcParams['figure.figsize'] = 13, 7

plt.rc('xtick', labelsize=13.5)
plt.rc('ytick', labelsize=13.5)

fig_name="result03.png"

##################### LOADING DATA FROM CSV FILE ########################################## 

data2   = np.genfromtxt('results/02simulationCovidSoloLowDensity/result.csv', delimiter=',')
data3   = np.genfromtxt('results/03simulationCoinfection/result.csv', delimiter=',')


########################### STORE data3 TO PLOT ###################################

time2                  = data2[:,0] #index
susceptible2           = data2[:,1]
exposed2               = data2[:,2]

time3                  = data3[:,0] #index
susceptible3           = data3[:,1]
exposed3               = data3[:,2]


########################### PLOT CONFIGURATION ###################################

#f, (mainPlot, stdPlot) = plt.subplots(2,1,sharex=True, gridspec_kw={'height_ratios': [4.8, 1]})
mainPlot = plt.figure().add_axes([0.1, 0.1, 0.8, 0.8])


########################### MAIN CURVE SETTINGS ##################################
 
#COVID-19
#mainPlot.plot(time, susceptible, color='#008000', lw=1.5, label="Susceptible")

mainPlot.plot(time2, exposed2, color='#e2d2c5', lw=1.5, label="Expostos COVID-19 sem Coinfecção")
mainPlot.plot(time3, exposed3, color='#fec89a', lw=1.5, label="Expostos COVID-19 durante Coinfecção")

mainPlot.fill_between(time2, 0, exposed2, color='#dcdad8', lw=1.5)
mainPlot.fill_between(time3, 0, exposed3, color='#f9dcc4', lw=1.5)



#################################### GENERAL SETTINGS ###################################

#X-AXIS
minXPlot  = 0   # x-axis inferior limit
maxXPlot  = 200 # x-axis superior limit
gridSteps = 20  # x-axis grid steps
dayOfCoinfectionStart = 3650
dayOfMaximumExposure2 = 92
dayOfMaximumExposure3 = 83

mainPlot.set_xlim([minXPlot,maxXPlot])
mainPlot.set_xticks(np.arange(minXPlot,maxXPlot, step=gridSteps))
mainPlot.set_xlabel('Time(Days)', fontsize=15)

#Y-AXIS
minYplot = 0
maxYplot = 317*317
plotVerticalLineAtDayOfMaximumExposureSim2 = True
plotVerticalLineAtDayOfMaximumExposureSim3 = True
plotVerticalLineAtCoinfectionDayZero = False

#mainPlot.set_ylim([0,1.0])
#mainPlot.set_yticks(np.arange(0,1.0001,step=0.1))
mainPlot.set_ylabel('Density in Population', fontsize=15)

if plotVerticalLineAtDayOfMaximumExposureSim2 == True:
    mainPlot.vlines(x=dayOfMaximumExposure2, ymin=0, ymax=maxYplot, colors='blue', ls='--', lw=2, label='Pico de Exposição COVID-19 sem Coinfecção')

if plotVerticalLineAtDayOfMaximumExposureSim3 == True:
    mainPlot.vlines(x=dayOfMaximumExposure3, ymin=0, ymax=maxYplot, colors='red', ls='--', lw=2, label='Pico de Exposição COVID-19 durante Coinfecção')

if plotVerticalLineAtCoinfectionDayZero == True:
    mainPlot.vlines(x=dayOfCoinfectionStart, ymin=0, ymax=maxYplot, colors='purple', ls='--', lw=2, label='Coinfection day 0')


#mainPlot.set_title('Figure 1')
mainPlot.legend(fontsize=13)
mainPlot.grid(True,axis='both',alpha=0.35)
mainPlot.tick_params(axis='both',direction='in',bottom=1, top=0, left=1, right=0)

############################ OUTPUT SETTINGS ########################################
plt.tight_layout() 
plt.savefig(fig_name, dpi=600, facecolor='w', edgecolor='w',
    orientation='portrait', format=None,
    transparent=False, bbox_inches=None, pad_inches=0.1)

plt.show()

print("Successfully Plotted! #DAFTBA")