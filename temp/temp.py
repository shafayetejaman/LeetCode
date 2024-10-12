from time import perf_counter

l = [1, 4, 2, 3, 5]
t = perf_counter()
print(l)
l[1:4] = sorted(l[1:4])
print(l)
t = (perf_counter() - t) * 1000
print(f"took {t}")
