/* Date : 2019.5.7
 * Author : seungyeon choi
 * 10815 (숫자 카드)
 */

#include <algorithm>
#include <cstdio>
#include <vector>

int N, M;
std::vector<int> V;

bool bs(int low, int high, int target) {
  if (low > high) {
    return false;
  } else {
    int mid = (low + high) / 2;
    if (V[mid] == target)
      return true;
    else if (V[mid] > target)
      return bs(low, mid - 1, target);
    else
      return bs(mid + 1, high, target);
  }
}

int main(void) {
  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    int num;
    scanf("%d", &num);
    V.push_back(num);
  }

  sort(V.begin(), V.end());

  scanf("%d", &M);
  for (int i = 0; i < M; i++) {
    int num;
    scanf("%d", &num);
    printf("%d ", bs(0, N - 1, num));
  }

  return 0;
}
