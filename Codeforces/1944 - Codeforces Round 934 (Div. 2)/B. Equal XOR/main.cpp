// ﷽
// https://codeforces.com/contest/1944/problem/B

#include <bits/stdc++.h>
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
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define minit(v, x) v = min(v, x)
#define maxit(v, x) v = max(v, x)

void solve() {
    int n, k;
    cin >> n >> k;

    int a[2 * n];
    map<int, int> fr1, fr2;
    for (int i = 0; i < 2 * n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) {
        fr1[a[i]]++;
    }
    for (int i = n; i < n << 1; i++) {
        fr2[a[i]]++;
    }

    vector<int> one[2], two[2];
    for (auto [x, f]: fr1) {
        if (f == 1) one[0].push_back(x);
        else two[0].push_back(x);
    }
    for (auto [x, f]: fr2) {
        if (f == 1) one[1].push_back(x);
        else two[1].push_back(x);
    }

    vector<int> ans1, ans2;

    while (ans1.size() < 2 * k) {
        if (two[0].size()) {
            ans1.push_back(two[0].back());
            ans1.push_back(two[0].back());
            ans2.push_back(two[1].back());
            ans2.push_back(two[1].back());
            two[0].pop_back();
            two[1].pop_back();
        } else {
            ans1.push_back(one[0].back());
            ans2.push_back(one[0].back());
            one[0].pop_back();
        }
    }

    for (auto x: ans1) cout << x << ' ';
    cout << endl;
    for (auto x: ans2) cout << x << ' ';
    cout << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
