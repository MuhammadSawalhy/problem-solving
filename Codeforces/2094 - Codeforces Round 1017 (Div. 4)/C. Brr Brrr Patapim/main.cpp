#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define all(v) begin(v), end(v)
#define rall(v) rbegin(v), rend(v)

void solve() {
    int n;
    cin >> n;
    int p[n * 2];

    set<int> s;
    for (int i = 1; i <= 2 * n; i++) s.insert(i);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int x;
            cin >> x;
            p[i + j + 1] = x;
            s.erase(x);
        }
    }

    p[0] = *s.begin();
    for (auto x : p) cout <<x << ' ';
    cout << endl;
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
