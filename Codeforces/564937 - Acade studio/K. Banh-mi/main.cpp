#include <bits/stdc++.h>
using namespace std;

const int N = 100100, mod = 1e9 + 7;
int ps[N], sump2[N];

int32_t main(int32_t argc, char **argv) {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;

    for (int i = 0; i < n; i++) {
        ps[i + 1] += ps[i] + s[i] - '0';
    }

    sump2[0] = 0;
    sump2[1] = 1;

    for (int i = 2, p = 2; i < N; i++) {
        sump2[i] = (sump2[i - 1] + p) % mod;
        p = (p * 2) % mod;
    }

    while (q--) {
        int l, r;
        cin >> l >> r;
        int ones = ps[r] - ps[l - 1];
        int x = sump2[ones] * 1;
        int y = 1LL * sump2[r - l + 1 - ones] * x % mod;
        cout << (x + y) % mod << endl;
    }

    return 0;
}
