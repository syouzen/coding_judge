# Date : 2017.11.6
# Author : seungyeon choi
# 4963 (섬의 개수)

dx = [1, 0, -1, 0, 1, 1, -1, -1]
dy = [0, 1, 0, -1, 1, -1, -1, 1]

while True :
    w, h = map(int, input().split())
    if not w and not h :
        break
    graph = [list(map(int,input().split())) for _ in range(h)]
    def bfs(i, j):
        q = [(i, j)]
        while q :
            x, y = q.pop(0)
            for i in range(8):
                tx = dx[i] + x
                ty = dy[i] + y
                if 0 <= tx and tx < h and 0 <= ty and ty < w and graph[tx][ty] :
                    q.append((tx, ty))
                    graph[tx][ty] = 0
    ans = 0
    for i in range(h):
        for j in range(w):
            if graph[i][j] :
                bfs(i, j)
                ans += 1
    print (ans)
