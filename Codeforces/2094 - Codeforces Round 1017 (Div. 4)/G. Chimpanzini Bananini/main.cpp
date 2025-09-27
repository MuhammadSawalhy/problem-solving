#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define all(v) begin(v), end(v)
#define rall(v) rbegin(v), rend(v)

void solve() {
    int q;
    cin >> q;

    int ans[2]{};
    int sum = 0, n = 0;
    deque<int> dq[2];
    int i = 0, j = 1;
    while (q--) {
        int t, x;
        cin >> t;
        if (t == 1) {
            x = dq[i].back();
            dq[i].pop_back();
            dq[i].push_front(x);
            ans[i] = x + (ans[i] - x * n + (sum - x));

            x = dq[j].front();
            dq[j].pop_front();
            dq[j].push_back(x);
            ans[j] = x * n + (ans[j] - x - (sum - x));
        } else if (t == 2) {
            swap(i, j);
        } else {
            cin >> x;
            dq[i].push_back(x);
            dq[j].push_front(x);
            n++;
            ans[i] += x * n;
            ans[j] += sum + x;
            sum += x;
        }
        cout << ans[i] << '\n';
    }
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
