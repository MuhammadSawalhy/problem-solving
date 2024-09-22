// ﷽
// https://codeforces.com/contest/2000/problem/C

#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
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
#define pii pair<int, int>
#define sz(v) (int) (v).size()
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define minit(v, x...) v = min({v, x})
#define maxit(v, x...) v = max({v, x})

template<class T>
using rpq = priority_queue<T, vector<T>, greater<T>>;

template<class T>
vector<int> compute(const vector<T> &a) {
    int n = sz(a);
    vector<int> ans(n , -1);
    map<int, int> last;
    for (int i = 0; i < n;i ++) {
        if (last.count(a[i])) {
            ans[i] = last[a[i]];
        }
        last[a[i]] = i;
    }
    return ans;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    auto x = compute(a);
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        string s;
        cin >> s;

        if (sz(s) != n) {
            cout << "NO\n";
            continue;
        }

        auto y = compute<char>(vector<char>(all(s)));

        bool ok = true;
        for (int i = 0; i < n; i++) {
            if (x[i] != y[i]) {
                ok = false;
            }
        }

        cout << (ok ? "YES": "NO") << endl;
    }
}

int32_t main(int32_t argc, char **argv) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int t = 1;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
