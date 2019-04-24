# Date : 2017.11.6
# Author : seungyeon choi
# 2156 (포도주 시식)

N = int(input())
wine = [0 for _ in range(10001)]
DP = [0 for _ in range(10001)]
for i in range(1, N+1):
    wine[i] = int(input())

if N == 1: DP[1] = wine[1]
elif N == 2:
    DP[1] = wine[1]
    DP[2] = DP[1] + wine[2]
else :
    DP[1] = wine[1]
    DP[2] = DP[1] + wine[2]
    for i in range(3, N+1):
        DP[i] = max(wine[i]+DP[i-2], wine[i]+wine[i-1]+DP[i-3], DP[i-1])

print (DP[N])
