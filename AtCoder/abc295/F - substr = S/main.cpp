// ﷽
#include <algorithm>
#include <array>
#include <assert.h>
#include <chrono>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <string.h>
#include <utility>
#include <vector>

using namespace std;

#ifdef SAWALHY
#include "debug.hpp"
#else
#define debug(...) 0
#define debug_itr(...) 0
#define debug_bits(...) 0
#endif

#define int long long
#define ll long long
#define all(v) v.begin(), v.end()

string S;
ll s, l, r;
ll dp[18][18][2][2][2];


int next(int j, int d) {
    for (int i = 0; i <= j; i++) {
        if (S.substr(i, j - i) + char(d + '0') == S.substr(0, j - i + 1)) {
            return j - i + 1;
        }
    }

    return 0;
}

ll solve(int i, int j, bool A, bool B, ll p, bool start) {
    if (p == 0) return debug(i, j, A, B), j == S.size();
    ll &ans = dp[i][j][A][B][start];
    if (~ans) return ans;

    ans = 0;
    if (j == S.size()) {
        if (A && B) {
            ans += r % (p * 10) - l % (p * 10) + 1;
        } else if (A) {
            ans += p * 10 - l % (p * 10);
        } else if (B) {
            ans += r % (p * 10) + 1;
        } else {
            ans += p * 10;
        }
        debug(i, j, A, B, l % p, ans);
    }

    for (int d = (A ? l /p % 10 : 0); d <= (B ? r / p % 10 : 9); d++) {
        ans += solve(i + 1, (start && d == 0) ? 0 : next(j, d), A && d == (l / p % 10), B && d == (r / p % 10), p / 10, start && d == 0);
    }

    return ans;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        cin >> S >> l >> r;
        s = stoll(S);
        ll p = 1e16;
        memset(dp, -1, sizeof dp);
        cout << solve(0, 0, 1, 1, p, 1) << '\n';
    }

    return 0;
}
