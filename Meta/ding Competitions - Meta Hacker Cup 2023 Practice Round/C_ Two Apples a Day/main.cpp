// ﷽
// https://www.facebook.com/codingcompetitions/hacker-cup/2023/practice-round/problems/C?source=codeforces
// Meta Coding Competitions -> Meta Hacker Cup 2023 Practice Round -> C: Two Apples a Day

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

int solve(const vector<int> &a) {
    int mn = 2e9;
    int n = a.size();

    int i = 1;
    while (i < n / 2 && a[i] + a[n - i - 1] == a[0] + a[n - 1]) {
        i++;
    }

    int j = n / 2;
    while (j > 1 && a[j - 1] + a[n - j + 1] == a[n / 2] + a[n / 2 + 1]) {
        j--;
    }

    for (int k = n / 2; k >= 2; k--) {
        if (k - 2 < i && k >= j && a[n / 2] + a[n / 2 + 1] == a[0] + a[n - 1] && a[0] + a[n - 1] - a[k - 1] > 0) {
            mn = min(mn, a[0] + a[n - 1] - a[k - 1]);
        }
    }

    if (i == n / 2 && a[0] + a[n - 1] - a[n / 2] > 0)
        mn = min(mn, a[0] + a[n - 1] - a[n / 2]);
    if (j == 1 && a[n / 2] + a[n / 2 + 1] - a[0] > 0)
        mn = min(mn, a[n / 2] + a[n / 2 + 1] - a[0]);

    // debug(i, j, mn);
    // debug(a);

    return mn;
}

void solve() {
    int n;
    cin >> n;

    n = n * 2 - 1;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    if (n == 1) {
        cout << 1 << endl;
        return;
    }

    int mn = 2e9;
    sort(all(a));
    mn = min(mn, solve(a));
    reverse(all(a));
    mn = min(mn, solve(a));

    cout << (mn == 2e9 ? -1 : mn) << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
        cout << "Case #" << i << ": ", solve();

    return 0;
}
