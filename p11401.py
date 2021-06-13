N, K = map(int, input().split())
nfp, mfp, MD = 1,1, 1000000007
def mult(a, b):
    return a * b % MD
def power(n, v):
    return n if v == 1 else mult(power(n, v // 2) ** 2, n if v % 2 == 1 else 1)
K = min(K, N - K)
for i in range(N - K + 1, N + 1):
    nfp = mult(nfp, i)
for i in range(1, K + 1):
    mfp = mult(mfp, i)
print(mult(nfp, power(mfp, MD - 2)))