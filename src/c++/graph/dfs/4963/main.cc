/* Date : 2019.4.25
 * Author : seungyeon choi
 * 4963 (섬의 개수)
 */

#include <cstdio>

int graph[52][52];
int dx[8] = {1, -1, 0, 0, 1, 1, -1, -1};
int dy[8] = {0, 0, 1, -1, 1, -1, -1, 1};

void dfs(int i, int j) {
  graph[i][j] = 0;
  for (int k = 0; k < 8; k++)
    if (graph[i + dx[k]][j + dy[k]])
      dfs(i + dx[k], j + dy[k]);
}

int main() {
  int i, j, ans;

  while (1) {
    scanf("%d %d", &j, &i);
    if (!i && !j) break;

    for (int x = 1; x <= i; x++) 
      for (int y = 1; y <= j; y++) 
        scanf("%d", &graph[x][y]);

    ans = 0;

    for (int x = 1; x <= i; x++) {
      for (int y = 1; y <= j; y++) {
        if (graph[x][y]) {
          dfs(x, y);
          ans++;
        }
      }
    }

    printf("%d\n", ans);
  }

  return 0;
}
