inp = list(map(int, input().split()))
student = inp[0]
q = inp[1]
ans = []
maxmark = 0
for i in range(student):
  ans.append(input())
answers = list(map(int,input().split()))
for i in range(q):
  dicts = {}
  for j in range(len(ans)):
    dicts[ans[j][i]] = dicts.get(ans[j][i], 0) + 1
  maxN = dicts[max(dicts, key=dicts.get)]
  maxmark += maxN * answers[i]
  
print(maxmark)
