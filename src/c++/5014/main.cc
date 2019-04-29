/* Date : 2019.4.29
 * Author : seungyeon choi
 * 5014 (스타트링크)
 */

#include <cstdio>
#include <queue>

using namespace std;

int F, S, G, U, D;
int graph[1000001] = {0, };

int bfs() {
  int x, ans;
  queue<pair<int, int>> q;
  q.push(make_pair(S, 0));

  while (!q.empty()) {
    x = q.front().first;
    ans = q.front().second;
    q.pop();

    if (x <= 0 || x > F) continue;
    if (graph[x]) continue;
    graph[x] = ans;

    q.push(make_pair(x + U, ans + 1));
    q.push(make_pair(x - D, ans + 1));
  }
}

int main() {
  scanf("%d %d %d %d %d", &F, &S, &G, &U, &D);
  if (S == G) {
    printf("0\n");
  } else {
    graph[0] = 1;
    bfs();
    if (graph[G]) printf("%d\n", graph[G]);
    else printf("use the stairs\n");
  }
  return 0;
}
