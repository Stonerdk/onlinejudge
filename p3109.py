R, C = map(int, input().split())
grid = []
count = 0
for i in range(R):
    g = input()
    r = []
    for c in g:
        r.append(True if c == '.' else False)
    grid.append(r)

def drive(i, j):
    global count
    grid[i][j] = False
    if j == C - 1:
        count += 1
        return True
    if i > 0 and grid[i - 1][j + 1] == True:
        if drive(i - 1, j + 1):
            return True
    if grid[i][j + 1] == True:
        if drive(i, j + 1):
            return True
    if i < R - 1 and grid[i + 1][j + 1] == True:
        if drive(i + 1, j + 1):
            return True
    return False

for i in range(R):
    drive(i, 0)
print(count)