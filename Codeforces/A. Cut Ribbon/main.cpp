#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long
#define ll long long
#define vi vector<int>
#define vb vector<bool>
#define pii pair<int, int>

int n, a, b, c;
int memo[4001];

int doit(int n) {
    if (n < 0) return 0;
    int &ans = memo[n];
    if (ans != -1) return ans;

    if (n == a || n == b || n == c) ans = 1;

    int p;
    p = doit(n - a);
    if (p) ans = max(ans, p + 1);
    p = doit(n - b);
    if (p) ans = max(ans, p + 1);
    p = doit(n - c);
    if (p) ans = max(ans, p + 1);

    return ans;
}

void solve() {
    memset(memo, -1, sizeof memo);
    cin >> n >> a >> b >> c;
    cout << doit(n) << endl;
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
