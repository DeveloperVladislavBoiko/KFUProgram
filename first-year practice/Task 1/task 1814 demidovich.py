#1814
from sympy import symbols, integrate, log

x = symbols('x')
integral = integrate(x**3 * log((1 - x)/(1 + x)), x)
print(integral," +C")
