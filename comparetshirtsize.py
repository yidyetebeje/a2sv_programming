queries = int(input())
for i in range(queries):
    size = input().split(" ")
    priority = {
      "M": 1,
      "L": 2,
      "S": 0
    }
    if size[0][-1] == size[1][-1]:
        if len(size[0]) > len(size[1]):
            if size[0][-1] == "L":
                print(">")
            else:
                print("<")
        elif len(size[0]) == len(size[1]):
            print("=")
        else:
             if size[0][-1] == "L":
                print("<")
             else:
                print(">")
    if priority[size[0][-1]] > priority[size[1][-1]]:
        print(">")
    elif priority[size[0][-1]] < priority[size[1][-1]]:
        print("<")
