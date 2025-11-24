import time

a = []
for i in range(1024 ** 16):
    a.append("a" * 1024)

time.sleep(10)

