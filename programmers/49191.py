def solution(s):
    n = len(s)
    mk, mi = 0, 0
    for i in range(n):
        k = 0
        while i - k >= 0 and i + k < n and s[i - k] == s[i + k]:
            k += 1
        if k > mk:
            mk, mi = k, i
    return s[(mi - mk + 1):(mi + mk)]
print(solution("abcdcba"))
print(solution("abcba"))
print(solution("abcdefg"))