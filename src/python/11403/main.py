# Date : 2017.11.15
# Author : seungyeon choi
# 11403 (경로 찾기)

N = int(input())
adj = [list(map(int, input().split())) for _ in range(N)]
for k in range(N):
    for i in range(N):
        for j in range(N):
            if adj[i][k] and adj[k][j] :
                adj[i][j] = 1
for i in range(N):
    print (' '.join(map(str, adj[i])))
