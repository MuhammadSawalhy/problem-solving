// ﷽
#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T, null_type, std::less<T>, rb_tree_tag, tree_order_statistics_node_update>;

using namespace std;

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

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    ordered_set<pair<int, int>> os;

    int n, k;
    cin >> n >> k;
    ll a[n];
    for (int i = 0; i < n; i++) cin >> a[i];

    for (int i = 0; i < k; i++) {
        os.insert({a[i], i});
    }

    cout << os.find_by_order((os.size() - 1) / 2)->first << " ";

    for (int i = k; i < n; i++) {
        os.erase({a[i - k], i - k});
        os.insert({a[i], i});
        cout << os.find_by_order((os.size() - 1) / 2)->first << " ";
    }

    return 0;
}
