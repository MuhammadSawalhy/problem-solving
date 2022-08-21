#include <bits/stdc++.h>

// clang-format off
#ifndef ONLINE_JUDGE
#include "/home/ms/myp/problem-solving/debug.hpp"
#else
#define debug(x...)
#define debug_arr(arr, n)
#endif

using namespace std;

#define ull unsigned long long
#define ll long long
#define vi vector<int>
#define vb vector<bool>
#define pii pair<int, int>

#define int ll

#define N 1000001
int a[N];
int n, p, s;
int memo[N][6];

int mindis(int i, int k) {
    if (i == n) return p - a[n];
    int &mdis = memo[i][k];
    if (mdis != -1) return mdis;

    mdis = LONG_LONG_MAX;
    for (int spent = 0; spent <= k; spent++) {
        int j = upper_bound(a, a + n + 1, a[i + 1] + spent * s) - a - 1;
        mdis = min(mdis, mindis(j, k - spent));
    }

    mdis += a[i + 1] - a[i];
    return mdis;
}

void solve() {
    memset(memo, -1, sizeof memo);
    cin >> n >> p >> s;
    a[0] = 0;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int k;
    cin >> k;
    cout << mindis(0, k) << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("/home/ms/myp/problem-solving/input", "r", stdin);
#endif
    solve();
    return 0;
}
