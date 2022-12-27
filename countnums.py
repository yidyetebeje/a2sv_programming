class Solution:
    def isSimilar(self,word1, word2):
        dict1 = {}
        dict2 = {}
        for i in range(len(word1)):
            dict1[word1[i]] = 1
        for i in range(len(word2)):
            dict2[word2[i]] = 1
        return dict1 == dict2
    def similarPairs(self, words: List[str]) -> int:
        count = 0
        for i in range(len(words)):
            for j in range(i+1,len(words)):
                if self.isSimilar(words[i], words[j]):
                    count += 1
        return count
