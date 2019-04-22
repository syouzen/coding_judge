# Date : 2017.11.4
# Author : seungyeon choi
# 1463 (1로 만들기)

N = int(input())

DP = [0 for i in range(1000001)]
DP[1] = 0
DP[2] = 1
DP[3] = 1

for i in range(4, N+1):
    DP[i] = DP[i-1]+1
    if i % 2 == 0:
        temp = DP[int(i/2)]+1
        DP[i] = min(temp, DP[i-1]+1)
    if i % 3 == 0:
        temp = DP[int(i/3)]+1
        DP[i] = min(temp, DP[i-1]+1)

print(DP[N])
