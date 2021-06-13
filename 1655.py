import heapq
class heap:
    def __init__(self, ascending = True):
        self.queue = []
        self.ascending = 1 if ascending else -1
    def push(self, value):
        heapq.heappush(self.queue, value * self.ascending)
    def top(self):
        return self.queue[0] * self.ascending
    def pop(self):
        return heapq.heappop(self.queue) * self.ascending
    def size(self):
        return len(self.queue)

N = int(input())
L, R = heap(False), heap()
sol = []
for i in range(N):
    x = int(input())
    if i % 2 == 0:
        if i == 0 or x < R.top():
            L.push(x)
        else:
            L.push(R.pop())
            R.push(x)
    else:
        if x < L.top():
            R.push(L.pop())
            L.push(x)
        else:
            R.push(x)
    print("loop", i, "value : ", x)
    print(L.queue)
    print(R.queue)
    sol.append(L.top())
for s in sol:
    print(s)