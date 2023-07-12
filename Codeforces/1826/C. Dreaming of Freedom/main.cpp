// ﷽
#include <bits/stdc++.h>

using namespace std;

#ifdef SAWALHY
#include "debug.hpp"
#else
#define debug(...)      0
#define debug_itr(...)  0
#define debug_bits(...) 0
#endif

#define ll     long long
#define int    long long
#define all(v) v.begin(), v.end()

const int N = 1e6 + 1;
vector<vector<int>> facts(N);

void solve() {
    int n, m;
    cin >> n >> m;

    if (n <= m && n != 1) {
        cout << "NO\n";
        return;
    }

    for (auto f : facts[n]) {
        if (f <= m) {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    for (int i = 2; i < N; i++) {
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
