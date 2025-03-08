#include <bits/stdc++.h>
using namespace std;
#define int long long

#ifdef SAWALHY
#include "debug.hpp"
#else
#define debug(...) 0
#define debug_itr(...) 0
#define debug_bits(...) 0
#endif


void solve() {
    string s;
    cin >> s;
    int n = s.size();


    int m = 0;
    while (m < n / 2 && s[n / 2 + m] == s[n / 2 - m - 1]) m++;

    int l = 0;
    while (l < n / 2 && s[l] == s[n - l - 1]) l++;

    debug(s);
    debug(m, l);

    if (m == n / 2) {
        assert(l == n / 2);
        cout << "0\n";
        return;
    }

    s = s.substr(l, n - 2 * l);
    n = s.size();
    debug(s);
    assert(m * 2 < n);

    map<char, int> fr1, fr2;

    for (int i = 0, j = n - 1; i < n / 2 - m; i++, j--) {
        fr1[s[i]]++;
        fr2[s[j]]++;
    }

    if (fr1 == fr2) {
        cout << n / 2 - m << endl;
        return;
    }

    int ans1 = n, ans2 = n;


    fr1.clear(), fr2.clear();

    for (int i = 0; i < n; i++) {
        fr1[s[i]]++;
    }

    for (int i = 0; i < n / 2; i++) {
        fr1[s[i]]--;
        fr2[s[i]]++;
    }

    for (int i = n / 2; i < n; i++) {
        fr1[s[i]]--;
        fr2[s[i]]++;

        bool ok = true;
        for (char c = 'a'; c <= 'z'; c++) {
            ok &= fr2[c] >= fr1[c];
        }

        if (ok) {
            ans1 = i + 1;
            break;
        }
    }

    fr1.clear(), fr2.clear();

    for (int i = 0; i < n; i++) {
        fr2[s[i]]++;
    }

    for (int i = n / 2; i < n; i++) {
        fr2[s[i]]--;
        fr1[s[i]]++;
    }

    for (int i = n / 2 - 1; i >= 0; i--) {
        fr2[s[i]]--;
        fr1[s[i]]++;

        bool ok = true;
        for (char c = 'a'; c <= 'z'; c++) {
            ok &= fr1[c] >= fr2[c];
        }

        if (ok) {
            ans2 = n - i;
            break;
        }
    }

    cout << min(ans1, ans2) << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);

    int T = 1;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        solve();
    }

    return 0;
}
