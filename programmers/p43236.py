def solution(distance, rocks, n):
    rocks.sort()
    intervals = [rocks[0]]
    mindp = []
    rocks.append(distance)
    for i in range(1, len(rocks)):
        intervals.append(rocks[i] - rocks[i - 1])
    for _ in range(n):
        mindp = [intervals[0]]
        for i in range(1, len(intervals)):
            mindp.append(min(mindp[i - 1], intervals[i]))
        start = 0
        end = len(mindp) - 1
        while(start != end):
            pivot = (start + end) // 2
            if mindp[pivot] == mindp[end]:
                end = pivot
            else:
                start = pivot + 1
        print(intervals)
        print(mindp)
        print(mindp[start])
        if start == len(mindp) - 1 or intervals[start + 1] >= intervals[start - 1]:
            intervals[start] += intervals[start - 1]
            intervals.pop(start - 1)
        else:
            intervals[start] += intervals[start + 1]
            intervals.pop(start + 1)

    mindp = [intervals[0]]
    for i in range(1, len(intervals)):
        mindp.append(min(mindp[i - 1], intervals[i]))
    return mindp[-1]
    
print(solution(15, [4, 9, 12, 14], 2))