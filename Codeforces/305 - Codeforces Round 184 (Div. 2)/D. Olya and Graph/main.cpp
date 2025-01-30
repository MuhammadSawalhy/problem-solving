#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 1, mod = 1e9 + 7;
int p2[N];
bool flag[N];

int32_t main(int32_t argc, char **argv) {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, m, k;
    cin >> n >> m >> k;

    vector<int> pos;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v, --u, --v;
        if (v - u == k + 1) pos.push_back(u), flag[u] = true;
        if (v - u != 1 && v - u != k + 1) return cout << "0\n", 0;
    }

    p2[0] = 1;
    for (int i = 1; i <= n; i++) p2[i] = (p2[i - 1] * 2) % mod;

    sort(pos.begin(), pos.end());
    if (pos.size())
        if (pos.back() - pos.front() > k) return cout << "0\n", 0;

    int ans = 1;
    set<int> s;
    for (int i = 0; i + k + 1 < n; i++) {
        s.erase(i - k - 1);
        bool ok = flag[i] == 0;
        if (pos.size()) {
            ok &= i + k + 1 > pos.back();
            ok &= i < pos.front() + k + 1;
        }
        if (ok) {
            ans = (ans + p2[s.size()]) % mod;
            s.insert(i);
        }
    }

    cout << ans << '\n';

    return 0;
}
