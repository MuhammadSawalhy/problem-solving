// ﷽
#include <bits/stdc++.h>
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

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    ordered_set<pair<int, int>> s;

    int n, q;
    cin >> n >> q;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        s.insert({a[i], i});
    }

    while (q--) {
        char t;
        int x, y;
        cin >> t >> x >> y;
        if (t == '?') {
            auto ite = s.upper_bound({y, n});
            auto its = s.lower_bound({x, 0});
            int i = s.order_of_key(*its);
            if (ite == s.end())
                cout << s.size() - i << endl;
            else
                cout << s.order_of_key(*ite) - i << endl;
        } else {
            x--;
            s.erase({a[x], x});
            a[x] = y;
            s.insert({a[x], x});
        }
    }

    return 0;
}
