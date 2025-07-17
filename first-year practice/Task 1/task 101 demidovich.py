def numerical_sequence_101(n_max=10**6):
    x_large = 1 - 1 / n_max
    inf_xn = 0  
    sup_xn = x_large  
    limit = x_large 
    limsup = limit
    return inf_xn, sup_xn, limit, limsup

inf, sup, limit, limsup = numerical_sequence_101()
print(f"inf x_n = {inf}, sup x_n ≈ {sup:.6f}, lim x_n ≈ {limit:.6f}, limsup x_n ≈ {limsup:.6f}")
