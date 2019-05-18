/* Date : 2019.5.18
 * Author : seungyeon choi
 * 17175 (피보나치는 지겨웡~)
 */

#include <stdio.h>

const int MAX_COUNT = 51;
const int DIVISOR = 1000000007;

int N;
int DP[MAX_COUNT];

int main(void) {
  scanf("%d", &N);
  DP[0] = DP[1] = 1;
  for (int i = 2; i <= N; i++) {
    DP[i] = 1;
    DP[i] += (DP[i - 1] % DIVISOR + DP[i - 2] % DIVISOR) % DIVISOR;
  }
  printf("%d\n", DP[N] % DIVISOR);
}
