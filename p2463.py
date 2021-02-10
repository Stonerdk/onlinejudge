N, M = map(int, input().split())

edges = []
for _ in range(M):
    edges.append(list(map(int, input().split())))
edges.sort(key = lambda x : x[2])

union = list(range(N))
rank = [1 for _ in range(N)]
setnum = [1 for _ in range(N)]

def find(u):
    if u == union[u]:
        return u
    union[u] = find(union[u])
    return union[u]

def merge(u, v):
    a, b = find(u), find(v)
    if a == b:
        return 0
    if (rank[a] < rank[b]):
        a, b = b, a
    union[b] = a
    ret = setnum[a] * setnum[b]
    setnum[a] += setnum[b]
    setnum[b] = 0
    if (rank[a] == rank[b]):
        rank[a] += 1
    return ret
cost = 0
sm = 0
for e in edges:
    sm += e[2]

while edges:
    e = edges.pop()
    ret = merge(e[0] - 1, e[1] - 1)
    cost = (cost + ret * sm) % 1000000000
    sm -= e[2]
print(cost) 