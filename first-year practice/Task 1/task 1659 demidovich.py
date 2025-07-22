#1659
from sympy import symbols, integrate, sqrt

x = symbols('x')
integral = integrate(1 / (5*x - 2)**(5/2), x)
print(integral,"+ C")
