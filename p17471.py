from collections import deque
N = int(input())
R = range(N)
vertices = list(map(int, input().split()))
allsum = sum(vertices)
edges = []
minsum = 10000
checked = [False for _ in R]
table = [False for _ in R]

def track(index, val, s):
    global minsum, checked
    table[index] = val
    ns = s
    if val:
        s += vertices[index]
    if index == N - 1:
        if ns == allsum:
            return
        q = deque([0, table.index(False)])
        checked = [False for _ in R]
        while q:
            idx = q.popleft()
            checked[idx] = True
            for k in edges[idx]:
                if table[k] == table[idx] and not checked[k]:
                    q.append(k)
        if False not in checked:
            minsum = min(minsum, abs(allsum - ns - ns))
        return
    track(index + 1, True, ns)
    track(index + 1, False, ns)

for _ in R:
    tmp = list(map(lambda x : int(x) - 1, input().split()))
    edges.append(tmp[1:])
track(0, True, 0)
print(minsum if minsum != 10000 else -1)