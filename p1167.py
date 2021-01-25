import sys

sys.setrecursionlimit(20)   
N = int(input())
table = [[] for _ in range(N)]
mll = [None for _ in range(N)]
mxr = [None for _ in range(N)]
checked = [False for _ in range(N)]

def getmll(index):
    if mll[index] == None:
        checked[index] = True
        filtered = list(filter(lambda x : checked[x[0]] == False, table[index]))
        if not filtered:
            mll[index] = []
        else:
            mll[index] = list(map(lambda x: x[1] + dom(getmll(x[0])), filtered))
        checked[index] = False
    return mll[index]

def sumdom(ls):
    fst, sec = 0, 0
    for i in ls:
        if i > fst:
            sec, fst = fst, i
        elif i > sec:
            sec = i 
    return fst + sec

def dom(ls):
    if not ls:
        return 0
    return max(ls)

for i in range(N):
    tmp = list(map(int, input().split()))
    idx = tmp[0]
    for j in range(1, len(tmp) - 1, 2):
        table[idx - 1].append([tmp[j] - 1, tmp[j+1]])
getmll(1)
print(max(list(map(lambda x : sumdom(getmll(x)), range(N)))))