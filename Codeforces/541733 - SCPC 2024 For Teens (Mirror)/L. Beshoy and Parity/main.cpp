// ﷽
// https://codeforces.com/group/Rilx5irOux/contest/541733/problem/L

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

int ans;
string s;

void solveit(int i, int p) {
    if (i == sz(s)) {
        minit(ans, (int) stoll(s));
        return;
    }

    if ((s[i] - '0') % 2 != p) {
        if (s[i] != '9') {
            string t = s;
            t[i] = t[i] + 1;
            for (int j = i + 1; j < sz(t); j++) {
                t[j] = '0' + p;
            }
            minit(ans, (int) stoll(t));
        }
    } else {
        if (s[i] != '8' && s[i] != '9') {
            string t = s;
            t[i] = t[i] + 2;
            for (int j = i + 1; j < sz(t); j++) {
                t[j] = '0' + p;
            }
            minit(ans, (int) stoll(t));
        }
    }

    if ((s[i] - '0') % 2 != p) return;
    solveit(i + 1, p);
}

void solve() {
    cin >> s;

    ans = 1e18;
    solveit(0, 0);
    solveit(0, 1);

    cout << ans << endl;
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
