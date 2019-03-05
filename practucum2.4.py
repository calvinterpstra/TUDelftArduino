# -*- coding: utf-8 -*-
"""
Created on Fri Dec 15 21:57:49 2017

@author: Calvin
"""

import numpy as np
import matplotlib.pyplot as plt

quality = 10000 # Elements in range
R_load = np.linspace(47, 100000, quality) # resistance (ohm)
R_thevenin = 220 # resistance (ohm)
U_thevenin = 5 # voltage (V)

def main():
    U0 = U_thevenin * (R_load/(R_load+R_thevenin))
    print("U0: ", np.interp(47, R_load, U0))

    I = U0/R_load
    P = I**2 * R_thevenin

    measured_U0 = np.array([0.83, 2.37, 3.22, 4.37, 4.61, 4.82, 4.87, 4.90])
    measured_R_load = np.array([47, 220, 470, 2200, 4700, 22000, 47000, 100000])

    measured_U0_2 = np.array([4.1, 4.69, 4.75, 4.80, 4.83, 4.87, 4.89, 4.91])
    measured_U0_3 = np.array([1.23, 3.78, 4.83, 4.88, 4.89, 4.89, 4.90, 4.90])

    plt.figure(0)
    fig, ax1 = plt.subplots()

    ax1.plot(R_load, U0, 'b', lw=2)
    ax1.plot(measured_R_load, measured_U0, 'y', lw=2)
    ax1.set_xlabel("R_load (Ohm)")
    ax1.set_ylabel("U0 (V)")

    ax2 = ax1.twinx()
    ax2.plot(R_load, P, 'r', lw=2)
    ax2.set_xlabel("power dissapated (Watts)")
    ax2.set_ylabel("U0 (V)")

    fig.tight_layout()
    plt.grid()
    plt.title("Theoretical voltage and power dissapated")
    plt.show()

    plt.figure(1)
    plt.plot(measured_R_load, measured_U0_2, 'b', lw=2)
    plt.plot(measured_R_load, measured_U0_3, 'g', lw=2)
    plt.show()

main()
