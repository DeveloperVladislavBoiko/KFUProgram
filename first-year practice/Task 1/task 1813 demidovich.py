#1813
from sympy import symbols, integrate, atan

x = symbols('x')
integral = integrate(x * atan(x)**2, x)
print(integral," +C")
