// Date: 30-12-2022
#include <bits/stdc++.h>

#define debug(...)
#ifdef SAWALHY
#include "debug.hpp"
#endif

#define int long long
#define ll long long
#define all(v) v.begin(), v.end()

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    priority_queue<int, vector<int>, greater<int>> qu;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        qu.push(a);
    }

    for (int i = 0;i < m; i++) {
        int b;
        cin >> b;
        qu.pop();
        qu.push(b);
    }


    ll sum = 0;
    while (qu.size())
        sum += qu.top(), qu.pop();

    cout << sum << endl;
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
