import numpy as np
import math
import matplotlib.pyplot as plt

def B02(t):
    return (1-t)**2
def B12(t):
    return 2*t*(1-t)
def B22(t):
    return t**2

def rational_bezier_deg2(t,P,W):
    return (B02(t)*P[0]*W[0]+B12(t)*P[1]*W[1]+B22(t)*P[2]*W[2])/(B02(t)*W[0]+B12(t)*W[1]+B22(t)*W[2])
    
def rational_bezier_deg3(t,P,W):
    pass
    
def parametric_circle(t):
    return (1-t**2)/(1+t**2),(2*t)/(1+t**2)
    
#ref circle
t=np.arange(0,math.pi/2,0.01)
plt.plot(np.cos(t),np.sin(t),label='ref_circle')

#circle parametrization test
t=np.arange(0,1,0.01)
x,y=parametric_circle(t)
plt.plot(x,y,label='parametric_circle')
norm=np.sqrt(x**2+y**2)
print(f"max_norm={norm.max()} min_norm={norm.min()}")

#rational bezier fit test
px=[1,1,0]
py=[0,1,1]
w=[1,math.sqrt(2)/2,1]
x=rational_bezier_deg2(t,px,w)
y=rational_bezier_deg2(t,py,w)
plt.plot(x,y,label='rational_bezier_deg2')
norm=np.sqrt(x**2+y**2)
print(f"max_norm={norm.max()} min_norm={norm.min()}")

plt.grid()
plt.legend()
plt.show()
