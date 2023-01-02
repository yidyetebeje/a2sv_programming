q = int(input())
dicts = {}
for i in range(q):
    chorus = input().split()
    for words in chorus:
        st = ""
        word = ""
        for s in words:
            if s.isdigit():
                st = st + s
            else:
                word = word + s
        dicts[st] = word
    for i in range(1,len(chorus) + 1):
        if i != len(chorus):
            print(dicts[str(i)], end=" ")
        else:
            print(dicts[str(i)])
