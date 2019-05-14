# Date : 2017.11.24
# Author : seungyeon choi
# 1867 (돌멩이 제거)

ans = 0
N, K = map(int, input().split())
graph = [[] for _ in range(N)]
Achk = [-1 for _ in range(N)]
Bchk = [-1 for _ in range(N)]
for _ in range(K):
    A, B = map(int, input().split())
    graph[A-1].append(B-1)
def dfs(i):
    global visit
    if visit[i] : return False
    visit[i] = 1
    for j in range(len(graph[i])):
        temp = graph[i][j]
        if (Bchk[temp] == -1) or dfs(Bchk[temp]) :
            Achk[i] = temp
            Bchk[temp] = i
            return True
    return False
for j in range(N):
    visit = [0 for _ in range(N)]
    if dfs(j):
        ans += 1
print (ans)
