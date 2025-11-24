a=int(input())
if a<38:
  print(a)
else:
    if int(str(a)[-1])>5:
        if 3<=int(str(a)[-1])-5:
            print(a+5-(int(str(a)[-1])-5))
        else:
            print(a)
    else:
        if 3<=int(str(a)[-1]):
            print(a+5-(int(str(a)[-1])))
        else:
            print(a)
