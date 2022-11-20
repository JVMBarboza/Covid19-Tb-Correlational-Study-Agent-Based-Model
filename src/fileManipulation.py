#!/usr/bin/env python
# coding: utf-8

import glob
import pandas as pd 


#LOADING DATA FILES 
filenames = glob.glob("results/04simulationCoinfection\
/*-count*.csv")

filenamesTB = glob.glob("results/04simulationCoinfection\
/*-TBcount*.csv")


# SETTING FRAMES

#covid-19
susceptibleFrame           = pd.DataFrame() # In matplot -> index = 1
exposedFrame               = pd.DataFrame() # In matplot -> index = 2
presymptomaticFrame        = pd.DataFrame() # ...
asymptomaticFrame          = pd.DataFrame()
symptomaticMildFrame       = pd.DataFrame()
symptomaticModerateFrame   = pd.DataFrame()
symptomaticSevereFrame     = pd.DataFrame()
hospitalizedFrame          = pd.DataFrame()
ICUFrame                   = pd.DataFrame()
recoveredFrame             = pd.DataFrame()
deathsByCovidFrame         = pd.DataFrame()
naturalDeathsFrame         = pd.DataFrame()    
dailyDeathsByCovidFrame    = pd.DataFrame()
availableHospitalBedsFrame = pd.DataFrame()
availableICUBedsFrame      = pd.DataFrame()


#tb
TBsusceptibleFrame = pd.DataFrame()
TBexposedFrame     = pd.DataFrame()
TBactivatedFrame   = pd.DataFrame()
TBdeathsFrame      = pd.DataFrame()


#MANIPULATING DATA
for file in filenames:
    df=pd.read_csv(file)
    susceptibleFrame           = pd.concat([susceptibleFrame, df["S"]], axis=1)
    exposedFrame               = pd.concat([exposedFrame, df["E"]], axis=1)
    presymptomaticFrame        = pd.concat([presymptomaticFrame, df["IP"]], axis=1)
    asymptomaticFrame          = pd.concat([asymptomaticFrame, df["IA"]], axis=1)
    symptomaticMildFrame       = pd.concat([symptomaticMildFrame, df["ISLight"]], axis=1)
    symptomaticModerateFrame   = pd.concat([symptomaticModerateFrame, df["ISModerate"]], axis=1)
    symptomaticSevereFrame     = pd.concat([symptomaticSevereFrame, df["ISSevere"]], axis=1)
    hospitalizedFrame          = pd.concat([hospitalizedFrame, df["H"]], axis=1)
    ICUFrame                   = pd.concat([ICUFrame, df["ICU"]], axis=1)
    recoveredFrame             = pd.concat([recoveredFrame, df["Recovered"]], axis=1)  
    deathsByCovidFrame         = pd.concat([deathsByCovidFrame, df["Deaths by Covid"]], axis=1)
    naturalDeathsFrame         = pd.concat([naturalDeathsFrame, df["Natural Deaths"]], axis=1) 
    dailyDeathsByCovidFrame    = pd.concat([dailyDeathsByCovidFrame, df["Daily Deaths"]], axis=1)
    availableHospitalBedsFrame = pd.concat([availableHospitalBedsFrame, df["Available Hospital Beds"]], axis=1)
    availableICUBedsFrame      = pd.concat([availableICUBedsFrame, df["Available ICU Beds"]], axis=1)
  

for file in filenamesTB:
    dfTB=pd.read_csv(file)
    TBsusceptibleFrame = pd.concat([TBsusceptibleFrame, dfTB["S"]], axis=1)
    TBexposedFrame     = pd.concat([TBexposedFrame, dfTB["LS"]], axis=1)
    TBactivatedFrame   = pd.concat([TBactivatedFrame, dfTB["TS"]], axis=1)
    TBdeathsFrame      = pd.concat([TBdeathsFrame, dfTB["Tb Daily Deaths"]], axis=1)


#CALCULATING MEAN VALUES
susceptibleFrame["Susceptible Mean"]                       = susceptibleFrame.mean(axis=1)
exposedFrame["Exposed Mean"]                               = exposedFrame.mean(axis=1)
presymptomaticFrame["Presymptomatic Mean"]                 = presymptomaticFrame.mean(axis=1)
asymptomaticFrame["Asymptomatic Mean"]                     = asymptomaticFrame.mean(axis=1)
symptomaticMildFrame["Symptomatic Mild Mean"]              = symptomaticMildFrame.mean(axis=1)
symptomaticModerateFrame["Symptomatic Moderate Mean"]      = symptomaticModerateFrame.mean(axis=1)
symptomaticSevereFrame["Symptomatic Severe Mean"]          = symptomaticSevereFrame.mean(axis=1)
hospitalizedFrame["Hospitalized Mean"]                     = hospitalizedFrame.mean(axis=1)
ICUFrame["ICU Mean"]                                       = ICUFrame.mean(axis=1)
recoveredFrame["Recovered Mean"]                           = recoveredFrame.mean(axis=1)
deathsByCovidFrame["Deaths by Covid Mean"]                 = deathsByCovidFrame.mean(axis=1)
naturalDeathsFrame["Natural Deaths Mean"]                  = naturalDeathsFrame.mean(axis=1)
dailyDeathsByCovidFrame["Daily Deaths by Covid Mean"]      = dailyDeathsByCovidFrame.mean(axis=1)
availableHospitalBedsFrame["Available Hospital Beds Mean"] = availableHospitalBedsFrame.mean(axis=1)
availableICUBedsFrame["Available ICU Beds Mean"]           = availableICUBedsFrame.mean(axis=1)


TBsusceptibleFrame["Susceptible Mean"] = TBsusceptibleFrame.mean(axis=1)
TBexposedFrame["Exposed Mean"]         = TBexposedFrame.mean(axis=1)
TBactivatedFrame["Activated Mean"]     = TBactivatedFrame.mean(axis=1)
TBdeathsFrame["Tb Daily Deaths Mean"]  = TBdeathsFrame.mean(axis=1) 


#OUTPUT
outputFrame = pd.concat([susceptibleFrame["Susceptible Mean"]                      
                       , exposedFrame["Exposed Mean"]                              
                       , presymptomaticFrame["Presymptomatic Mean"]                
                       , asymptomaticFrame["Asymptomatic Mean"]                    
                       , symptomaticMildFrame["Symptomatic Mild Mean"]             
                       , symptomaticModerateFrame["Symptomatic Moderate Mean"]     
                       , symptomaticSevereFrame["Symptomatic Severe Mean"]         
                       , hospitalizedFrame["Hospitalized Mean"]                    
                       , ICUFrame["ICU Mean"]                                      
                       , recoveredFrame["Recovered Mean"]                          
                       , deathsByCovidFrame["Deaths by Covid Mean"]                
                       , naturalDeathsFrame["Natural Deaths Mean"]                 
                       , dailyDeathsByCovidFrame["Daily Deaths by Covid Mean"]     
                       , availableHospitalBedsFrame["Available Hospital Beds Mean"]
                       , availableICUBedsFrame["Available ICU Beds Mean"]], axis=1)


outputFrameTB = pd.concat([TBsusceptibleFrame["Susceptible Mean"]
                        , TBexposedFrame["Exposed Mean"]
                        , TBactivatedFrame["Activated Mean"]
                        , TBdeathsFrame["Tb Daily Deaths Mean"]], axis=1)


outputFrame.to_csv("result.csv", index=True)
outputFrameTB.to_csv("result_tb.csv", index= True)