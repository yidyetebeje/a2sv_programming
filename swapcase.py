def swap_case(s):
    newS = ""
    for letter in s:
        if letter.islower():
            newS += letter.upper()
        else:
            newS += letter.lower()
    return newS

