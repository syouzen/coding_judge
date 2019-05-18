# Date : 2017.11.11
# Author : seungyeon choi
# 2293 (동전1)

N, K = map(int, input().split())
coin = []
DP = [0 for _ in range(10001)]
DP[0] = 1
for _ in range(N):
    coin.append(int(input()))
for i in range(N):
    for j in range(coin[i], K+1, 1):
        DP[j] += DP[j-coin[i]]
print (DP[K])
