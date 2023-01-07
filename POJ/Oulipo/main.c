#include "stdio.h"
#include "string.h"

char W[10001];
char T[1000001];

int main() {
    int t;
    scanf("%d", &t);

    while (t--) {
        scanf("%s", W);
        scanf("%s", T);

        int n = strlen(T), m = strlen(W);

        int ans = 0;

        int table[m]; table[0] = 0;
        int i, k;
        for (i = 1, k = 0; i < m; i++) {
            while (k > 0 && W[k] != W[i])
                k = table[k - 1];
            if (W[i] == W[k])
                table[i] = ++k;
            else
                table[i] = k;
        }

        for (i = 0, k = 0; i < n; i++) {
            while (k > 0 && W[k] != T[i])
                k = table[k - 1];

            k += W[k] == T[i];

            if (k == m) {
                ans++;
                k = table[k - 1];
            }
        }

        printf("%d\n", ans);
    }

    return 0;
}
