grid = [[] for _ in range(9)]
blank = []
initialmask = []
for i in range(9):
    grid[i] = list(map(int, input().split()))

for i in range(9):
    for j in range(9):
        if grid[i][j] == 0:
            blank.append((i, j))
            tm = [True for _ in range(10)]
            for k in range(9):
                tm[grid[i][k]] = False
                tm[grid[k][j]] = False
            for k in range(i // 3 * 3, i // 3 * 3 + 3):
                for l in range(j // 3 * 3, j // 3 * 3 + 3):
                    tm[grid[k][l]] = False
            initialmask.append(tm)

def bt(index):
    if index == len(blank):
        for i in range(9):
            print(*grid[i])
        return
    x, y = blank[index]
    mk = initialmask[index].copy()
    for i in range(index):
        bx, by = blank[i]
        if bx == x or by == y or (bx // 3 == x // 3 and by // 3 == y // 3):
            mk[grid[bx][by]] = False

    for m in range(1, 10):
        if mk[m] == True:
            grid[x][y] = m
            bt(index + 1)
            grid[x][y] = 0

bt(0)
