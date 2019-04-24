# Date : 2017.11.6
# Author : seungyeon choi
# 2163 (초콜릿 자르기)

N, M = map(int, input().split())
DP = [[0]*(301) for i in range(301)]
for i in range(1, 301):
    DP[1][i] = i-1
for i in range(1, 301):
    DP[i][1] = i-1

DP[1][1] = 0
DP[2][1] = 1
DP[1][2] = 1
DP[2][2] = 3

for i in range(2, N+1):
    for j in range(2, M+1):
        DP[i][j] = max(DP[i][j], DP[i-1][j]+DP[1][j] + 1, DP[i][j-1]+DP[i][1] + 1)

print(DP[N][M])
