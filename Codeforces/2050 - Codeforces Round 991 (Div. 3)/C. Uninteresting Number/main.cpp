// ﷽
// https://codeforces.com/contest/2050/problem/C

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

void solve() {
    string n;
    cin >> n;

    int sum = 0;
    int twos = 0, threes = 0;
    for (int i = 0; i < n.size(); i++) {
        sum += n[i] - '0';
        sum %= 9;
        twos += n[i] == '2';
        threes += n[i] == '3';
    }

    int z = (9 - sum) % 9;

    for (int i = 0; i < min(9ll, twos + 1); i ++) {
        for (int j = 0; j < min(9ll, threes + 1); j++) {
            if ((2 * i + 6 * j) % 9 == z) {
                cout << "YES\n";
                return;
            }
        }
    }
    cout << "NO\n";
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
