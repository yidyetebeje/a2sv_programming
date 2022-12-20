# Enter your code here. Read input from STDIN. Print output to STDOUT
words = []
n = int(input())
for i in range(n):
    words.append(input())
dict = {}
for word in words:
    if word in dict:
        dict[word] += 1
    else:
        dict[word] = 1
print(len(dict))
for key in dict:
    print(dict[key], end = " ")
