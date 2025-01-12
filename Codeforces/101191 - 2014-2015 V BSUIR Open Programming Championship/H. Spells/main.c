#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define MOD 1000000007

typedef struct {
    int **a;
    int n, m;
} Mat;

Mat create_mat(int n, int m) {
    Mat mat;
    mat.n = n;
    mat.m = m;
    mat.a = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        mat.a[i] = (int *)calloc(m, sizeof(int));
    }
    return mat;
}

Mat multiply(Mat a, Mat b) {
    Mat c = create_mat(a.n, b.m);
    for (int i = 0; i < a.n; i++) {
        for (int j = 0; j < b.m; j++) {
            for (int k = 0; k < a.m; k++) {
                c.a[i][j] = (c.a[i][j] + 1LL * a.a[i][k] * b.a[k][j]) % MOD;
            }
        }
    }
    return c;
}

void fast_pow(Mat *m, int p) {
    assert(m->n == m->m);
    Mat res = create_mat(m->n, m->n);
    for (int i = 0; i < m->n; i++)
        res.a[i][i] = 1;

    while (p) {
        if (p & 1) res = multiply(res, *m);
        *m = multiply(*m, *m);
        p >>= 1;
    }
    *m = res;
}

int main() {
    int n;
    scanf("%d", &n);

    Mat A = create_mat(27, 1);
    A.a[26][0] = 1;

    for (int i = 0; i < n; i++) {
        char s[101];
        int k;
        scanf("%s %d", s, &k);

        Mat All = create_mat(27, 27);
        for (int i = 0; i < 27; i++)
            All.a[i][i] = 1;

        for (int i = 0; s[i]; i++) {
            Mat M = create_mat(27, 27);
            for (int j = 0; j < 27; j++) {
                M.a[s[i] - 'a'][j] = 1;
            }

            for (int j = 0; j < 26; j++) {
                if (j != s[i] - 'a') {
                    M.a[j][j] = 1;
                }
            }

            All = multiply(M, All);
        }

        fast_pow(&All, k);
        A = multiply(All, A);
    }

    int ans = 0;
    for (int i = 0; i < 26; i++)
        ans = (ans + A.a[i][0]) % MOD;

    printf("%d\n", ans);

    return 0;
}
