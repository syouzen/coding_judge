# Date : 2017.11.8
# Author : seungyeon choi
# 2606 (바이러스)

N = int(input())
E = int(input())
edge = [list(map(int, input().split())) for _ in range(E)]
graph = [[0]*N for _ in range(N)]
visit = [0 for _ in range(N)]
ans = 0
for i in range(E):
    graph[edge[i][0]-1][edge[i][1]-1] = 1
    graph[edge[i][1]-1][edge[i][0]-1] = 1
def dfs(i):
    global ans
    visit[i] = 1
    for k in range(N):
        if not visit[k] and graph[i][k] :
            ans += 1
            dfs(k)
dfs(0)
print (ans)
