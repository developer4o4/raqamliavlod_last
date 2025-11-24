ans = 0
for _ in range(int(input())):
  x = int(input())
  y = x % 10
  x //= 10
  ans += pow(x, y)
  assert(1 <= ans <= int(1e9))
print(ans)