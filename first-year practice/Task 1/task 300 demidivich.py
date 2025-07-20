import numpy as np
import matplotlib.pyplot as plt

x_left = np.linspace(-1, -0.001, 5000)
x_right = np.linspace(0.001, 1, 5000)
x = np.concatenate([x_left, x_right])
y = np.cos(np.pi / x)

plt.figure(figsize=(12, 8), dpi=100)
plt.plot(x, y, label='$y = \\cos\\left(\\frac{\\pi}{x}\\right)$',
         color='purple', linewidth=1, alpha=0.8)

plt.plot(0, 0, 'wo', markersize=8, markeredgecolor='red', markeredgewidth=1.5)
plt.annotate('Разрыв\n(0,0)', xy=(0.05, 0), xytext=(0.2, 0.8),
             arrowprops=dict(facecolor='black', arrowstyle='->'),
             fontsize=10, bbox=dict(boxstyle='round,pad=0.5', fc='white', alpha=0.8))

plt.title('График функции с бесконечными осцилляциями\n$y = \\cos\\left(\\frac{\\pi}{x}\\right)$',
          fontsize=14, pad=20)
plt.xlabel('Ось X', fontsize=12, labelpad=10)
plt.ylabel('Ось Y', fontsize=12, labelpad=10)
plt.legend(fontsize=12, loc='upper right')
plt.grid(True, linestyle='--', alpha=0.7)
plt.ylim(-1.1, 1.1)

plt.tight_layout()
plt.savefig('300.png', dpi=300, bbox_inches='tight')
plt.show()
