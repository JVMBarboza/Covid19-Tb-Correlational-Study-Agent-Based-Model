#!/usr/bin/env python
# coding: utf-8

import numpy as np
import matplotlib.pyplot as plt 

plt.rcParams['figure.figsize'] = 13, 7

plt.rc('xtick', labelsize=13.5)
plt.rc('ytick', labelsize=13.5)

fig_name="05result_infecciosos_covid.jpg"

##################### LOADING DATA FROM CSV FILE ########################################## 

data_actual = np.genfromtxt('results/05simulation-omicron/result.csv', delimiter=',')
data_base   = np.genfromtxt('results/02simulation/result.csv', delimiter=',')


########################### STORE data_base TO PLOT ###################################

time2                  = data_actual[:,0] #index
susceptible2           = data_actual[:,1]
exposed2               = data_actual[:,2]
presymptomatic2        = data_actual[:,3]
asymptomatic2          = data_actual[:,4]
symptomaticMild2       = data_actual[:,5]
symptomaticModerate2   = data_actual[:,6]
symptomaticSevere2     = data_actual[:,7]
hospitalized2          = data_actual[:,8]
icu2                   = data_actual[:,9]
recovered2             = data_actual[:,10]
covidDeaths2           = data_actual[:,11]
naturalDeaths2         = data_actual[:,12]
dailyDeaths2           = data_actual[:,13]
availableHospitalBeds2 = data_actual[:,14]
availableICUBeds2      = data_actual[:,15] 

time3                  = data_base[:,0] #index
susceptible3           = data_base[:,1]
exposed3               = data_base[:,2]
presymptomatic3        = data_base[:,3]
asymptomatic3          = data_base[:,4]
symptomaticMild3       = data_base[:,5]
symptomaticModerate3   = data_base[:,6]
symptomaticSevere3     = data_base[:,7]
hospitalized3          = data_base[:,8]
icu3                   = data_base[:,9]
recovered3             = data_base[:,10]
covidDeaths3           = data_base[:,11]
naturalDeaths3         = data_base[:,12]
dailyDeaths3           = data_base[:,13]
availableHospitalBeds3 = data_base[:,14]
availableICUBeds3      = data_base[:,15] 


########################### PLOT CONFIGURATION ###################################

#f, (mainPlot, stdPlot) = plt.subplots(2,1,sharex=True, gridspec_kw={'height_ratios': [4.8, 1]})
mainPlot = plt.figure().add_axes([0.1, 0.1, 0.8, 0.8])


########################### MAIN CURVE SETTINGS ##################################
 
#COVID-19
#mainPlot.plot(time, susceptible, color='#008000', lw=1.5, label="Susceptible")

mainPlot.plot(time3, symptomaticMild3+symptomaticModerate3+symptomaticSevere3, color='#e2d2c5', lw=1.5, label="Infectious, No Coinfection Scenario")
mainPlot.plot(time2, symptomaticMild2+symptomaticModerate2+symptomaticSevere2, color='#720026', lw=1.5, label="Infectious, Coinfection Scenario")

mainPlot.fill_between(time3, 0, symptomaticMild3+symptomaticModerate3+symptomaticSevere3, color='#dcdad8', lw=1.5)
mainPlot.fill_between(time2, 0, symptomaticMild2+symptomaticModerate2+symptomaticSevere2, color='#ce4257', lw=1.5)




#################################### GENERAL SETTINGS ###################################

#X-AXIS
minXPlot  = 0   # x-axis inferior limit
maxXPlot  = 200 # x-axis superior limit
gridSteps = 20  # x-axis grid steps
dayOfCoinfectionStart = 3650
dayOfMaximumExposure2 = 80.8
dayOfMaximumExposure3 = 111

mainPlot.set_xlim([minXPlot,maxXPlot])
mainPlot.set_xticks(np.arange(minXPlot,maxXPlot, step=gridSteps))
mainPlot.set_xlabel('Time (Days)', fontsize=15)

#Y-AXIS
minYplot = 0
maxYplot = 18000 #317*317
plotVerticalLineAtDayOfMaximumExposureSim2 = True
plotVerticalLineAtDayOfMaximumExposureSim3 = True
plotVerticalLineAtCoinfectionDayZero = False

#mainPlot.set_ylim([0,1.0])
#mainPlot.set_yticks(np.arange(0,1.0001,step=0.1))
mainPlot.set_ylabel('Number of Individuals', fontsize=15)

if plotVerticalLineAtDayOfMaximumExposureSim2 == True:
    mainPlot.vlines(x=dayOfMaximumExposure2, ymin=0, ymax=maxYplot, colors='#6a040f', ls='--', lw=2)

if plotVerticalLineAtDayOfMaximumExposureSim3 == True:
    mainPlot.vlines(x=dayOfMaximumExposure3, ymin=0, ymax=maxYplot, colors='grey', ls='--', lw=2)

if plotVerticalLineAtCoinfectionDayZero == True:
    mainPlot.vlines(x=dayOfCoinfectionStart, ymin=0, ymax=maxYplot, colors='grey', ls='--', lw=2, label='Coinfection Day Zero')


#mainPlot.set_title('Figure 1')
mainPlot.legend(fontsize=13, loc="upper left")
mainPlot.grid(True,axis='both',alpha=0.35)
mainPlot.tick_params(axis='both',direction='in',bottom=1, top=0, left=1, right=0)

############################ OUTPUT SETTINGS ########################################
plt.tight_layout() 
plt.savefig(fig_name, dpi=600, facecolor='w', edgecolor='w',
    orientation='portrait', format=None,
    transparent=False, bbox_inches=None, pad_inches=0.1)

plt.show()

print("Successfully Plotted! #DAFTBA")