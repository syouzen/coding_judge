/* Date : 2019.5.10
 * Author : seungyeon choi
 * 5567 (결혼식)
 */

#include <cmath>
#include <cstdio>
#include <queue>

using namespace std;

const int MAX_FRIEND = 501;

int N, M;
int adj[MAX_FRIEND][MAX_FRIEND];
bool visit[MAX_FRIEND];

int bfs() {
  int x, f, ans = 0;
  queue<pair<int, int>> q;
  q.push(make_pair(x, f));

  while (!q.empty()) {
    x = q.front().first;
    f = q.front().second;
    q.pop();
    visit[x] = true;

    for (int i = 0; i < N; i++) {
      if (adj[x][i]) {
        if (!visit[i]) {
          visit[i] = true;
          q.push(make_pair(i, f + 1));
          if (f + 1 <= 2)
            ans += 1;
        }
      }
    }
  }

  return ans;
}

int main() {
  int num1, num2;
  scanf("%d", &N);
  scanf("%d", &M);
  for (int i = 0; i < M; i++) {
    scanf("%d %d", &num1, &num2);
    adj[num1 - 1][num2 - 1] = 1;
    adj[num2 - 1][num1 - 1] = 1;
  }
  printf("%d\n", bfs());
  return 0;
}
