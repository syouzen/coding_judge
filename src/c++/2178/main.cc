/* Date : 2019.4.29
 * Author : seungyeon choi
 * 2178 (미로 탐색)
 */

#include <cstdio>
#include <queue>

using namespace std;

int N, M;
int graph[100][100];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void bfs(int x, int y) {
  queue<pair<int, int>> q;
  q.push(make_pair(x, y));

  while (!q.empty()) {
    x = q.front().first;
    y = q.front().second;
    q.pop();

    for (int i = 0; i < 4; i++) {
      int nx = x + dx[i];
      int ny = y + dy[i];
      if (nx < 0 || nx > N - 1 || ny < 0 || ny > M - 1) continue;
      if (graph[nx][ny] == 1) {
        q.push(make_pair(nx, ny));
        graph[nx][ny] = graph[x][y] + 1;
      }
    }
  }
}

int main() {
  scanf("%d %d", &N, &M);
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      scanf("%1d", &graph[i][j]);
    }
  }

  graph[0][0] = 2;
  bfs(0, 0);

  printf("%d\n", graph[N - 1][M - 1] - 1);

  return 0;
}
