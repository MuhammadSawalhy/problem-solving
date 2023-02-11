// ﷽
#include <bits/stdc++.h>

using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T, null_type, std::less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#ifdef SAWALHY
#include "debug.hpp"
#else
#define debug(...)
#define debug_itr(...)
#define debug_bits(...)
#endif

#define int long long
#define ll long long
#define all(v) v.begin(), v.end()

void solve() {
    int n;
    cin >> n;

    ordered_set<pair<int, int>> s;
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        int o = s.order_of_key({x, n});

        if (x - o - 1 >= 0) {
            ans += x - o - 1;

            int l = o, r = s.size();
            while (r - l > 1) {
                int mid = (l + r) / 2;
                auto it = s.find_by_order(mid);
                if (mid + 1 <= it->first)
                    l = mid;
                else
                    r = mid;
            }

            ans -= r - o;
        }

        s.insert({x, i});
        cout << ans << " ";
    }
    cout << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
