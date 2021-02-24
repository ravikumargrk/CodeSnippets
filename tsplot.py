#%%
import CoolProp.CoolProp as CP
from matplotlib import pyplot as plt
import gif

# @gif.frame
def plotTs(domain,mix):
    [[Smin,Smax],[Tmin, Tmax]] = domain
    for Q in [0,1]:
        Tlst = []
        Slst = []
        # first plot Q=0
        N = 50
        for x in range(0,N,1):
            T = Tmin + (Tmax-Tmin)*(x/N)
            s = CP.PropsSI('S','T',T,'Q',Q,mix)
            Slst.append(s)
            Tlst.append(T)
        plt.plot(Slst,Tlst)
    plt.xlim((Smin, Smax))
    plt.ylim((Tmin, Tmax))
#%%
ref1 = 'R134a'
ref2 = 'Propane'
# Mass fraction of R134a : 0.95  102.03 g/mol
# mf1 = 0.95*102.03/(0.95*102.03+0.05*44.1)
# Mass fraction of propane: 0.05 44.1 g/mol
# mf2 = 0.05*44.1/(0.95*102.03+0.05*44.1)
mf1 = 0.977
mf2 = 0.023
mix = ref1+str([mf1])+'&'+ref2+str([mf2])
CP.PropsSI('D','T',300,'P',101325,mix)

plotTs([[0,2466],[122,368]],mix)
plt.savefig('plot.png')
#%%
# 1.	Create your own function file in python for the following:
# a.	To call the state points of pure and binary mixtures of refrigerants.
# b.	To plot the saturation curve for pure binary mixtures of refrigerants.

# 2.	Build a system simulation of heat pump software which is suitable for 2refrigerant mixtures, consisting of the following inputs:
# Inputs:
# Refrigerant 1: R134a
# Refrigerant 2: propane
# Mass fraction of R134a : 0.95
# Mass fraction of propane: 0.05

# Compressor discharge = 17.1 m3/hr
# Isentropic Efficiency of Compressor = 0.7
# Condenser Temperature = 333 K
# Evaporator Temperature = 283 K
# Superheat Temperature = 11 K
# Sub-cool Temperature = 8 K

# Outputs:
# COPHP
# Heating Capacity
# Work input to Compressor
# Mass flow rate of refrigerant

# Plot the saturation curve and on the saturation curve show the state points of the heat pump. Plot using matplotlib library. 
# Use tkinter library to create the GUI for the software . 

# Note: 
# 1.	While running the saturation curve function file, please run it 10K less than the critical t

