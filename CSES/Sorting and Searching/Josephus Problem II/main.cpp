// ﷽
// 12 جُمادى الآخرة 1444
// Jan 04, 2023
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T, null_type, std::less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define debug(...)
#ifdef SAWALHY
#include "debug.hpp"
#endif

#define int long long
#define ll long long
#define all(v) v.begin(), v.end()

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n, k;
    cin >> n >> k;

    ordered_set<int> s;

    for (int i = 0; i < n; i++) {
        s.insert(i + 1);
    }

    auto it = s.begin();
    int i = 0;
    while (s.size()) {
        i = (i + k) % s.size();
        auto it = s.find_by_order(i);
        cout << *it << " ";
        s.erase(it);
    }

    return 0;
}
