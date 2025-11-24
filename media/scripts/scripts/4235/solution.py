from random import randint
def gen():
  n = randint(1, 15)
  s = ""
  for _ in range(n):
    s += chr(randint(97, 122))
  return s

st = set()
a, b = map(int, input().split())
for _ in range(b):
  s = gen()
  while s in st:
    s = gen()
  print(s, end = " ")
  st.add(s)