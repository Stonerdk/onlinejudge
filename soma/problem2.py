from collections import deque
N = int(input())
grid = list(map(int, input().split()))
parents = [0 for _ in range(N)]
for i in range(N):
    dest = i + grid[i]
    grid[i] = dest
    parents[dest] += 1
q = deque(list(filter(lambda x : parents[x] == 0, list(range(N)))))

while q:
    idx = q.popleft()
    parents[grid[idx]] -= 1
    if parents[grid[idx]] == 0:
        q.append(grid[idx])
visited = list(map(lambda x: x == 0, parents))
i, cnt, mxcnt = 0, 0, 0
while i < N:
    if visited[i] == True:
        i += 1
        continue
    visited[i], cnt = True, cnt += 1
    if visited[grid[i]] == True:
        mxcnt, cnt = max(mxcnt, cnt), 0
    else:
        i = grid[i]
print(mxcnt)

    

