# Date : 2017.11.10
# Author : seungyeon choi
# 11376 (열혈강호2)

import sys
ans = 0
v = 1
N, M = map(int, sys.stdin.readline().split())
adj = [[] for _ in range(N)]
cow = [-1 for _ in range(N)]
house = [-1 for _ in range(M)]
visit = [0 for _ in range(N)]
for i in range(N):
    S =  list(map(int, sys.stdin.readline().split()))
    for j in range(1, len(S)):
        adj[i].append(S[j]-1)
for j in range(N):
    def dfs(i):
        global v
        if visit[i] == v : return False
        visit[i] = v
        for j in range(len(adj[i])):
            if house[adj[i][j]] == -1 or dfs(house[adj[i][j]]):
                cow[i] = adj[i][j]
                house[adj[i][j]] = i
                return True
        return False
    v += 1
    if dfs(j): ans += 1
    v += 1
    if dfs(j): ans += 1
print (ans)
