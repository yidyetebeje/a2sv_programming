n = list(map(int,input().split()))
answer = n[0] + n[1] +  2*n[2]
if n[0] - n[1] == 0:
  print(answer)
else:
  print(answer - abs(n[0] - n[1]) + 1)