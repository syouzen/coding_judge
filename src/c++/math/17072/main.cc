/* Date : 2019.5.13
 * Author : seungyeon choi
 * 17072 (아스키 아트)
 */

#include <cstdio>

const int MAX_COUNT = 401;

static inline int getIntensity(int r, int g, int b) {
  return 2126 * r + 7152 * g + 722 * b;
}

int N, M;
char ASCII[MAX_COUNT][MAX_COUNT];

int main(void) {
  int r, g, b, intensity;
  scanf("%d %d", &N, &M);
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      scanf("%d %d %d", &r, &g, &b);
      intensity = getIntensity(r, g, b);
      if (intensity >= 0 && intensity < 510000) {
        ASCII[i][j] = '#';
      } else if (intensity >= 510000 && intensity < 1020000) {
        ASCII[i][j] = 'o';
      } else if (intensity >= 1020000 && intensity < 1530000) {
        ASCII[i][j] = '+';
      } else if (intensity >= 1530000 && intensity < 2040000) {
        ASCII[i][j] = '-';
      } else {
        ASCII[i][j] = '.';
      }
    }
  }
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      printf("%c", ASCII[i][j]);
    }
    printf("\n");
  }

  return 0;
}
