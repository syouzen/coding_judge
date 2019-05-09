/* Date : 2019.5.9
 * Author : seungyeon choi
 * 1671 (상어의 저녁식사)
 */

#include <cstdio>
#include <vector>

using namespace std;

struct shark {
  int size;
  int speed;
  int iq;
};

const int MAX = 51;

int N;
int v = 1;
bool adj[MAX][MAX];
vector<shark> shark_list;
vector<int> cow, house;
vector<int> visit;

bool dfs(int i) {
  if (visit[i] == v) return false;
  visit[i] = v;
  for (int j = 0; j < N; j++) {
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
  house = vector<int>(N, -1);
  visit = vector<int>(N, -1);
  int ans = 0;
  for (int i = 0; i < N; i++) {
    v++;
    if (dfs(i))
      ans++;
    v++;
    if (dfs(i))
      ans++;
  }
  return ans;
}

int main() {
  int SZ, SPD, IQ;
  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    scanf("%d %d %d", &SZ, &SPD, &IQ);
    shark_list.push_back({SZ, SPD, IQ});
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (i == j)
        continue;
      if (i > j &&
          shark_list[i].size == shark_list[j].size &&
          shark_list[i].speed == shark_list[j].speed &&
          shark_list[i].iq == shark_list[j].iq)
        continue;
      if (shark_list[i].size >= shark_list[j].size &&
          shark_list[i].speed >= shark_list[j].speed &&
          shark_list[i].iq >= shark_list[j].iq)
        adj[i][j] = true;
    }
  }

  printf("%d\n", N - bmatch());

  return 0;
}
