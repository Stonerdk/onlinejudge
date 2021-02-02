from heapq import heappush, heappop

N, M = map(int, input().split())
INF = 1e9
graph = [[] for _ in range(N)]
for _ in range(M) :
    src, dest, dist = map(int, input().split())
    graph[src - 1].append((dest - 1, dist))
    graph[dest - 1].append((src - 1, dist))
P, Q = map(int, input().split())
P -= 1
Q -= 1

def dij(start):
    dp = [INF] * N
    dp[start] = 0
    bfs = []
    heappush(bfs, [start, 0])
    while(bfs):
        n, d = heappop(bfs)
        for nn, nd in graph[n]:
            nd += d
            if nd < dp[nn]:
                dp[nn] = nd
                heappush(bfs, [nn, nd])
    return dp

dijp = dij(P)
dijq = dij(Q)

sp = dijp[0]
pd = dijp[N-1]
sq = dijq[0]
qd = dijq[N-1]
pq = dijp[Q]
g = []
if sp < INF and pq < INF and qd < INF:
    g.append(sp + pq + qd)
if sq < INF and pq < INF and pd < INF:
    g.append(sq + pq + pd)
if not g:
    res = -1
else:
    res = min(g)
print(res)

