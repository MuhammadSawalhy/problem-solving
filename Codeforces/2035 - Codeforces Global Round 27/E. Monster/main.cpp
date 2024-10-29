// ﷽
// https://codeforces.com/contest/2035/problem/E

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

int a, b, z, k;

int ceildiv(int x, int y) {
    return (x + y - 1) / y;
}

int getmind(int x, int d) {
    int f = x / d;
    int min_d = x / (f + 1) + 1;
    assert(x / min_d == x / d);
    return min_d;
}

int getcost(int x) {
    if (x > z || x < 1) return 1e18;
    int cnt = (x + k - 1) / k - 1;
    int rem = z - (cnt + 1) * cnt / 2 * k;
    if (rem == 0) return x * a + cnt * b;
    if (rem < 0) return 1e18;
    int newx = getmind(rem + x - 1, x);
    if (newx != x) return getcost(newx);
    int cost = x * a + cnt * b + (rem + x - 1) / x * b;
    return cost;
}

mt19937 rng = mt19937(random_device()());

void seed(int s) { rng = mt19937(s); }

int rand_int(int x, int y) {
    return uniform_int_distribution<int>(x, y)(rng);
}


void solve() {
    cin >> a >> b >> z >> k;
    int ans = 1e18;

    set<double> s;
    int l = 1, r = 1e9;

    while (r - l > 1e5) {
        int m1 = l + (r - l) / 3;
        int m2 = r - (r - l) / 3;
        debug(l, m1, m2, r);
        int cost1 = getcost(m1);
        int cost2 = getcost(m2);
        debug(cost1, cost2);
        if (cost1 < cost2 || cost2 == 1e18) {
            r = m2;
        } else {
            l = m1;
        }
    }

    l = min(l, (int) 1e8);
    r = min(r, (int) 1e8);
    debug(l, r);

    for (int i = l; i <= r; i = min(i + 5, r)) {
        minit(ans, getcost(i));
        if (i == r) break;
    }


    cout << ans << endl;
}

int32_t main(int32_t argc, char **argv) {
    cin.tie(nullptr)->sync_with_stdio(false);

    int T = 1;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        debug("--------", t);
        solve();
    }

    return 0;
}
