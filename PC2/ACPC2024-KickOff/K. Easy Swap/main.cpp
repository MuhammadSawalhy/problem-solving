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

void solve() {
    string s;
    cin >> s;
    int i;
    cin >> i, i--;
    int n = s.size();
    string t;
    for (int I = 0; I < n; I++) {
        if (I != i - 1 && I != i + 1) t += s[I];
    }

    sort(all(t));
    debug(t);

    int x = i > 0, y = i < n - 1;

    for (int I = 0; I < t.size(); I++) {
        if (I < i - x)
            s[I] = t[I];
        else if (I + x == i)
            s[I + x] = t[I];
        else
            s[I + x + y] = t[I];
    }

    cout << s << endl;
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
