/* Date : 2019.4.24
 * Author : seungyeon choi
 * 14501 (퇴사)
 */

#include <algorithm>
#include <cstdio>

using namespace std;

int ans, n, T[16], P[16], DP[16];

int main() {
  scanf("%d", &n);

  for (int i = 1; i <= n; i++) {
    scanf("%d %d", &T[i], &P[i]);
    DP[i] = P[i];
  }

  for (int i = 2; i <= n; i++) {
    int j = 1;
    while (j < i) {
      if (T[j] + j <= i)
        DP[i] = max(DP[j] + P[i], DP[i]);
      j++;
    }
  }

  for (int i = 0; i <= n; i++) {
    if (i + T[i] <= n + 1) {
      if (DP[i] > ans)
        ans = DP[i];
    }
  }

  printf("%d", ans);

  return 0;
}
