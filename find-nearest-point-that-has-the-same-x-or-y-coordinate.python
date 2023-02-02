class Solution:
    def nearestValidPoint(self, x: int, y: int, points: List[List[int]]) -> int:
        validPoint = -1
        minDis = float('inf')
        for i in range(len(points)):
            if points[i][0] == x or points[i][1] == y:
                distance = abs(x - points[i][0]) + abs(y - points[i][1])
                if distance < minDis:
                    minDis = distance
                    validPoint = i
        return validPoint