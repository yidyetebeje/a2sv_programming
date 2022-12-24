class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        prefix = strs[0]
        for str in strs:
            minSize = min(len(prefix), len(str))
            if str == "":
                return ""
            for i in range(minSize):
                if prefix[i] != str[i]:
                    prefix = prefix[0:i]
                    break
                if (i == (minSize - 1) and i < len(prefix)):
                    prefix = prefix[0:(i + 1)]
        return prefix
