# Enter your code here. Read input from STDIN. Print output to STDOUT
i, j = map(int , input().split())
groupA = []
for l in range(i):
    groupA.append(input())
groupB = []
for k in range(j):
    groupB.append(input())

for l in range(j):
    found = False
    for k in range(i):
        if (groupB[l] == groupA[k]):
            found = True
            print(k + 1, end= " ")
        
    if not found: print(-1)
    else: print()
