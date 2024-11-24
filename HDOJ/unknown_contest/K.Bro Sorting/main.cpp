#include <bits/stdc++.h>
using namespace std;

char in[1 << 24];
struct Scanner {
    char const *o;
    Scanner() : o(in) { load(); }
    void load() { in[fread(in, 1, sizeof(in) - 4, stdin)] = 0; }
    unsigned readInt() {
        unsigned u = 0;
        while (*o && *o <= 32) ++o;
        while (*o >= '0' && *o <= '9')
            u = u * 10 + (*o++ - '0');
        return u;
    }
    unsigned readDigit() {
        while (*o && *o <= 32) ++o;
        if (*o >= '0' && *o <= '9')
            return *o++ - '0';
        assert(false);
    }
} sc;

const int N = 1e6 + 1;
int a[N], st[N];

int main() {
    int t;
    t = sc.readInt();
    for (int T = 1; T <= t; T++) {
        int n, m = 0, ans = 0;
        n = sc.readInt();

        for (int i = 0; i < n; i++) {
            a[i] = sc.readInt();
            while (m > 0 && st[m - 1] > a[i]) {
                m--;
                ans++;
            }
            st[m++] = a[i];
        }

        printf("Case #%d: %d\n", T, ans);
    }

    return 0;
}
