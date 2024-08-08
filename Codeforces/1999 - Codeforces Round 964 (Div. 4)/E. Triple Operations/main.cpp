// ﷽
// https://codeforces.com/contest/1999/problem/E

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

const int N = 2e5 + 5;
vector<int> vals(N);


void solve() {
    int l, r;
    cin >> l >> r;

    int cnt = 0;

    cnt += 2 * (vals[l] - vals[l - 1]);
    cnt += vals[r] - vals[l];

    cout << cnt << endl;
}

int32_t main(int32_t argc, char **argv) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    for (int i = 1; i < N; i++) {
        int x = i;
        while (x) {
            vals[i]++;
            x /= 3;
        }
        vals[i] += vals[i - 1];
    }

    int t = 1;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
