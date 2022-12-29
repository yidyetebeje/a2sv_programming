class Solution:
    def findDuplicate(self, paths: List[str]) -> List[List[str]]:
        dict = {}
        for path in paths:
            li = path.split(" ")
            directory = li[0]
            for j in range(1, len(li)):
                sp = li[j].split("(")
                file = sp[0]
                content = sp[1][:-1]
                fullpath = directory + "/" + file
                if content not in dict:
                    dict[content] = [fullpath]
                else:
                    dict[content].append(fullpath)
        li = []
        for di in dict:
            if len(dict[di]) != 1:
                li.append(dict[di])
        return li
