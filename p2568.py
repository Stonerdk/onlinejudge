N = int(input())
P = []
B = []
for _ in range(N):
    a, b = map(int, input().split())
    P.append((a, b))
P.sort(key = lambda x : x[0])

def ins(key, start, end):
    pivot = (start + end) // 2
    maxv = B[pivot][-1][1]
    if start == end :
        if pivot == len(B) - 1 and key[1] > maxv:
            B.append(B[pivot] + [key])
        else:
            if pivot >= 1 :
                B[pivot] = B[pivot - 1] + [key]
            else:
                B[pivot] = [key]
        return
    if key[1] < maxv:
        ins(key, start, pivot)
    elif key[1] > maxv:
        ins(key, pivot + 1, end)

B.append([P[0]])
for i in range(1, N):
    ins(P[i], 0, len(B) - 1)

ftable = [x for x in P if x not in B[-1]]
print(len(ftable))
for f in ftable:
    print(f[0])
