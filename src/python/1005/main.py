# Date : 2017.11.22
# Author : seungyeon choi
# 1005 (ACM Craft)

import sys
for _ in range(int(sys.stdin.readline())):
    N, K = map(int, sys.stdin.readline().split())
    graph = [[] for _ in range(N)]
    vertex, result = [], []
    line = [0 for _ in range(N)]
    temp = list(map(int, sys.stdin.readline().split()))
    for i in range(N):
        vertex.append(temp[i])
        result.append(temp[i])
    for _ in range(K):
        x, y = map(int, sys.stdin.readline().split())
        graph[x-1].append(y-1)
        line[y-1] += 1
    q = []
    test = int(sys.stdin.readline())-1
    for i in range(N):
        if line[i] == 0 : q.append(i)
    for i in range(N):
        x = q.pop(0)
        f = 0
        for j in range(len(graph[x])):
            result[graph[x][j]] = max(result[graph[x][j]], result[x] + vertex[graph[x][j]])
            if line[graph[x][j]]:
                line[graph[x][j]] -= 1
                if line[graph[x][j]] == 0:
                    if test == graph[x][j]:
                        f = 1
                        break
                    q.append(graph[x][j])
        if f : break
    print(result[test])
