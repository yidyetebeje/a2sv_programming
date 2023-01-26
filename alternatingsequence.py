h = int(input())
for i in range(h):
    n = int(input())
    a = list(map(int, input().split()))
    s = 0
    flag = a[0] > 0
    r = 0
    while r < n:
        maxEl = float("-inf")
        while flag  and r < len(a):
            if(a[r] < 0):
                flag = False
                break
            maxEl = max(maxEl, a[r])
            r += 1
        if maxEl != float("-inf"):
            s += maxEl
        maxEl = float("-inf")
        while not flag and r < len(a):
            if a[r] > 0:
                flag = True
                break
            maxEl = max(maxEl, a[r])
            r += 1
        if maxEl != float("-inf"):
            s += maxEl
    print(s)
