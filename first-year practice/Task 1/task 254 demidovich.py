#254
import numpy as np
import matplotlib.pyplot as plt

x = np.linspace(-5, 5, 1000)
y = x**2 + 1/x

x = x[np.abs(x) > 0.05]
y = x**2 + 1/x

plt.figure(figsize=(10, 6))
plt.plot(x, y, label='$y = x^2 + \\frac{1}{x}$', color='blue')
plt.axvline(x=0, color='red', linestyle='--', label='Точка разрыва (x=0)')

plt.xlabel('Ось x', fontsize=12)
plt.ylabel('Ось y', fontsize=12)
plt.title('Трезубец Ньютона', fontsize=14)
plt.legend()
plt.grid(True)
plt.gca().set_aspect('auto')
plt.tight_layout()
plt.savefig('254.png', dpi=300)
plt.show()
