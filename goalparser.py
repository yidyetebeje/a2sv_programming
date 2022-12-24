class Solution:
    def interpret(self, command: str) -> str:
        string = ""
        i = 0
        while i < len(command):
            if command[i] == 'G':
                string += command[i]
                i += 1
            else:
                temp = ""
                while command[i] != ')':
                    temp += command[i]
                    i += 1
                temp += ")"
                i += 1
                if temp == "()":
                    string += "o"
                elif temp == "(al)":
                    string += "al"
        return string
