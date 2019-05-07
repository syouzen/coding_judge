# Date : 2017.11.16
# Author : seungyeon choi
# 1012 (유기농배추)

import sys
dx = [1, -1, 0, 0]
dy = [0, 0, 1, -1]
for _ in range(int(sys.stdin.readline())):
    ans = 0
    M, N, K = map(int, sys.stdin.readline().split());
    graph = [[0]*M for _ in range(N)]
    for _ in range(K):
        X, Y = map(int, sys.stdin.readline().split());
        graph[Y][X] = 1
    for i in range(N):
        for j in range(M):
            q = []
            if graph[i][j] :
                ans += 1
                q.append((i, j))
                while q :
                    x, y = q.pop(0)
                    graph[x][y] = 0
                    for k in range(4):
                        tx, ty = x + dx[k], y + dy[k]
                        if 0<=tx<N and 0<=ty<M and graph[tx][ty]:
                            q.append((tx, ty))
                            graph[tx][ty] = 0
    print (ans)
