#1660
from sympy import symbols, integrate

x = symbols('x')
integral = integrate((1 - x)**(-3/5), x)
print(integral,"+ C")
