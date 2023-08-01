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

const int N = 1e6 + 6;
vector<vector<int>> divs(N);

void solve() {
    int n;
    cin >> n;

    if (n == 0) {
        cout << 0 << endl;
    }

    int ans = 0;
    for (auto div : divs[n]) {
        int x = div;
        int y = n / x - 1;
        ans += y;
    }

    cout << ans/ 2 << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    for (int i = 1; i < N; i++) {
        for (int j =i ; j < N; j+= i) {
            divs[j].push_back(i);
        }
    }

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
