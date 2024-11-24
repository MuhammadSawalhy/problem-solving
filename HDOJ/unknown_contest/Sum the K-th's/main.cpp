#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T, null_type, std::less<T>, rb_tree_tag, tree_order_statistics_node_update>;

using namespace std;

const int N = 100100, mod = 1e9 + 7;
int n, m, k;
int a[N];

long long getitem(int i) {
    i = (i + n + n) % n;
    return 1LL * a[i] << 20 | i;
}

void solve() {
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    if (m == 0) {
        cout << "0\n";
        return;
    }

    ordered_set<long long> s;
    int ans = 0;

    for (int i = -m; i <= m; i++) {
        if (i) {
            s.insert(getitem(i));
        }
    }

    ans += *s.find_by_order(k - 1) >> 20;
    if (ans >= mod) ans -= mod;

    for (int i = 1; i < n; i++) {
        s.insert(getitem(i - 1));
        s.erase(getitem(i));

        s.erase(getitem(i - 1 - m));
        s.insert(getitem(i + m));

        ans += *s.find_by_order(k - 1) >> 20;
        if (ans >= mod) ans -= mod;
    }

    cout << ans << '\n';
}

int32_t main(int32_t argc, char **argv) {
    cin.tie(nullptr)->sync_with_stdio(false);

    int T = 1;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        solve();
    }

    return 0;
}
