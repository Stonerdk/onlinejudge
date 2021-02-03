from collections import deque
N = int(input())

def D(num):
    res = (num * 2) % 10000
    return res
def S(num):
    return (num + 9999) % 10000
def L(num):
    return num % 1000 * 10 + num // 1000
def R(num):
    return num % 10 * 1000 + num // 10

for _ in range(N):
    src, dest = map(int, input().split())
    q = deque()
    occ = [False for _ in range(10000)]

    q.append((src, ""))
    while q:
        num, res = q.popleft()
        #print((num, res))
        if num == dest:
            print(res)
            break
        if occ[num] == True:
            continue
        occ[num] = True
        
        q.append((D(num), res + "D"))
        q.append((S(num), res + "S"))
        q.append((L(num), res + "L"))
        q.append((R(num), res + "R"))
    
