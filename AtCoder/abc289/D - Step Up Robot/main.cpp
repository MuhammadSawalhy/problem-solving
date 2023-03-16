// ﷽
#include <iostream>

using namespace std;

#ifdef SAWALHY
#include "debug.hpp"
#else
#define debug(...)
#define debug_itr(...)
#define debug_bits(...)
#endif

#define int long long
#define ll long long
#define all(v) v.begin(), v.end()

const int N = 10 + 1, M = 1e5 + 1;
int n, m;
int traps[M];
bool dp[M];

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> n;

    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    cin >> m;
    for (int i = 0, x; i < m; i++) {
        cin >> x, traps[x] = true;
    }

    int x;
    cin >> x;

    dp[0] = 1;
    for (int i = 0; i < x; i++) {
        if (traps[i]) continue;
        for (int j = 0; j < n; j++)
            dp[i + a[j]] = dp[i + a[j]] || dp[i];
    }

    cout << (dp[x] ? "Yes" : "No") << endl;

    return 0;
}
