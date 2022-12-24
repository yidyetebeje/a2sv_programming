class Solution:
    def sortArrayByParity(self, arr: List[int]) -> List[int]:
        pointer = 0
        for i in range(len(arr)):
            if arr[i] % 2 == 0:
                temp = arr[i]
                arr[i] = arr[pointer]
                arr[pointer] = temp
                pointer += 1
        return arr
