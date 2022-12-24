class Solution:
    def findTheDifference(self, s: str, t: str) -> str:
        dict = {}
        # initialize dict
        for letter in s:
            dict.get(letter, 0) + 1
        # iterate through the t string and check it letter exist in dict
        for letter in t:
            if letter in dict:
                dict[letter] -= 1
                dict.pop(letter)
            else:
                return letter