# -*- coding: utf-8 -*-

import numpy as np
import matplotlib.pyplot as plt

R = 2200
C = 1e-6
f_c = 1/(2*np.pi*R*C) 	#analog cut-off frequency (Hz)
omega_c = 2*np.pi*f_c	#(rad/s)
T_c = 2*np.pi/omega_c 		#period (s)
omega_d = omega_c		#desired cut-off frequency (rad/s)


omega_a = (2/T_c)*np.tan((omega_d)/2) #analog required frequency (rad/s)
f_a = (2*np.pi)/omega_a

