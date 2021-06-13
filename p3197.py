from collections import deque
R, C = map(int, input().split())
swans = []
grid = []
for i in range(R):
    line = input()
    row = []
    for j, c in enumerate(line):
        row.append(0 if c == '.' or c == 'L' else 1e10)
        if c == 'L':
            swans.append((i, j))
    grid.append(row)

level = [[1e10 for _ in range(C)] for _ in range(R)]
visited = [[False for _ in range(C)] for _ in range(R)]
for i in range(R):
    level[i][0] = grid[i][0]
    for j in range(1, C):
        level[i][j] = min(level[i][j], level[i][j - 1] + 1, grid[i][j])
    for j in range(C - 2, 0, -1):
        level[i][j] = min(level[i][j], level[i][j + 1] + 1, grid[i][j])
for j in range(C):
    for i in range(1, R):
        level[i][j] = min(level[i][j], level[i - 1][j] + 1, grid[i][j])
    for i in range(R - 2, 0, -1):
        level[i][j] = min(level[i][j], level[i + 1][j] + 1, grid[i][j])
#O(4RC)

clev = 0
nq = [swans[0]]
q = deque()
flag = False
def appendcond(r, c):
    if r >= 0 and c >= 0 and r < R and c < C and not visited[r][c]:
        q.append((r, c))
while True:
    q = deque(nq)
    nq = []
    while q:
        r, c = q.popleft()
        #print(r, c)
        if level[r][c] > clev:
            nq.append((r, c))
        else:
            if swans[1] == (r, c):
                print(clev)
                flag = True
                break
            visited[r][c] = True
            appendcond(r + 1, c)
            appendcond(r - 1, c)
            appendcond(r, c + 1)
            appendcond(r, c - 1)
    if flag:
        break
    clev += 1
