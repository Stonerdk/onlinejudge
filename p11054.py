N = int(input())
arr = list(map(int, input().split()))

dpi = [0 for i in range(N)]
dpd = [0 for i in range(N)]

for i in range(N):
    for j in range(i):
        if arr[i] > arr[j] and dpi[i] < dpi[j]:
            dpi[i] = dpi[j]
    dpi[i] += 1
for i in range(N-1, -1, -1) :
    for j in range(N - 1, i, -1) :
        if arr[i] > arr[j] and dpd[i] < dpd[j]:
            dpd[i] = dpd[j]
    dpd[i] += 1

for i in range(N):
    dpi[i] += dpd[i]
print(max(dpi) - 1)
