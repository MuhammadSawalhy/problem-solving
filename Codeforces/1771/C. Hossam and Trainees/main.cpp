// Date: 11-12-2022
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define all(v) v.begin(), v.end()
#define debug(...)
#ifdef SAWALHY
#include "debug.hpp"
#endif

vector<int> primes;

void solve() {
    int n;
    cin >> n;
    ll a[n];

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    map<int, bool> exists;
    for (int i = 0; i < n; i++) {
        for (auto p: primes) {
            if (a[i] % p != 0) continue;
            while (a[i] % p == 0) a[i] /= p;

            if (exists[p]) {
                cout << "YES" << endl;
                return;
            }

            exists[p] = true;
        }

        if (a[i] != 1) {
            int p = a[i];

            if (exists[p]) {
                cout << "YES" << endl;
                return;
            }

            exists[p] = true;
        }
    }

    cout << "NO" << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int limit = sqrt(1e9) + 1;
    vector<bool> is_prime(limit, true);
    for (int i = 2; i < limit; i++) {
        if (!is_prime[i]) continue;
        primes.push_back(i);
        for (int j = i + i; j < limit; j += i) {
            is_prime[j] = false;
        }
    }

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
