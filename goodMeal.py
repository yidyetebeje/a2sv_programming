class Solution:
    def countPairs(self,deliciousness) :
        numDict = {}
        for num in deliciousness :
            if num in numDict :
                numDict[num] += 1
            else :
                numDict[num] = 1
        count = 0
        for num in numDict :
            for i in range(22) :
                p2 = 2**i
                if p2 - num in numDict :
                    if p2 - num == num :
                        count += numDict[num] * (numDict[num] - 1)/2
                    else :
                        count += (numDict[num] * numDict[p2 - num])/2
                    
        return int(count % (10**9 + 7))
                    
