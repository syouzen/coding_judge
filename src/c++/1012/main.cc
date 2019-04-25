/* Date : 2019.4.25
 * Author : seungyeon choi
 * 1012 (유기농 배추)
 */

#include <cstdio>

int graph[52][52];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int t, m, n, k, x, y, ans;

void dfs(int i, int j) {
  graph[i][j] = 0;
  for (int k = 0; k < 4; k++)
    if (graph[i + dx[k]][j + dy[k]])
      dfs(i + dx[k], j + dy[k]);
}

int main() {
  scanf("%d", &t);

  for (int i = 0; i < t; i++) {
    scanf("%d %d %d", &m, &n, &k);

    for (int j = 0; j < k; j++) {
      scanf("%d %d", &x, &y);
      graph[x + 1][y + 1] = 1;
    }

    ans = 0;

    for (int a = 1; a <= m; a++) {
      for (int b = 1; b <= n; b++) {
        if (graph[a][b]) {
          dfs(a, b);
          ans++;
        }
      }
    }

    printf("%d\n", ans);
  }

  return 0;
}
