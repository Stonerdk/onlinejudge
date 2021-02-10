import heapq

N = int(input())
paths = [list(map(int, input().split())) for _ in range(N)]
dist = int(input())
for r in paths:
    r.sort()
paths.sort(key = lambda x : x[1])
answer = 0
heap = []

for r in paths:
    while heap and heap[0][0] < r[1] - dist:
        heapq.heappop(heap)
    if r[0] >= r[1] - dist:
        heapq.heappush(heap, r)
    answer = max(answer, len(heap))
print(answer)