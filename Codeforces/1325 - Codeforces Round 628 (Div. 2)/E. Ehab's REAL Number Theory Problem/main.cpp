// ﷽
// https://codeforces.com/contest/1325/problem/E
// Codeforces -> Codeforces Round 628 (Div. 2) -> E. Ehab's REAL Number Theory Problem

#include <bits/stdc++.h>
using namespace std;

#ifdef SAWALHY
#include "debug.hpp"
#else
#define debug(...) 0
#define debug_itr(...) 0
#define debug_bits(...) 0
#endif

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define minit(v, x) v = min(v, x)
#define maxit(v, x) v = max(v, x)

const int inf = 1e9, M = 1e6 + 6;
vector<int> adj[M];
int d[M], p[M];

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n;
    cin >> n;
    int a[n];

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        // prime fact of a[i]
        vector<int> primes;
        for (int j = 2; j * j <= a[i]; j++) {
            int r = 0;
            while (a[i] % j == 0) {
                r++, a[i] /= j;
            }
            if (r & 1) {
                primes.push_back(j);
            }
        }
        if (a[i] > 1) primes.push_back(a[i]);
        while (primes.size() < 2) primes.push_back(1);
        adj[primes[0]].push_back(primes[1]);
        adj[primes[1]].push_back(primes[0]);
    }

    int ans = inf;
    // find the shortest cycle using bfs
    for (int i = 1; i <= 1000; i++) {
        if (adj[i].empty()) continue;
        queue<int> q;
        for (int i = 0; i < M; i++) d[i] = inf;
        for (int i = 0; i < M; i++) p[i] = -1;
        q.push(i);
        d[i] = 0;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            bool skip = true;
            for (int v: adj[u]) {
                if (d[v] != inf) {
                    if (p[u] != v || !skip)
                        ans = min(ans, d[u] + d[v] + 1);
                    if (p[u] == v)
                        skip = false;
                } else {
                    d[v] = d[u] + 1;
                    p[v] = u;
                    q.push(v);
                }
            }
        }
    }

    cout << (ans == inf ? -1 : ans) << '\n';
    return 0;
}
