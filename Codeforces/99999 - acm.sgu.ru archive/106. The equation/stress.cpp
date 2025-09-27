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

#define ll long long
#define all(v) v.begin(), v.end()

void solve() {
    int a, b, c, x1, x2, y1, y2;
    cin >> a >> b >> c >> x1 >> x2 >> y1 >> y2;
    int ans = 0;
    for (int x = x1; x <= x2; x++) {
        for (int y = y1; y <= y2; y++) {
            if (a * x + b * y + c == 0) {
                ans++;
            }
        }
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int t = 1;
    while (t--)
        solve();

    return 0;
}
