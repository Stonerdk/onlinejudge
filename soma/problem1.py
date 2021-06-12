from collections import deque
T = int(input())
res = []

for t in range(T) :
    m, n = map(int, input().split())
    grid = [[] for _ in range(m)]
    visited = [[False for _ in range(n)] for _ in range(m)]
    soma = (0, 0)
    keyList = []
    for i in range(m):
        grid[i] = list(map(int, input().split()))
    
    for i in range(m):
        for j in range(n):
            if grid[i][j] == 3:
                soma = [i, j]
            if grid[i][j] == 4:
                keyList.append([i, j])

    q = deque([soma])
    key = False
    flag = 0

    while q:
        ipos, jpos = q.popleft()
        if grid[ipos][jpos] == 4:
            for keyI, keyJ in keyList:
                grid[keyI][keyJ] = 0
            visited = [[False for _ in range(n)] for _ in range(m)]
            key = True
            q.clear()
        if grid[ipos][jpos] == 2:
            if key == True:
                flag = 1
                break
        visited[ipos][jpos] = True
        for i, j in [(ipos + 1, jpos), (ipos - 1, jpos), (ipos, jpos - 1), (ipos, jpos + 1)]:
            if 0 <= i and i < m and 0 <= j and j < n and visited[i][j] == False and grid[i][j] != 1:
                q.append([i, j])
    res.append(flag)

for f in res:
    print(f)