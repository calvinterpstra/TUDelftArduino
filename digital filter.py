# -*- coding: utf-8 -*-

import numpy as np
from scipy import signal
import matplotlib.pyplot as plt

R = 2200
C = 1e-6
f_c = 1/(2*np.pi*R*C) 	#analog cut-off frequency (Hz)
omega_c = 2*np.pi*f_c	   #(rad/s)
f_s = 3333              #sampling frequency (Hz)
T_s = (2*np.pi)/f_s               #Sampling period (s)
omega_d = omega_c	      #desired cut-off frequency (rad/s)

omega_a = (2/T_s)*np.tan((T_s*omega_d)/2) #analog required frequency (rad/s)
f_a = omega_a/(2*np.pi)

C1 = 2/(omega_a*T_s)    #digital filter constant 1
C2 = 1/(1+C1)           #digital filter constant 2

xk = C2
xk1 = C2
yk1 = C2*(C1-1)

print('y[k] = {:.5f}x[k] + {:.5f}x[k-1] + {:.5f}y[k-1]'.format(xk,xk1,yk1))


#================ MAKING THE BODE PLOT =======================#

system = signal.lti([1], [(1/omega_a),1])
f = np.logspace(0.1, 5)
w = 2*np.pi*f
w, mag, phase = signal.bode(system,w)

fig, (ax1, ax2) = plt.subplots(2, 1)
fig.subplots_adjust(hspace=0.8) #Vertical Space adjuster

ax1.set_title('|H(w)|')
ax1.semilogx(w, mag,'b',lw=2)    #Magnitude plot
ax1.set_xlabel('w [rad/s]')
ax1.set_ylabel('|H(w)|')
ax1.axvline(omega_c, color='r', lw=2) # cutoff frequency
ax1.set_xlim(10,1000)
ax1.grid(which='both', axis='both')


b, a = signal.butter(2, 0.05, 'lowpass', analog=False)
w, h = signal.freqs(b, a)

ax2.plot(w, 20 * np.log10(abs(h)),color='blue',lw=2)
ax2.set_xscale('log')
ax2.set_title('Butterworth digital filter')
ax2.set_xlabel('Angular frequency [rad/s]')
ax2.set_ylabel('Amplitude [dB]')
ax2.grid(which='both', axis='both')
ax2.axvline(omega_c, color='red', lw=2) # cutoff frequency
