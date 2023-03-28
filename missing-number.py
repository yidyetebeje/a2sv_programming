class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        dict = {}
        for i in range(len(nums)):
            dict[nums[i]] = 1
        for i in range(len(nums)):
            if i not in dict:
                return i
        return len(nums)