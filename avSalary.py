class Solution:
    def average(self, salary: List[int]) -> float:
        max = salary[0]
        min = salary[0]
        sum = 0
        for el in salary:
            sum += el
            if(el > max):
                max = el
            if(el < min):
                min = el
            
        sum = sum - (min + max)
        avg = sum/(len(salary) - 2)
        return avg
