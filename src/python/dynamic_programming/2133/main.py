# Date : 2017.11.12
# Author : seungyeon choi
# 2133 (타일 채우기)

N = int(input())
DP = [0 for _ in range(31)]
DP[0], DP[2] = 1, 3
for i in range(4, N+1, 2):
    DP[i] += 3 * DP[i-2]
    for j in range(i-4, -1, -2):
        DP[i] += 2 * DP[j]
print (DP[N])
