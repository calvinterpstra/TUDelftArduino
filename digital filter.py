# -*- coding: utf-8 -*-

import numpy as np
import matplotlib.pyplot as plt

# R = 2.2 * 10**3
# a = 3.95 * 10**-3
# b = 6.28 * 10**-2
# print("1: ", 5 / np.sqrt(a*R**2 + 1))
# print("2: ", np.arctan(b*R))

C = 1 * 10**-6
L = 13 * 10**-6
R = 220

print((np.sqrt(1/(L*C))/(2*np.pi)))