// ﷽
// https://csacademy.com/ieeextreme18/task/icarus/

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
#define vi vector<int>
#define vvi vector<vector<int>>
#define pii pair<int, int>
#define vii vector<pii>
#define sz(v) (int) (v).size()
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define minit(v, x...) v = min({v, x})
#define maxit(v, x...) v = max({v, x})

template<class T>
using rpq = priority_queue<T, vector<T>, greater<T>>;

const int N = 2e5;
int p[N];
pair<int, int> adj[N];

string s;

void solve() {
    cin >> s;

    int cnt = 1;

    while (cnt < 2 * sz(s)) {
        int rnd = rand() & 1;
        int node = cnt;
        if (rnd) {
            adj[node].first = ++cnt;
        } else {
            adj[node].second = ++cnt;
        }
    }

    cout << cnt << ' ' << cnt << ' ' << 1 << endl;

    for (int i = 1; i <= cnt; i++) {
        cout << adj[i].first << ' ' << adj[i].second << endl;
    }
}

int32_t main(int32_t argc, char **argv) {
    cin.tie(nullptr)->sync_with_stdio(false);
    srand(time(nullptr));

    int T = 1;
    for (int t = 1; t <= T; t++) {
        debug("--------", t);
        solve();
    }

    return 0;
}
