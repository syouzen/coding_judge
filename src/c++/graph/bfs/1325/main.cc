/* Date : 2019.5.10
 * Author : seungyeon choi
 * 1325 (효율적인 해킹)
 */

#include <algorithm>
#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

const int MAX_COUNT = 10001;

int N, M;
vector<int> adj[MAX_COUNT];
vector<int> hak_list;
vector<bool> ans, visit;

void bfs() {
  int x;
  queue<int> q;

  for (int i = 0; i < N; i++) {
    int hak = 0;
    q.push(i);

    visit = vector<bool>(N, false);

    while (!q.empty()) {
      x = q.front();
      q.pop();

      visit[x] = true;

      for (int j = 0; j < adj[x].size(); j++) {
        if (!visit[adj[x][j]]) {
          visit[adj[x][j]] = true;
          q.push(adj[x][j]);
          hak += 1;
        }
      }
    }

    hak_list[i] = hak;
  }
}

int main() {
  int num1, num2, max;
  scanf("%d %d", &N, &M);
  for (int i = 0; i < M; i++) {
    scanf("%d %d", &num1, &num2);
    adj[num2 - 1].push_back(num1 - 1);
  }

  ans = vector<bool>(N, false);
  hak_list = vector<int>(N, -1);
  bfs();

  max = *max_element(hak_list.begin(), hak_list.end());
  for (int i = 0; i < N; i++) {
    if (hak_list[i] == max)
      ans[i] = 1;
  }

  for (int i = 0; i < N; i++) {
    if (ans[i])
      printf("%d\n", i + 1);
  }

  return 0;
}
