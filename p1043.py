def line2list():
    return list(map(int, input().split()))
meeting_cnt = line2list()[1]

W = set(line2list()[1:])
P = []
for _ in range(meeting_cnt):
    P.append(set(line2list()[1:]))
A = [1 for _ in range(meeting_cnt)]

for _ in range(meeting_cnt):
    for i, p in enumerate(P):
        if W.intersection(p):
            W = W.union(p)
            A[i] = 0
print(sum(A))