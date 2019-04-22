# Date : 2017.11.12
# Author : seungyeon choi
# 1904 (01타일)

N = int(input())
DP = [0 for _ in range(1000001)]
DP[1], DP[2] = 1, 2
for i in range(3, N+1):
    DP[i] = (DP[i-1] + DP[i-2])%15746
print (DP[N])
