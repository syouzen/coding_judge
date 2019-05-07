/* Date : 2019.4.25
 * Author : seungyeon choi
 * 2667 (단지번호 붙이기)
 */

#include <algorithm>
#include <cstdio>

char graph[27][27];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int n, x, ans;
int ans2[27 * 27];

void dfs(int i, int j) {
  if (graph[i][j] != '1') return;

  graph[i][j] = '0';
  ans2[ans]++;

  for (int k = 0; k < 4; k++)
    dfs(i + dx[k], j + dy[k]);
}

int main() {
  scanf("%d", &n);

  for (int i = 1; i <= n; i++)
    scanf("%s", &graph[i][1]);

  for (int x = 1; x <= n; x++) {
    for (int y = 1; y <= n; y++) {
      if (graph[x][y] != '0') {
        dfs(x, y);
        ans++;
      }
    }
  }

  std::sort(ans2, ans2 + ans);
  printf("%d\n", ans);
  for (int i = 0; i < ans; i++)
    printf("%d\n", ans2[i]);

  return 0;
}
