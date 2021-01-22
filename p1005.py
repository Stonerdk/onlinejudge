from collections import deque 

class Node:
    def __init__(self, time):
        self.time = time
        self.dest = []
        self.indeg = 0
        self.dp = 0
    def add(self, node):
        self.dest.append(node)

T = int(input())
nodes = []
ans = []

for _ in range(T):
    N, K = map(int, input().split())
    nodes = list(map(lambda u : Node(int(u)), input().split()))
    for k in range(K):
        src, dest = list(map(lambda u : int(u) - 1, input().split()))
        nodes[src].add(nodes[dest])
        nodes[dest].indeg += 1
    q = deque()
    for i in range(N):
        if nodes[i].indeg == 0:
            q.append(nodes[i])
            nodes[i].dp = nodes[i].time
    while q:
        a = q.popleft()
        for n in a.dest:
            n.indeg -= 1
            n.dp = max(a.dp + n.time, n.dp)
            if n.indeg == 0:
                q.append(n)
    goal = int(input()) - 1
    ans.append(nodes[goal].dp)
for a in ans :
    print(a)