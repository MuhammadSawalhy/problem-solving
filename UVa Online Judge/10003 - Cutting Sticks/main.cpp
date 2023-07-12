#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long
#define ll long long
#define vi vector<int>
#define vb vector<bool>
#define pii pair<int, int>

#define N 51

int n;
int cuts[N];
int dp[N][N];

int mincost(int l, int r) {
    if (r - l == 1)
        return 0;

    int &c = dp[l][r];
    if (c != -1) return c;

    c = INT_MAX;
    for (int i = l + 1; i < r; i++) {
        c = min(c, mincost(i, r) + mincost(l, i));
    }

    c += cuts[r] - cuts[l];

    return c;
}

void solve() {
    int l;
    while (true) {
        cin >> l;
        if (!l) break;
        memset(dp, -1, sizeof dp);
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> cuts[i];
        cuts[0] = 0;
        cuts[n + 1] = l;
        cout << "The minimum cutting is " << mincost(0, n + 1) << "." << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("/home/ms/myp/problem-solving/input", "r", stdin);
#endif
    solve();
    return 0;
}
