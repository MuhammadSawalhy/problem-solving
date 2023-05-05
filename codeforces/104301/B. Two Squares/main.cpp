// ﷽
#include <bits/stdc++.h>

using namespace std;

#ifdef SAWALHY
#include "debug.hpp"
#else
#define debug(...) 0
#define debug_itr(...) 0
#define debug_bits(...) 0
#endif

#define int long long
#define ll long long
#define all(v) v.begin(), v.end()

const int N = 1e7 + 7;
int ans[N];

void solve() {
    int n;
    cin >> n;
    cout << ans[n] << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    for (int a = 0; a * a < N; a++) {
        for (int b = 0; b * b + a * a < N; b++) {
            ans[a * a + b * b] = 1;
        }
    }

    for (int i = 1; i < N; i++)
        ans[i] += ans[i - 1];

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
