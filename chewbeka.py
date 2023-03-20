number = input()
stack = []
for i in range(len(number)):
  if int(number[0]) == 9 and i == 0:
      stack.append("9")
      continue
  if 9 - int(number[i]) >= int(number[i]):
      stack.append(number[i])
  else:
      stack.append(str(9 - int(number[i])))
j = ''.join(stack)
print(j)