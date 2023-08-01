// ﷽
#include <bits/stdc++.h>

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

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    const int N = 1e6;
    vector<int> mp(N + 1);
    for (int i = 2; i <= N; i++) {
        if (mp[i] != 0) continue;
        for (int j = i; j <= N; j+=i)
            mp[j] = i;
    }

    int n;
    cin >> n;
    while (n--) {
        int x; cin >> x;
        map<int, int> primes;
        int m = mp[x];
        while (m != 0) {
            primes[m]++;
            x /= m;
            m = mp[x];
        }
        int r = 1;
        for (auto [p, fr] : primes) {
            r *= (fr + 1);
        }
        cout << r << endl;
    }

    return 0;
}
