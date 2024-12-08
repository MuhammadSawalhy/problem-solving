#include <bits/stdc++.h>
using namespace std;

int dp[251][251][251];
int32_t main(int32_t argc, char **argv) {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, q;
    cin >> n >> q;

    string s;
    cin >> s;

    int nxt[n][26];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 26; j++) {
            nxt[i][j] = n;
        }
    }

    for (int i = n - 1; i >= 0; i--) {
        if (i + 1 < n)
            for (int j = 0; j < 26; j++) nxt[i][j] = nxt[i + 1][j];
        nxt[i][s[i] - 'a'] = i;
    }

    string r[3];

    auto getdp = [&](int i, int li, int j, int lj, int k, int lk) {
        pair<int, int> vals[] = {{i, li}, {j, lj}, {k, lk}};
        sort(vals, vals + 3);
        return dp[vals[0].second][vals[1].second][vals[2].second];
    };

    auto setdp = [&](int i, int li, int j, int lj, int k, int lk, int val) {
        pair<int, int> vals[] = {{i, li}, {j, lj}, {k, lk}};
        sort(vals, vals + 3);
        dp[vals[0].second][vals[1].second][vals[2].second] = val;
    };

    dp[0][0][0] = -1;

    while (q--) {
        char type, c;
        int i;
        cin >> type >> i;
        i--;
        if (type == '+') cin >> c, r[i] += c;
        if (type == '-')
            r[i].pop_back();

        set<int> ind{0, 1, 2};
        ind.erase(i);

        int j = *ind.begin();
        int k = *ind.rbegin();

        int li = r[i].size();
        for (int lj = 0; lj <= r[j].size(); lj++) {
            for (int lk = 0; lk <= r[k].size(); lk++) {
                if (li == 0 && lj == 0 && lk == 0) continue;
                int ans = n;
                int ind;
                if (li - 1 >= 0) {
                    ind = getdp(i, li - 1, j, lj, k, lk);
                    if (ind + 1 < n)
                        ans = min(ans, nxt[ind + 1][r[i][li - 1] - 'a']);
                }
                if (lj - 1 >= 0) {
                    ind = getdp(i, li, j, lj - 1, k, lk);
                    if (ind + 1 < n)
                        ans = min(ans, nxt[ind + 1][r[j][lj - 1] - 'a']);
                }
                if (lk - 1 >= 0) {
                    ind = getdp(i, li, j, lj, k, lk - 1);
                    if (ind + 1 < n)
                        ans = min(ans, nxt[ind + 1][r[k][lk - 1] - 'a']);
                }
                setdp(i, li, j, lj, k, lk, ans);
            }
        }

        auto ans = dp[r[0].size()][r[1].size()][r[2].size()];
        cout << (ans != n ? "YES" : "NO") << '\n';
    }

    return 0;
}
