# Date : 2017.11.24
# Author : seungyeon choi
# 1671 (상어의 저녁식사)

N = int(input())
ans = 0
v = 1
Achk = [-1 for _ in range(N)]
Bchk = [-1 for _ in range(N)]
visit = [0 for _ in range(N)]
Shark = []
for _ in range(N):
    A, B, C = map(int, input().split())
    Shark.append((A, B, C))
graph = [[] for _ in range(N)]
for i in range(N): 
    for j in range(N):
        if j == i : continue
        if i > j and Shark[i][0] == Shark[j][0] and Shark[i][1] == Shark[j][1] and Shark[i][2] == Shark[j][2] :
            continue
        if Shark[i][0] >= Shark[j][0] and Shark[i][1] >= Shark[j][1] and Shark[i][2] >= Shark[j][2] :
            graph[i].append(j)
def dfs(i):
    global visit, v
    if visit[i] == v : return False
    visit[i] = v
    for j in range(len(graph[i])):
        temp = graph[i][j]
        if (Bchk[temp] == -1) or dfs(Bchk[temp]) :
            Achk[i] = temp
            Bchk[temp] = i
            return True
    return False
for j in range(N):
    v += 1
    if dfs(j): ans += 1
    v += 1
    if dfs(j): ans += 1
print (N-ans)
