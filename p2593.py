from collections import deque
def getsol(a, b, c):
    A = a
    B = b
    sw = 1
    if a <= b:
        a, b = b, a
        A, B = B, A
        sw = -1
    px, x = 1, 0
    py, y = 0, 1
    while(1):
        r = a % b
        if r == 0:
            if c % b != 0:
                return -1
            x *= (c // b) * sw
            y *= -(c // b) * sw
            p = min(x // B, y // A)
            return (x - p * B, y - p * A)
            break
        q = a // b
        a, b = b, r
        px, x = x, px - x * q
        py, y = y, py - y * q

N, M = map(int, input().split())
ev = []
for i in range(M):
    ev.append(list(map(int, input().split())))
S, D = map(int, input().split())
nodes = [[] for _ in range(M + 2)]
for i in range(M):
    if S - ev[i][0] >= 0 and (S - ev[i][0]) % ev[i][1] == 0:
        nodes[M].append(i)
    if D - ev[i][0] >= 0 and (D - ev[i][1]) % ev[i][1] == 0:
        nodes[i].append(M+1)
for i in range(1, M):
    for j in range(i):
        sol = getsol(ev[i][1], ev[j][1], ev[j][0] - ev[i][0])
        if sol == -1:
            continue
        if ev[i][1] > ev[j][1]:
            u = ev[i][0] + sol[0] * ev[i][1]
        else:
            u = ev[j][0] + sol[0] * ev[i][1]
        if  u <= N:
            nodes[i].append(j)
            nodes[j].append(i)
que = deque()
que.append((M, []))
minlist = []
minlen = 100
flag = False
while que:
    u = que.popleft()
    if u[0] == M + 1:
        if len(u[1]) < minlen:
            minlen = len(u[1]) - 1
            minlist = u[1]
        flag = True
    for n in nodes[u[0]]:
        if u[0] not in u[1]:
            que.append((n, u[1] + [u[0]]))
if flag == False:
    print(-1)
else:
    print(minlen)
    for i in (1, minlen):
        print(minlist[i] + 1)
