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

void solve() {
    int n, k, m;
    cin >> n >> k >> m;

    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int i = 0, j = n;
    while (i < n && a[i] == 0)
        i++;
    while (j > i && a[j - 1] == 0)
        j--;

    vector<int> tocover;
    for (int l = i; l < j; l++) {
        int cnt = 0;
        while (a[l] == 0) {
            cnt++;
            l++;
        }
        tocover.push_back(cnt);
    }

    sort(tocover.rbegin(), tocover.rend());

    cout << accumulate(all(tocover), 0LL) - accumulate(tocover.begin(), tocover.begin() + min((k + m - 1), (int)tocover.size()), 0LL) << endl;
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
