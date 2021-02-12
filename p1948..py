N = int(input())
vertices = [[] for _ in range(N)]
dp = [-1 for _ in range(N)]
latest_loads = set()

M = int(input())

def dfs(index):
    if dp[index] != -1:
        return dp[index]
    mxv = 0
    for t in vertices[index]:
        mxv = max(mxv, t[1] + dfs(t[0]))
    dp[index] = mxv
    return mxv
def dfs2(index):
    for t in vertices[index]:
        if dp[index] - dp[t[0]] == t[1]:
            flag =  t[0] in latest_loads
            latest_loads.add(t[0])
            if ~flag:
                dfs2(t[0])

for _ in range(M):
    src, dest, dist = map(int, input().split())
    vertices[dest - 1].append((src - 1, dist))
start, end = map(int, input().split())

dp[start - 1] = 0
print(dfs(end - 1))
dfs2(end - 1)
print(len(latest_loads) + 1)

