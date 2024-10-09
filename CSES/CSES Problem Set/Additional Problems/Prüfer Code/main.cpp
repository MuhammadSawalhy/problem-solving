// ﷽
// https://cses.fi/problemset/task/1134

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
#define vvi vector<vector<int>>
#define sz(v) (int) (v).size()
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define minit(v, x...) v = min({v, x})
#define maxit(v, x...) v = max({v, x})

template<class T>
using rpq = priority_queue<T, vector<T>, greater<T>>;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n - 2);
    set<int> s;

    for (int i = 0; i < n; i++) {
        s.insert(i);
    }

    vector<int> fr(n);

    for (int i = 0; i < n - 2; i++) {
        cin >> a[i], a[i]--;
        fr[a[i]]++;
        s.erase(a[i]);
    }

    rpq<int> pq;
    for (auto i: s) pq.push(i);

    vector<int> adj[n];
    for (int i = 0; i < n - 2; i++) {
        int t = pq.top();
        pq.pop();

        adj[t].push_back(a[i]);

        fr[a[i]]--;
        if (fr[a[i]] == 0) {
            pq.push(a[i]);
        }
    }

    assert(pq.size() == 2);
    int u = pq.top();
    pq.pop();
    int v = pq.top();
    adj[u].push_back(v);

    for (int i = 0; i < n; i++) {
        for (auto j : adj[i]) {
            cout << i + 1 << ' ' << j + 1 << endl;
        }
    }
}

int32_t main(int32_t argc, char **argv) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int T = 1;
    for (int t = 1; t <= T; t++) {
        debug("--------", t);
        solve();
    }

    return 0;
}
