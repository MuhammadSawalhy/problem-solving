// ﷽
// https://codeforces.com/contest/2044/problem/D

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

    vector<int> b(n), ind(n + 1, -1);
    set<int> nums;
    for (int i = 1; i <= n; i++) nums.insert(i);
    for (int i = 0; i < n; i++) {
        if (ind[a[i]] == -1) {
            ind[a[i]] = i;
            b[i] = a[i];
            nums.erase(a[i]);
        }
    }

    for (int i = 0; i < n; i++) {
        if (b[i] == 0) b[i] = *nums.begin(), nums.erase(nums.begin());
        cout << b[i] << ' ';
    }
    cout << endl;
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
