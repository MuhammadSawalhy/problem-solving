// ﷽
// https://codeforces.com/contest/2026/problem/B

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
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    if (n == 1) {
        cout << "1\n";
        return;
    }


    if (n % 2 == 0) {
        priority_queue<int> vals;
        for (int i = 1; i < n; i += 2) {
            vals.push(a[i] - a[i - 1]);
        }
        cout << vals.top() << endl;
    } else {
        int mn = 1e18;

        for (int i = 0; i < n; i += 2) {
            priority_queue<int> vals;
            int prev = -1;
            for (int j = 0; j < n; j++) {
                if (j == i) continue;
                if (prev != -1) {
                    vals.push(a[j] - a[prev]);
                    prev = -1;
                } else {
                    prev = j;
                }
            }
            assert(prev == -1);
            int cur = vals.top();
            int nearest = 1e18;
            int j = i + 1;
            while (j < n && a[j] - a[j - 1] == 1) j++;
            j--;
            minit(nearest, a[j] + 1);
            j = i - 1;
            while (i > -1 && a[j + 1] - a[j] == 1) j--;
            j++;
            minit(nearest, a[j] - 1);

            maxit(cur, abs(nearest - a[i]));
            debug(i, cur, nearest);

            minit(mn, cur);
        }

        cout << mn << endl;
    }
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
