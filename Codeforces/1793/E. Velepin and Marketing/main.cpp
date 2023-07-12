// ﷽
#include <algorithm>
#include <array>
#include <iostream>
#include <map>
#include <queue>
#include <utility>
#include <vector>

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

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];

    sort(a, a + n);

    int q;
    cin >> q;

    pair<int, int> k[q];
    for (int i = 0; i < q; i++)
        cin >> k[i].first, k[i].second = i;

    sort(k, k + q);

    int ans[q];
    ans[0] = 0;
    int last = 0;
    int x = 0;
    for (auto [b, i] : k) {
        // choose reader from n
    
        while (x < b) {
            x++;
        }
        
        ans[i] = last;
    }

    for (int i = 0; i < q; i++)
        cout << ans[i] << endl;

    return 0;
}
