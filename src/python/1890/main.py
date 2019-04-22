# Date : 2017.11.12
# Author : seungyeon choi
# 1890 (점프)

N = int(input())
graph = [list(map(int, input().split())) for _ in range(N)]
DP = [[0]*N for _ in range(N)]
DP[0][0] = 1
for i in range(N):
    for j in range(N):
        if i == N-1 and j == N-1: continue
        if i+graph[i][j] < N :
            DP[i+graph[i][j]][j] += DP[i][j]
        if j+graph[i][j] < N :
            DP[i][j+graph[i][j]] += DP[i][j]
print(DP[N-1][N-1])
