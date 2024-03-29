// ﷽
// https://cses.fi/problemset/task/1161

#include <bits/stdc++.h>
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
#define sz(v) (int) (v).size()
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define minit(v, x...) v = min({v, x})
#define maxit(v, x...) v = max({v, x})

template<class T>
using rpq = priority_queue<T, vector<T>, greater<T>>;

void solve() {
    int x, n;
    cin >> x >> n;
    vector<int> a(n);
    rpq<int> pq;
    for (int i = 0; i < n; i++) cin >> a[i], pq.push(a[i]);

    int ans = 0, f, s;
    while (pq.size() > 1) {
        f = pq.top(), pq.pop();
        s = pq.top(), pq.pop();
        ans += f + s, pq.push(f + s);
    }

    cout << ans << endl;
}

int32_t main(int32_t argc, char **argv) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    solve();

    return 0;
}
