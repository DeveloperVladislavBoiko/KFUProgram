#1812
from sympy import symbols, integrate, asin

x = symbols('x')
integral = integrate(asin(x)**3, x)
print(integral," +C")
