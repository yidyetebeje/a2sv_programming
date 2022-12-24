class Solution:
    def checkIfExist(self, arr: List[int]) -> bool:
        dict = {}
        for i in range(len(arr)):
            dict[arr[i]] = i
        for i in range(len(arr)):
            double = arr[i] * 2
            if double in dict:
                if i != dict[double]:
                    return True

        return False
