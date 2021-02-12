N = int(input())
grid = [[0 for _ in range(N)] for _ in range(N)]
for i in range(N):
    grid[i] = list(map(int, input().split()))
tornado = [(0, 1, 7), (0, -1, 7), (2, 0, 5), (-1, 1, 1), (-1, -1, 1), (1, 1, 10), (1, -1, 10), (0, 2, 2), (0, -2, 2), (1, 0, -1)]
DOWN = (False, True)
UP = (False, False)
LEFT = (True, False)
RIGHT = (True, True)
pos = (N // 2, N // 2)
lamount = 0
def getDirection(p):
    if p[0] > p[1]:
        return DOWN if p[0] + p[1] < N - 1 else RIGHT
    return LEFT if p[0] + p[1] <= N - 1 else UP


def isValid(pos):
    x, y = pos
    return x >= 0 and y >= 0 and x < N and y < N

def drive(current, direction):
    px, py = current
    global lamount
    value = grid[px][py]
    grid[px][py] = 0
    plus = value
    for dx, dy, amount in tornado:
        if not direction[1]:
            dx = -dx
        if direction[0]:
            dx, dy = dy, dx
        if amount == -1:
            gain = plus
        else:
            gain = value * amount // 100
        if isValid((px + dx, py + dy)):
            grid[px + dx][py + dy] += gain
        else:
            lamount += gain
        plus -= gain

def getPos(pos, direction):
    delta = 1 if direction[1] else -1
    if not direction[0]:
        return (pos[0] + delta, pos[1])
    else:
        return (pos[0], pos[1] + delta)
    
while True:
    d = getDirection(pos)
    pos = getPos(pos, d)
    if not isValid(pos):
        break
    drive(pos, d)
print(lamount)
