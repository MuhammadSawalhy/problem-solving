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

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    long long ans = 0, sum = 0;
    bitset<200'000> bs;
    bs[1] = 1;
    for (int i = 0; i < n; i++) {
        if (sum < i) break;
        sum += a[i];
        // get the position of the next one after the i-th position
        int min_sum = bs._Find_next(i);
        ans = max(ans, sum - min_sum + 1);
        bs |= bs << a[i];
    }

    cout << ans << endl;

    return 0;
}
