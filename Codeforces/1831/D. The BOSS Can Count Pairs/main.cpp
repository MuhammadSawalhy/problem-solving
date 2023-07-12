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
#define int long long
#define all(v) v.begin(), v.end()

void solve() {
    int n;
    cin >> n;
    int a[n], b[n];
    vector<int> A(n);

    map<int, int> fr[n + 1];

    for (int i = 0; i < n; i++)
        cin >> a[i], A[i] = a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i], fr[a[i]][b[i]]++;

    sort(all(A));
    A.erase(unique(all(A)), A.end());
    debug(A);

    long long ans = 0;

    for (int i = 0; i < (int) A.size(); i++) {
        int cur = 0;
        for (auto [x, f]: fr[A[i]]) {
            // a[i], a[j], and b[j] are known
            int bi = A[i] * A[i] - x;
            auto it = fr[A[i]].find(bi);
            if (it != fr[A[i]].end())
                cur += bi == x ? f * (f - 1) : it->second * f;
        }
        ans += cur / 2;
        for (int j = 0; j < i && A[i] * A[j] <= 2 * n; j++) {
            for (auto [x, f]: fr[A[i]]) {
                // a[i], a[j], and b[j] are known
                int bj = A[i] * A[j] - x;
                auto it = fr[A[j]].find(bj);
                if (it != fr[A[j]].end())
                    ans += it->second * f;
            }
        }
    }

    cout << ans << '\n';
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
