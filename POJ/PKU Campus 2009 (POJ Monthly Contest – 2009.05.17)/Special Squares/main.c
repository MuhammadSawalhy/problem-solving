#include <stdio.h>

#define N 1010

int p[N][N], yy[N], xx[N], v[N * 2][2];

int count(int x1, int y1, int x2, int y2) {
    return p[x2][y2] - p[x1 - 1][y2] - p[x2][y1 - 1] + p[x1 - 1][y1 - 1];
}

int main(int argc, char **argv) {
    int n1, n2, n3;
    scanf("%d %d %d", &n1, &n2, &n3);

    for (int i = 0, y; i < n1; i++) scanf("%d", &y), yy[y + 1]++;
    for (int i = 0, x; i < n2; i++) scanf("%d", &x), xx[x + 1]++;
    for (int i = 0, x, y; i < n3; i++) scanf("%d %d", &x, &y), p[x + 1][y + 1]++;

    for (int x = 1; x <= 1001; x++) {
        for (int y = 1; y <= 1001; y++) {
            p[x][y] += p[x - 1][y] + p[x][y - 1] - p[x - 1][y - 1];
        }
    }

    int ans = 0;

    for (int sum = 2; sum <= 2002; sum++) {
        int v_size = 0, i = 0;
        for (int x = 1; x <= 1001; x++) {
            int y = sum - x;
            if (1 <= y && y <= 1001 && yy[y] != 0 && xx[x] != 0) {
                while (i < v_size && count(v[i][0], y, x, v[i][1])) i++;
                ans += i;
                v[v_size][0] = x;
                v[v_size][1] = y;
                v_size++;
            }
        }
    }

    printf("%d\n", ans);
    return 0;
}
