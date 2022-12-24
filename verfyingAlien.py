class Solution:
    def isAlienSorted(self, words: List[str], order: str) -> bool:
        # create a dictionary to map the order
        dict = {}
        for i in range(len(order)):
            dict[order[i]] = i
        # iterate through the words
        for i in range(len(words) - 1):
            word1 = words[i]
            word2 = words[i + 1]
            # iterate through the words
            j = 0
            while j < len(word1) and j < len(word2):
                if dict[word1[j]] > dict[word2[j]]:
                    return False
                elif dict[word1[j]] < dict[word2[j]]:
                    break
                j += 1
            if j == len(word2) and len(word1) > len(word2):
                return False
        return True