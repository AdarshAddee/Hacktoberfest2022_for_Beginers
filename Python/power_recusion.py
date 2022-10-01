def power(base, exponent):
    if exponent == 0: return 1
    return base * power(base, exponent - 1)

b, e = list(map(int, input("Enter base and exponent : ").split()))
print(power(b, e))