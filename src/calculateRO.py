#!/usr/bin/env python
# coding: utf-8

import numpy as np
import math 


data = np.genfromtxt('RO.txt', delimiter='\n')

if( (data.mean() - int(data.mean())) > 0.5 ):
    print("", math.ceil(data.mean()) )
else:
    print("", math.floor(data.mean()) )