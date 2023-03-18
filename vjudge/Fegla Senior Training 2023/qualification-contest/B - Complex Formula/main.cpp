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
    cin >> n;

    ll ans = 0;

    const int N = 1e6 + 1;
    vector<int> facts(N);

    for (int i = 1; i < N; i++) {
        for (int j = i; j < N; j += i)
            facts[j]++;
    }

    for (int x = 1; x <= n / 3; x++) {
        if ((n - x * 3) % 7 != 0) continue;
        int y = (n - x * 3) / 7;
        ans += facts[y];
    }

    cout << ans << endl;

    return 0;
}
