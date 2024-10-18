// ﷽
// https://codeforces.com/contest/2022/problem/B

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


int rem[10 + 1], rem2[10 + 1];

void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(rall(a));
    debug(a);
    int s = -1, e = 1e18;

    while (e - s > 1) {
        int mid = (s + e) / 2;
        for (int i = 1; i <= 10; i++)
            rem[i] = rem2[i] = 0;
        rem[x] = rem2[x] = mid;

        int ok = true;
        for (int i = 0; i < n; i++) {
            int todo = a[i];
            for (int j = 10; j >= 1; j--) {
                int delta = min(todo, rem[j]);
                todo -= delta;
                rem2[j] -= delta;
                rem2[j - 1] += delta;
            }
            for (int j = 1; j <= 10; j++)
                rem[j] = rem2[j];
            if (todo) {
                ok = false;
                break;
            }
        }

        if (ok) {
            e = mid;
        } else {
            s = mid;
        }
    }

    cout << e << endl;
}

int32_t main(int32_t argc, char **argv) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int T = 1;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        debug("--------", t);
        solve();
    }

    return 0;
}
