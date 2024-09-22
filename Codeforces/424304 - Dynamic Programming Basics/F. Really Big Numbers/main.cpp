// ﷽
// https://codeforces.com/group/isP4JMZTix/contest/424304/problem/F

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

void solve() {
    int n, s;
    cin >> n >> s;

    int ans = max(0ll, n - (s + 9 * 18 + 1) + 1);
    for (int i = s + 1; i < min(n + 1, s + 9 * 18 + 1); i++) {
        int sd = 0;
        int j = i;
        while (j) sd += j % 10, j /= 10;
        if (i - sd >= s) ans++;
    }
    cout << ans << endl;
}

int32_t main(int32_t argc, char **argv) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int t = 1;
    while (t--)
        solve();

    return 0;
}
