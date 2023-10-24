// ﷽
// https://codeforces.com/contest/1884/problem/B

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

int sum(int a, int b) {
    b--;
    return a * (a + 1) / 2 - b * (b + 1) / 2;
}

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    reverse(all(s));
    int onepos[n + 1];
    int one[n + 1];
    int zeropos[n + 2];
    int zero[n + 2];
    onepos[0] = one[0] = 0;
    zeropos[n + 1] = 0;
    zero[n + 1] = 0;
    for (int i = 0; i < n; i++) {
        onepos[i + 1] = onepos[i] + (s[i] == '1') * (i + 1);
        one[i + 1] = one[i] + (s[i] == '1');
    }
    for (int i = n; i >= 1; i--) {
        zeropos[i] = zeropos[i + 1] + (s[i - 1] == '0') * i;
        zero[i] = zero[i + 1] + (s[i - 1] == '0');
    }

    debug(s);
    for (int i = 1; i <= n; i++) {
        if (one[n] + i > n) {
            cout << "-1 ";
        } else {
            if (one[i] == 0) {
                cout << "0 ";
                continue;
            }
            assert(zero[i + 1] >= one[i]);
            int s = i, e = n + 1;
            while (e - s > 1) {
                int mid = (s + e) / 2;
                if (zero[i + 1] - zero[mid + 1] < one[i]) {
                    s = mid;
                } else {
                    e = mid;
                }
            }
            s++;
            debug(i, s);
            assert(zero[i + 1] - zero[s + 1] == one[i]);
            int x = sum(i + 1, i + one[i]) - onepos[i];
            int y = zeropos[i + 1] - zeropos[s + 1] - sum(i + 1, i + one[i]);
            debug(x, y);
            cout << (x + y) << " ";
        }
    }

    cout << '\n';
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
