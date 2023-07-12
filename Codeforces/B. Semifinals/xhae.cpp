#include <algorithm>
#include <cstdio>

using namespace std;

int a[100000], b[100000], n;
int arr[200000];

int ans[2][100000];

int main(void) {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d %d", a + i, b + i);
    arr[i * 2] = a[i];
    arr[i * 2 + 1] = b[i];
  }

  for (int i = 0; i < n / 2; i++)
    ans[0][i] = ans[1][i] = 1;
  if (n & 1)
    ans[0][n / 2] = ans[1][n / 2] = 1;

  sort(arr, arr + n * 2);
  int i1 = 0, i2 = 0;
  for (int i = 0; i < n; i++) {
    int cur = arr[i];
    if (a[i1] == cur)
      ans[0][i1++] = 1;
    else
      ans[1][i2++] = 1;
  }

  for (int i = 0; i < n; i++)
    printf("%d", ans[0][i]);
  printf("\n");
  for (int i = 0; i < n; i++)
    printf("%d", ans[1][i]);
  printf("\n");

  return 0;
}
