if __name__ == '__main__':
    N = int(input())
    li = []
    for i in range(N):
        command = input().split(" ")
        if command[0] in "insert":
            li.insert(int(command[1]), int(command[2]))
        elif command[0] in "remove":
            li.remove(int(command[1]))
        elif command[0] in "append":
            li.append(int(command[1]))
        elif command[0] in "sort":
            li.sort()
        elif command[0] in "reverse":
            li.reverse()
        elif command[0] in "pop":
            li.pop()
        elif command[0] in "print":
            print(li)
