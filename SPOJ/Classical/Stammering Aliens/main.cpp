#include <bits/stdc++.h>
using namespace std;

int n, m;
string s;
__int128 h[40004], base[40004];
const long long mod = (1ll << 61) - 1;

void calc_hash() {
    for (int i = 0; i < (int) s.size(); i++)
        h[i + 1] = (h[i] * base[1] + s[i]) % mod;
}

int get(int l, int r) {
    return (h[r + 1] - h[l] * base[r - l + 1] % mod + mod) % mod;
}

int32_t main(int32_t argc, char **argv) {
    cin.tie(nullptr)->sync_with_stdio(false);

    base[0] = 1;
    for (int i = 1; i < 40004; i++) base[i] = (base[i - 1] * 127) % mod;

    while (cin >> m, m != 0) {
        cin >> s;
        n = s.size();
        calc_hash();
        int l = 0, r = n + 1, pos;
        while (r - l > 1) {
            int mid = (l + r) / 2;
            map<long long, int> fr;
            int p = -1;
            for (int i = 0; i + mid <= n; i++) {
                long long cur = get(i, i + mid - 1);
                if (++fr[cur] >= m) p = i;
            }
            cerr << mid << ' ' << p << '\n';
            if (p == -1) r = mid;
            else l = mid, pos = p;
        }
        if (l == 0) cout << "none\n";
        else cout << l << ' ' << pos << '\n';
    }

    return 0;
}
