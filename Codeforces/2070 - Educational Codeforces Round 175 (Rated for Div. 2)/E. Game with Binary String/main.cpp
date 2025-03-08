#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T, null_type, std::less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#ifdef SAWALHY
#include "debug.hpp"
#else
#define debug(...) 0
#define debug_itr(...) 0
#define debug_bits(...) 0
#endif


using namespace std;
#define int long long
#define ll long long
#define all(v) begin(v), end(v)
#define rall(v) rbegin(v), rend(v)

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    int ans = 0;

    ordered_set<pair<int, int>> os;
    os.insert({0, -1});

    for (int i = 0, val = 0; i < n; i++) {
        if (s[i] == '0') val++;
        else val -= 3;
        debug(i, val);

        // x = val - y;

        // val - y = -1, y = val + 1;
        auto it1 = os.order_of_key({val +1, -1});
        auto it2 = os.order_of_key({val + 2, -1});
        ans += it2 - it1;
        debug(ans);

        // val - y > 1, y < val  - 1
        ans += os.order_of_key({val - 1, -1});
        debug(ans);
        os.insert({val, i});
    }

    cout << ans << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);

    int T = 1;
    for (int t = 1; t <= T; t++) {
        solve();
    }

    return 0;
}
