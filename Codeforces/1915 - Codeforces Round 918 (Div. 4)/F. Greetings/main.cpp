// ﷽
// https://codeforces.com/contest/1915/problem/F

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
#define debug(...) 0
#define debug_itr(...) 0
#define debug_bits(...) 0
#endif

#define ll long long
#define int long long
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define minit(v, x) v = min(v, x)
#define maxit(v, x) v = max(v, x)

void solve() {
    int n;
    cin >> n;
    int a[n], b[n];
    ordered_set<int> oset;
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
        oset.insert(a[i]);
    }
    vector<int> order(n);
    iota(all(order), 0);
    sort(all(order), [&](int i, int j) {
        return b[i] < b[j];
    });
    int ans = 0;
    for (auto i: order) {
        // for not inserted, but before a[i]
        ans += oset.order_of_key(a[i]);
        oset.erase(a[i]);
    }
    cout << ans << endl;
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
