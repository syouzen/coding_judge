# Date : 2017.11.15
# Author : seungyeon choi
# 5567 (결혼식)

N = int(input())
M = int(input())
adj = [[] for _ in range(N)]
for _ in range(M):
    A, B = map(int, input().split())
    adj[A-1].append(B-1)
    adj[B-1].append(A-1)
ans = 0
q = []
visit = [0 for _ in range(N)]
q.append((0, 0))
while q :
    x, w = q.pop(0)
    visit[x] = 1
    for j in range(len(adj[x])):
        temp = adj[x][j]
        if not visit[temp] :
            visit[temp] = 1
            q.append((temp, w+1))
            if w+1 <= 2:
                ans += 1
print (ans)
