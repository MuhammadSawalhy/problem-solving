// ﷽
// https://codeforces.com/contest/1999/problem/G2

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

    int l = 2, r = 999;

    while (r - l > 0) {
        int a = l + (r - l + 1) / 3;
        int b = l + (r - l + 1) / 3 * 2;

        cout << "? " << a << ' ' << b << endl;
        int area;
        cin >> area;

        if (area == a * b) {
            l = b + 1;
        } else if (area == a * (b + 1)) {
            l = a + 1;
            r = b;
        } else {
            r = a;
        }
    }

    cout << "! " << r << endl;
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
