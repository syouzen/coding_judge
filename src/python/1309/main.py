# Date : 2017.11.12
# Author : seungyeon choi
# 1309 (동물원)

N = int(input())
DP = [0 for _ in range(100001)]
DP[1], DP[2] = 3, 7
for i in range(3, N+1):
    DP[i] = (DP[i-1]*2 + DP[i-2]) % 9901
print (DP[N])
