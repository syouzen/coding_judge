# Date : 2017.11.6
# Author : seungyeon choi
# 1507 (궁금한 민호)

N = int(input())
graph = [list(map(int,input().split())) for _ in range(N)]
check = [[1] * N for _ in range(N)]
ans = 0
for k in range(N):
    for i in range(N):
        for j in range(N):
            if i == j or j == k or i == k : continue
            if graph[i][j] == (graph[i][k] + graph[k][j]):
                check[i][j] = 0
            if graph[i][j] > (graph[i][k] + graph[k][j]):
                ans = -1
if ans != -1 :
    for i in range(N):
        for j in range(N):
            if check[i][j] :
                ans += graph[i][j]
    print (int(ans/2))
else :
    print (-1)
