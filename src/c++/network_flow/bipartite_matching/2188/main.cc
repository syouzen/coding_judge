/* Date : 2019.5.1
 * Author : seungyeon choi
 * 2188 (축사배정)
 */

#include <cstdio>
#include <vector>

using namespace std;

const int MAX = 201;

int N, M;
bool adj[MAX][MAX];
vector<int> cow, house;
vector<bool> visit;

bool dfs(int i) {
  if (visit[i]) return false;
  visit[i] = true;
  for (int j = 0; j < M; j++) {
    if (adj[i][j]) {
      if (house[j] == -1 || dfs(house[j])) {
        cow[i] = j;
        house[j] = i;
        return true;
      }
    }
  }
  return false;
}

int bmatch() {
  cow = vector<int>(N, -1);
  house = vector<int>(M, -1);
  int ans = 0;
  for (int i = 0; i < N; i++) {
    visit = vector<bool>(N, false);
    if (dfs(i))
      ans++;
  }
  return ans;
}

int main() {
  int num, num2 = 0;
  scanf("%d %d", &N, &M);
  for (int i = 0; i < N; i++) {
    scanf("%d", &num);
    for (int j = 0; j < num; j++) {
      scanf("%d", &num2);
      adj[i][num2 - 1] = true;
    }
  }

  printf("%d\n", bmatch());

  return 0;
}
