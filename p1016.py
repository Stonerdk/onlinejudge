from math import sqrt
from math import ceil
minv, maxv = map(int, input().split())
N = int(sqrt(maxv))

flt = [x for x in range(2, N + 1)]
psq = []

while(flt):
    dec = flt[0]
    psq.append(dec ** 2)
    flt = list(filter(lambda x: x % dec != 0, flt))
ans = maxv - minv + 1
siv = [0 for x in range(minv, maxv + 1)]
for k in psq:
    sn = ceil(minv / k)
    while(sn * k <= maxv):
        if siv[sn * k - minv] == 0:
            siv[sn * k - minv] = 1
            ans -= 1
        sn += 1
print(ans)