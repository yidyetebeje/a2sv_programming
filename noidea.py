size = input();
sizeOfArray = int(size.split(" ")[0]);
sizeOfSet = int(size.split(" ")[1]);
arrayElements = input();
arrayElements = arrayElements.split(" ");
arrayElements = [int(i) for i in arrayElements];
A = input();
A = A.split(" ");
A = set([int(i) for i in A]);
B = input();
B = A.split(" ");
B = set([int(i) for i in B]);
happinessIndex = 0
for el in arrayElements:
    if el in A:
        happinessIndex += 1
    elif el in B:
        happinessIndex -= 1

        
        