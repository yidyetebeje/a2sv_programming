# Enter your code here. Read input from STDIN. Print output to STDOUT
nTest = int(input())
for i in range(nTest):
    n = int(input())
    arr = list(map(int, input().split(" ")))
    l, r = 0, n - 1
    top = max(arr[l], arr[r])

    found = True
    while l <= r:
        maxNum = max(arr[l], arr[r])
        if top >= maxNum:
            if arr[l] > arr[r]:
                top = arr[l]
                l += 1
            else:
                top = arr[r]
                r -= 1
        else:
            found = False
            print("No")
            break
    if found:
        print("Yes")
