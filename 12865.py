N, M = map(int, input().split())
wv = [list(map(int, input().split())) for _ in range(N)]
dp = [[0 for _ in range(M + 1)] for _ in range(N + 1)]
for i, (w, v) in enumerate(wv):
    for j in range(M + 1):
        if j >= w:
            dp[i + 1][j] = max(dp[i][j], dp[i][j - w] + v)
        else:
            dp[i + 1][j] = dp[i][j]
print(dp[N][M])