class Solution:
    def flipgame(self, fronts: List[int], backs: List[int]) -> int:
        s = set()
        for i in range(len(fronts)):
            if fronts[i] == backs[i]:
                s.add(fronts[i])
        mi = 3000
        for k in range(len(fronts)):
            if fronts[k] not in s:
                mi = min(mi, fronts[k])
            if backs[k] not in s:
                mi = min(mi, backs[k])
        if mi == 3000:
            return 0
        return mi
        