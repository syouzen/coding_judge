/* Date : 2019.5.18
 * Author : seungyeon choi
 * 2294 (동전2)
 */

#include <algorithm>
#include <cstdio>

using namespace std;

const int MAX_COIN = 101;
const int MAX_COUNT = 10001;

int N, K;
int COIN[MAX_COIN];
int DP[MAX_COUNT];

int main() {
  scanf("%d %d", &N, &K);

  DP[0] = 0;
  for (int i = 1; i <= K; i++)
    DP[i] = 10001;

  for (int i = 1; i <= N; i++) {
    scanf("%d", &COIN[i]);
    for (int j = COIN[i]; j <= K; j++) {
      DP[j] = min(DP[j - COIN[i]] + 1, DP[j]);
    }
  }

  printf("%d\n", (DP[K] == 10001) ? -1 : DP[K]);

  return 0;
}
