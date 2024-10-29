// ﷽
// https://codeforces.com/contest/2004/problem/E

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

const int N = 3e5 + 1;
const int M = 1e7 + 1;
int g[M];


std::vector<int> minp, primes;
void sieve(int n) {
    minp.assign(n + 1, 0);
    primes.clear();

    for (int i = 2; i <= n; i++) {
        if (minp[i] == 0) {
            minp[i] = i;
            primes.push_back(i);
        }

        for (auto p: primes) {
            if (i * p > n) {
                break;
            }
            minp[i * p] = p;
            if (p == minp[i]) {
                break;
            }
        }
    }
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    int v = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        v ^= g[a[i]];
        debug(g[a[i]]);
    }

    if (v == 0) {
        cout << "Bob\n";
    } else {
        cout << "Alice\n";
    }
}

int32_t main(int32_t argc, char **argv) {
    cin.tie(nullptr)->sync_with_stdio(false);

    sieve(M);

    const int nn = 100;
    vi vals(nn);

    for (int i = 1; i < nn; i++) {
        vi g;

        for (int j = 1; j <= i; j++) {
            if (gcd(i, j) == 1) {
                assert(gcd(i - j, i) == 1);
                g.push_back(vals[i - j]);
            }
        }

        sort(all(g));
        g.erase(unique(all(g)), g.end());
        while (vals[i] < sz(g) && vals[i] == g[vals[i]]) vals[i]++;
        debug(i, vals[i]);
    }

    g[1] = 1;
    for (int i = 3, mx = 1; i < M; i += 2) {
        if (minp[i] == i) {
            g[i] = ++mx;
        } else {
            g[i] = g[minp[i]];
        }
    }

    int T = 1;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        debug("--------", t);
        solve();
    }

    return 0;
}
