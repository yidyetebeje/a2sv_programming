class Solution:
    def freqAlphabets(self, s: str) -> str:
        # mapping
        string = ""
        ascii = ord("a")
        i = 0
        while i < len(s):
            letter = ""
            if i + 2 < len(s):
                if (s[i + 2] == "#"):
                    number = int(s[i:(i+2)])
                    letter = chr(ord("a") + number - 1)
                    i += 3
                else:
                    letter = chr(ord("a") + int(s[i]) - 1)
                    i += 1
            else:
                letter = chr(ord("a") + int(s[i]) - 1)
                i += 1
            string += letter
        return string
