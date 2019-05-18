/* Date : 2019.5.18
 * Author : seungyeon choi
 * 11047 (동전0)
 */

#include <cstdio>

using namespace std;

const int MAX_COUNT = 11;

int N, K, ans;
int COIN[MAX_COUNT];

int main() {
  scanf("%d %d", &N, &K);

  for (int i = 0; i < N; i++)
    scanf("%d", &COIN[i + 1]);

  while (K) {
    for (int i = N; i > 0; i--) {
      if (COIN[i] <= K) {
        ans += (K / COIN[i]);
        K = (K % COIN[i]);
      }
    }
  }

  printf("%d\n", ans);

  return 0;
}
