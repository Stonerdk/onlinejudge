N, M, X = map(int, input().split())
X -= 1
MAX = 10000000
dist = [[MAX for _ in range(N)] for _ in range(N)]
for _ in range(M):
    src, dest, dis = map(int, input().split())
    dist[src - 1][dest - 1] = dis

for i in range(N):
    dist[i][i] = 0

for j in range(N):
    for i in range(N):
        if dist[i][j] != MAX:
            for k in range(N):
                dist[k][i] = min(dist[k][i], dist[k][j] + dist[j][i])
ret = 0
for i in range(N):
    ret = max(ret, dist[i][X] + dist[X][i])
print(ret)