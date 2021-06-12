def solution(number, k):
    l = []
    u = 0
    for t in number:
        l.append(int(t))
    for _ in range(k):
        for i in range(u, len(l)):
            if i == len(l) - 1 or l[i] < l[i+1]:
                l.pop(i)
                u = min(i, len(l))
                break
    res = ""
    for k in l:
        res += str(k)
    return res
print(solution("1924",2))