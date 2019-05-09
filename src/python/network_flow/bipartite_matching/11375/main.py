# Date : 2017.11.10
# Author : seungyeon choi
# 11375 (열혈강호)

ans = 0
N, M = map(int, input().split())
adj = [[] for _ in range(N)]
cow = [-1 for _ in range(N)]
house = [-1 for _ in range(M)]
for i in range(N):
    S =  list(map(int, input().split()))
    for j in range(1, len(S)):
        adj[i].append(S[j]-1)
for j in range(N):
    visit = [0 for _ in range(N)]
    def dfs(i):
        if visit[i] :
            return False
        visit[i] = 1
        for j in range(len(adj[i])):
            if house[adj[i][j]] == -1 or dfs(house[adj[i][j]]):
                cow[i] = adj[i][j]
                house[adj[i][j]] = i
                return True
        return False
    if dfs(j):
        ans += 1
print (ans)
