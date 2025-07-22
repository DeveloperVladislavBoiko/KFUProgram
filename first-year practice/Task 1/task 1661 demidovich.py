#1661
from sympy import symbols, integrate

x = symbols('x')
integral = integrate(1 / (2 + 3*x**2), x)
print(integral," +C")
