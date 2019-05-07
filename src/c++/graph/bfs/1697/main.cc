/* Date : 2019.4.29
 * Author : seungyeon choi
 * 1697 (숨바꼭질)
 */

#include <cmath>
#include <cstdio>
#include <queue>

using namespace std;

int N, K;
int graph[100001] = {0, };

int bfs() {
  int x, ans;
  queue<pair<int, int>> q;
  q.push(make_pair(N, 0));

  while (!q.empty()) {
    x = q.front().first;
    ans = q.front().second;
    q.pop();

    if (x < 0 || x > 100000) continue;
    if (graph[x]) continue;
    graph[x] = 1;

    if (x == K) return ans;

    q.push(make_pair(x + 1, ans + 1));
    q.push(make_pair(x - 1, ans + 1));
    q.push(make_pair(x * 2, ans + 1));
  }
}

int main() {
  scanf("%d %d", &N, &K);
  printf("%d\n", bfs());
  return 0;
}
