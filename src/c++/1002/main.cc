/* Date : 2017.8.1
 * Author : seungyeon choi
 * 1002 (터렛)
 */

#include <stdio.h>

int main(void) {
  int num;
  int x1, y1, x2, y2, r1, r2;
  int pnt_d, rds1, rds2, ans;

  scanf("%d", &num);

  for (int i = 0; i < num; i++) {
    scanf("%d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2);

    pnt_d = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
    rds1 = (r1 - r2) * (r1 - r2);
    rds2 = (r1 + r2) * (r1 + r2);

    if (pnt_d == 0 && (r1 == r2))
      ans = -1;
    else if (pnt_d < rds1 || pnt_d > rds2)
      ans = 0;
    else if (pnt_d == rds1 || pnt_d == rds2)
      ans = 1;
    else
      ans = 2;

    printf("%d\n", ans);
  }
}
