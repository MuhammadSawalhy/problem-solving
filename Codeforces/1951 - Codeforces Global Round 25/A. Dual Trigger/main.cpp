// ﷽
// https://codeforces.com/contest/1951/problem/A

#include <algorithm>
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

    int ones = count(all(s), '1');
    if (ones & 1) {
        cout << "NO\n";
    } else {
        if (ones == 2) {
            for (int i = 0; i + 1 < n; i++) {
                if (s[i] == s[i + 1] && s[i] == '1') {
                    cout << "NO\n";
                    return;
                }
            }
            cout << "YES\n";
        } else {
            cout << "YES\n";
        }
    }
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
