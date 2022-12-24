# Enter your code here. Read input from STDIN. Print output to STDOUT
k = input()
roomNo = input().split()
dict = {}
for room in roomNo:
    if room in dict:
        dict[room] += 1
    else:
        dict[room] = 1
for key in dict:
    if dict[key] == 1:
        print(int(key))
