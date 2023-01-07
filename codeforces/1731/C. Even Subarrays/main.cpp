// Date: 27-12-2022
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define all(v) v.begin(), v.end()
#define debug(...)
#ifdef SAWALHY
#include "debug.hpp"
#endif

int N = 2e5;
vector<int> squares;

void solve() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int px[n];
    vector<int> fr(1 << (32 - __builtin_clz(n)));
    fr[0]++;

    debug(fr.size());

    ll ans = 0;

    for (int i = 0; i < n; i++) {
        px[i] = (i > 0 ? px[i - 1] : 0) ^ a[i];

        ans += i + 1;
        for (auto s : squares) {
            if ((px[i] ^ s) >= fr.size()) continue;
            int cnt = fr[px[i] ^ s];
            ans -= cnt;
        }

        fr[px[i]]++;
    }

    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    ll s = 0;
    while (__builtin_clz(s * s) >= __builtin_clz(N))
        squares.push_back(s * s), s++;

    debug(squares.size());

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
