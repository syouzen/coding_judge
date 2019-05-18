/* Date : 2019.5.18
 * Author : seungyeon choi
 * 2293 (동전1)
 */

#include <cstdio>

using namespace std;

const int MAX_COIN = 101;
const int MAX_COUNT = 10001;

int N, K, ans;
int COIN[MAX_COIN];
int DP[MAX_COUNT];

int main() {
  scanf("%d %d", &N, &K);

  for (int i = 0; i < N; i++)
    scanf("%d", &COIN[i + 1]);

  DP[0] = 1;

  for (int i = 1; i <= N; i++) {
    for (int j = COIN[i]; j <= K; j++) {
      if (j >= COIN[i])
        DP[j] += DP[j - COIN[i]];
    }
  }

  printf("%d\n", DP[K]);

  return 0;
}
