#1811
from sympy import symbols, integrate, exp

x = symbols('x')
integral = integrate(x**3 * exp(x**2), x)
print(integral," +C")
