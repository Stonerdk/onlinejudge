from collections import defaultdict

def solution(tickets):
    vec = ["ICN"]
    dic = defaultdict(list)
    def dfs(d):
        d[1] = True
        vec.append(d[0])
        for nd in dic[d[0]]:
            if not nd[1]:
                if dfs(nd):
                    return True
        if len(vec) == len(tickets):
            return True
        vec.pop()
        d[1] = False
        return False
    for [src, dest] in tickets:
        dic[src] += [[dest, False]]
    for k in dic:
        dic[k].sort()
    for t in dic["ICN"]:
        if dfs(t):
            return vec