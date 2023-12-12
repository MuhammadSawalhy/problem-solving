// ﷽
// https://atcoder.jp/contests/abc327/tasks/abc327_a

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
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define minit(v, x) v = min(v, x)
#define maxit(v, x) v = max(v, x)

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n;
    string s;
    cin >> n >> s;

    bool ok = false;
    for (int i = 1; i < n; i++) {
        ok |= s[i] == 'a' && s[i - 1] == 'b' || s[i] == 'b' && s[i - 1] == 'a';
    }

    cout << (ok ? "Yes" : "No") << endl;

    return 0;
}
