# Date : 2017.11.16
# Author : seungyeon choi
# 2294 (동전2)

N, K = map(int, input().split())
coin = []
DP = [12345 for _ in range(10001)]
DP[0] = 0
for _ in range(N):
    coin.append(int(input()))
for i in range(N):
    for j in range(coin[i], K+1):
        DP[j] = min(DP[j-coin[i]] + 1, DP[j])
print(-1 if DP[K] == 12345 else DP[K])
