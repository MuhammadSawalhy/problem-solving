// ﷽
#include <bits/stdc++.h>

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

    const int N = 1e6 + 1;
    vector<int> p(N);

    for (int i = 2; i < N; i += (i & 1) + 1) {
        if (p[i] != 0) continue;
        for (int j = i; j < N; j+=i) {
            int k = j;
            while (k % i == 0) {
                p[j]++;
                k /= i;
            }
        }
    }

    for (int i = 1; i < N; i++)
        p[i] += p[i - 1];

    int n;
    while (cin >> n) {
        cout << p[n] << endl;
    }

    return 0;
}
