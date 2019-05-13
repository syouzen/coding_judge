/* Date : 2019.5.11
 * Author : seungyeon choi
 * 1818 (책정리)
 */

#include <algorithm>
#include <cstdio>

using namespace std;

const int MAX_COUNT = 200001;

int n, x, ans = 0;
int DP[MAX_COUNT];

int main() {
  scanf("%d", &n);

  for (int i = 0; i < n; i++) {
    scanf("%d", &x);
    if (DP[ans] < x)
      DP[++ans] = x;
    else
      *lower_bound(DP, DP + ans + 1, x) = x;
  }

  printf("%d", n - ans);

  return 0;
}
