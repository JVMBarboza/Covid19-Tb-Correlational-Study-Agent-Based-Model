#!/usr/bin/env python
# coding: utf-8

import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sns

dataSet = pd.read_csv("lattice.csv")
dataSet = dataSet.pivot("y-coord","x-coord","State")

ax = sns.heatmap(dataSet, annot=False, fmt="d", linewidths=.5, cbar=False, cmap = "PiYG_r")
plt.show()