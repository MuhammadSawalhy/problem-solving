// ﷽
// https://codeforces.com/contest/1950/problem/E

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
#define sz(v) (int) (v).size()
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define minit(v, x...) v = min({v, x})
#define maxit(v, x...) v = max({v, x})

template<class T>
using rpq = priority_queue<T, vector<T>, greater<T>>;


void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    vector<int> factors;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            factors.push_back(i);
            if (i * i != n && i != 1) factors.push_back(n / i);
        }
    }

    sort(all(factors));

    debug(s);
    debug(n, factors);

    for (auto f: factors) {
        string sub = s.substr(0, f);
        debug(f, sub);

        {
            int diff = 0;
            for (int i = 0; i < n; i += f) {
                for (int j = i; j < i + f; j++) {
                    diff += s[j] != sub[j - i];
                }
            }

            if (diff <= 1) {
                return void(cout << f << endl);
            }
            debug(diff);
        }

        sub = s.substr(f, f);
        debug(f, sub);

        {
            int diff = 0;
            for (int i = 0; i < n; i += f) {
                for (int j = i; j < i + f; j++) {
                    diff += s[j] != sub[j - i];
                }
            }

            if (diff <= 1) {
                return void(cout << f << endl);
            }

            debug(diff);
        }
    }

    cout << n << endl;
}


int32_t main(int32_t argc, char **argv) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
