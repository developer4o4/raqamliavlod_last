dig = [0, 3, 3, 3, 3, 3, 4, 3, 4]

def f(c):
  pos = ord(c) - ord('a') + 1
  ind = 0
  while pos > 0:
    pos -= dig[ind]
    ind += 1
  return str(ind)

a = []

for _ in range(int(input())):
  s = input()
  t = ""
  for c in s:
    t += f(c)
  a.append(t)

dig = [0, 3, 3, 3, 3, 3, 4, 3, 4]

def f(c):
  pos = ord(c) - ord('a') + 1
  ind = 0
  while pos > 0:
    pos -= dig[ind]
    ind += 1
  return str(ind)

a = []

for _ in range(int(input())):
  s = input()
  t = ""
  for c in s:
    t += f(c)
  a.append(t)

print(a.count(input()))