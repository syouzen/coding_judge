/* Date : 2019.5.24
 * Author : seungyeon choi
 * 11057 (오르막 수)
 */

#include <cstdio>

const int MAX_COUNT = 1001;
const int DIVISOR = 10007;

int N, ANS;
int DP[MAX_COUNT][10];

int main(void) {
  scanf("%d", &N);
  for (int i = 0; i < 10; i++) {
    DP[1][i] = 1;
  }

  for (int i = 2; i <= N; i++) {
    for (int j = 0; j < 10; j++) {
      for (int k = j; k < 10; k++) {
        DP[i][j] = (DP[i][j] + DP[i - 1][k]) % DIVISOR;
      }
    }
  }

  for (int i = 0; i < 10; i++) {
    ANS = (ANS + DP[N][i]) % DIVISOR;
  }

  printf("%d\n", ANS);
}
