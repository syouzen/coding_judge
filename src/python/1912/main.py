# Date : 2017.11.12
# Author : seungyeon choi
# 1912 (연속합)

N = int(input())
S = list(map(int, input().split()))
DP = [0 for _ in range(N)]
DP[0] = S[0]
for i in range(1, N):
    DP[i] = max(DP[i-1] + S[i], S[i])
print (max(DP))
