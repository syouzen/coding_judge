/* Date : 2019.5.9
 * Author : seungyeon choi
 * 11376 (열혈강호2)
 */

#include <cstdio>
#include <vector>

using namespace std;

const int MAX = 1001;

int N, M;
bool adj[MAX][MAX];
vector<int> cow, house;
vector<int> visit;

bool dfs(int i) {
  if (visit[i] > 0) return false;
  visit[i]++;
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
    visit = vector<int>(N, -1);
    if (dfs(i))
      ans++;
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
