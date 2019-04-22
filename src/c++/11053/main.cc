/* Date : 2019.4.22
 * Author : seungyeon choi
 * 11053 (가장 긴 증가하는 부분 수열 - LIS)
 */

#include <algorithm>
#include <cstdio>

using namespace std;

int n, x, ans = 0;
int DP[1001];

int main() {
  scanf("%d", &n);

  for (int i = 0; i < n; i++) {
    scanf("%d", &x);
    if (DP[ans] < x)
      DP[++ans] = x;
    else
      *lower_bound(DP, DP + ans + 1, x) = x;
  }

  printf("%d", ans);

  return 0;
}
