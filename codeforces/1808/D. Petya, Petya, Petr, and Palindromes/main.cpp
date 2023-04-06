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

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n, k;
    cin >> n >> k;

    map<int, int> fr[2];

    int a[n + 1];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    set<int> ind;
    int cnt[2];
    fr[(k - 1) & 1][a[k - 1]]++;
    ind.insert(k - 1);
    cnt[0] = 1;
    cnt[1] = 0;

    ll ans = 0;

    for (int i = 0, j = k - 2; i < n - k / 2 - 1; i++, j--) {
        ans += cnt[i & 1] - fr[i & 1][a[i]];

        if (i + k < n)
            fr[(i + k) & 1][a[i + k]]++, cnt[(i + k) & 1]++, ind.insert(i + k);
        if (j > k / 2)
            fr[j & 1][a[j]]++, cnt[j & 1]++, ind.insert(j);

        while (ind.size() && *ind.begin() <= i) {
            cnt[(*ind.begin()) & 1]--;
            fr[(*ind.begin()) & 1][a[*ind.begin()]]--;
            ind.erase(ind.begin());
        }
        while (ind.size() && *prev(ind.end()) >= n - (i + k + 1 - n)) {
            cnt[(*prev(ind.end())) & 1]--;
            fr[(*prev(ind.end())) & 1][a[*prev(ind.end())]]--;
            ind.erase(prev(ind.end()));
        }
    }

    cout << ans;

    return 0;
}
