/* Date : 2019.5.7
 * Author : seungyeon choi
 * 2805 (나무 자르기)
 */

#include <cstdio>

const int TREE_MAX = 1000001;

long long M, N, low, high, tree_max;
long long ans = 0;
long long tree[TREE_MAX];

int main(void) {
  scanf("%lld %lld", &N, &M);

  for (int i = 0; i < N; i++) {
    scanf("%lld", &tree[i]);
    if (tree[i] > tree_max)
      tree_max = tree[i];
  }

  low = 0;
  high = tree_max;

  while (low <= high) {
    long long mid = (low + high) / 2;
    long long total = 0;
    for (int i = 0; i < N; i++)
      if (tree[i] - mid > 0)
        total += tree[i] - mid;

    if (total >= M) {
      if (ans < mid)
        ans = mid;
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }

  printf("%lld\n", ans);

  return 0;
}
