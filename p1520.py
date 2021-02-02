import sys
sys.setrecursionlimit(100000000)

N, M = map(int, input().split())

grid = [[] for _ in range(N)]
dp = [[-1 for _ in range(M)] for _ in range(N)]
for i in range(N):
    grid[i] = list(map(int, input().split()))

def getH(i, j):
    if i >= 0 and i < N and j >= 0 and j < M:
        return grid[i][j]
    return 0

def getDP(i, j):
    if dp[i][j] != -1:
        return dp[i][j]
    h = getH(i, j)
    sm = 0
    if getH(i - 1, j) > h:
        sm += getDP(i - 1, j)
    if getH(i + 1, j) > h:
        sm += getDP(i + 1, j)
    if getH(i, j - 1) > h:
        sm += getDP(i, j - 1)
    if getH(i, j + 1)  > h:
        sm += getDP(i, j + 1)
    dp[i][j] = sm
    return sm
dp[0][0] = 1
print(getDP(N - 1, M - 1))
    