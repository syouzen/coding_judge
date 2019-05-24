/* Date : 2019.5.24
 * Author : seungyeon choi
 * 1003 (피보나치 함수)
 */

#include <cstdio>

const int MAX_COUNT = 41;

int T, N;
int DP_ZERO[MAX_COUNT];
int DP_ONE[MAX_COUNT];

int main(void) {
  DP_ZERO[0] = DP_ONE[1] = 1;
  DP_ZERO[1] = DP_ONE[0] = 0;
  for (int i = 2; i <= 40; i++) {
    DP_ZERO[i] = DP_ZERO[i - 1] + DP_ZERO[i - 2];
    DP_ONE[i] = DP_ONE[i - 1] + DP_ONE[i - 2];
  }

  scanf("%d", &T);
  while (T) {
    scanf("%d", &N);
    printf("%d %d\n", DP_ZERO[N], DP_ONE[N]);
    T--;
  }
}
