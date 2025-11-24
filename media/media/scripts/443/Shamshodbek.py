n = int(input())
v = []
for i in range(n):
    a, b, c = map(int, input().split())
    v.append([-a, -b, c, i + 1])
v.sort()
for i in v:
    print(i[3], end=' ')