/* Date : 2019.5.10
 * Author : seungyeon choi
 * 1867 (돌멩이 제거)
 */

#include <cstdio>
#include <vector>

using namespace std;

const int MAX_COUNT = 501;

int N, K;
int adj[MAX_COUNT][MAX_COUNT];
vector<int> Achk, Bchk;
vector<bool> visit;

bool dfs(int i) {
  if (visit[i]) return false;
  visit[i] = true;
  for (int j = 0; j < N; j++) {
    if (adj[i][j]) {
      if (Bchk[j] == -1 || dfs(Bchk[j])) {
        Achk[i] = j;
        Bchk[j] = i;
        return true;
      }
    }
  }
  return false;
}

int bmatch() {
  Achk = vector<int>(N, -1);
  Bchk = vector<int>(N, -1);
  int ans = 0;
  for (int i = 0; i < N; i++) {
    visit = vector<bool>(N, false);
    if (dfs(i))
      ans++;
  }
  return ans;
}

int main() {
  int num1, num2;
  scanf("%d %d", &N, &K);
  for (int i = 0; i < K; i++) {
    scanf("%d %d", &num1, &num2);
    adj[num1 - 1][num2 - 1] = 1;
  }
  printf("%d\n", bmatch());
  return 0;
}
