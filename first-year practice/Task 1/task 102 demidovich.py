#102
def numerical_sequence_102(n_max=10**6):
    n_even = n_max if n_max % 2 == 0 else n_max - 1
    n_odd = n_max if n_max % 2 != 0 else n_max - 1

    x_even = ((-1)**n_even)/n_even + (1 + (-1)**n_even)/2  
    x_odd = ((-1)**n_odd)/n_odd + (1 + (-1)**n_odd)/2

    inf_xn = min(0, x_odd)
    sup_xn = max(1, x_even)
    limit = 0.5
    limsup = 1
    liminf = 0

    return inf_xn, sup_xn, limit, limsup, liminf

inf, sup, limit, limsup, liminf = numerical_sequence_102()
print(f"inf x_n ≈ {inf:.6f}, sup x_n ≈ {sup:.6f}, lim x_n не существует, limsup x_n = {limsup}, liminf x_n = {liminf}")
