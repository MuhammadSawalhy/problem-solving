// ﷽
#include <bits/stdc++.h>

using namespace std;

#ifdef SAWALHY
#include "debug.hpp"
#else
#define debug(...) 0
#define debug_itr(...) 0
#define debug_bits(...) 0
#endif

#define int long long
#define ll long long
#define all(v) v.begin(), v.end()


vector<int> ans;

bool doit(int x) {
    if (x == 1) {
        return true;
    }

    if (x == 0) return false;
    if (x % 2 == 0) return false;

    if (doit((x + 1) / 2)) {
        ans.push_back(1);
        return true;
    }

    if (doit((x - 1) / 2)) {
        ans.push_back(2);
        return true;
    }

    return false;
}

void solve() {
    int n;

    cin >> n;

    ans.clear();
    if (!doit(n)) return cout << -1 << '\n', void();

    cout << ans.size() << '\n';
    for (auto i: ans)
        cout << i << ' ';
    cout << '\n';
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
