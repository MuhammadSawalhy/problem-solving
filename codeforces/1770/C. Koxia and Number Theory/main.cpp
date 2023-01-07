// Date: 30-12-2022
#include <bits/stdc++.h>

#define debug(...)
#ifdef SAWALHY
#include "debug.hpp"
#endif

#define int long long
#define ll long long
#define all(v) v.begin(), v.end()

using namespace std;

int primes[] = {
        2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};

void solve() {
    int n;
    cin >> n;
    ll a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<set<int>> ps(100);

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            ll d = abs(a[i] - a[j]);

            if (d == 0) {
                cout << "NO" << endl;
                return;
            }

            for (int p: primes)
                if (d % p == 0)
                    ps[p].insert(a[i] % p);
        }
    }

    for (int p : primes) {
        if (ps[p].size() == p) {
            cout << "NO" << endl;
            return;
        }
    }

    cout << "YES" << endl;
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
