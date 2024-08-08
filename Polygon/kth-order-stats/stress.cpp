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
#define debug(...) 0
#define debug_itr(...) 0
#define debug_bits(...) 0
#endif

#define ll long long
#define int long long
#define all(v) v.begin(), v.end()

void solve() {
    int n;
    cin >> n;

    ordered_set<int> s;
    while (n--) {
        char t;
        cin >> t;

        if (t == '?') {
            int sum = 0;
            for (int i = 2; i < s.size(); i += 5) {
                sum += *s.find_by_order(i);
            }
            cout << sum << endl;
        }  else if (t == '+') {
            int x; cin >> x;
            s.insert(x);
        } else {
            int x; cin >> x;
            s.erase(x);
        }
   }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int t = 1;
    // cin >> t;
    while (t--)
        solve();

    return 0;
}
