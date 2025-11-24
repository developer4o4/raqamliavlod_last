def champ(a, b):
    d = max(b)
    c = 0
    for x in b:
        if x + a >= d:
            c += 1
    return c

a = int(input())
b = [int(input()) for _ in range(a)]
print(champ(a, b))
