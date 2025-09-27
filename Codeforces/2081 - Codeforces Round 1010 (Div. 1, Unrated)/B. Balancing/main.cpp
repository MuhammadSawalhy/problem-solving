#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define all(v) begin(v), end(v)
#define rall(v) rbegin(v), rend(v)

#ifdef SAWALHY
#include "debug.hpp"
#else
#define debug(...) 0
#define debug_itr(...) 0
#define debug_bits(...) 0
#endif


void solve() {
    int n;
    cin >> n;
    vector<int> arr(n), b(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    for (int i = 1; i < n; i++)
        b[i] = arr[i] - arr[i - 1] > 0 ? 1 : -1;

    debug(b);
    vector<int> negs;
    for (int i = 1, j = 1; i < n; i++) {
        if (b[i] == -1) negs.push_back(i);
    }

    int ans;
    if (negs.size() == 0) {
        ans = 0;
    } else if (negs.size() & 1) {
        ans = (negs.size() + 1) / 2;
    } else {
        int i = negs.front(), j = negs.back();
        bool f = arr[j] - arr[i - 1] - 1 < j - i;
        debug(f);
        ans = negs.size() / 2 + f;
    }

    assert(ans <= n / 2 + 1);
    cout << ans << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);

    int T = 1;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        debug(t);
        solve();
    }

    return 0;
}
