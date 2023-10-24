// ﷽
// https://codeforces.com/contest/1884/problem/D

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

const int N = 1e6 + 1;
vector<int> facts[N];
bool ex[N];


void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        ex[a[i]] = true;
    }


    sort(all(a));

    for (int i = 0; i < n; i++) {
        for (auto f : facts[i] ) {

        }
    }

    for (int i = 0; i < n; i++) {
        ex[a[i]] = false;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    for (int i = 1; i < N; i++) {
        for (int j = i; j < N; j += i) {
            facts[j].push_back(i);
        }
    }

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
