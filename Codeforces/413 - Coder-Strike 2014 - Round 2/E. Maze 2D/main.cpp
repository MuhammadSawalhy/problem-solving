#include <bits/stdc++.h>
using namespace std;

template<class T>
using rpq = priority_queue<T, vector<T>, greater<T>>;

int32_t main(int32_t argc, char **argv) {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, q;
    cin >> n >> q;

    string s[2];
    cin >> s[0] >> s[1];
    s[0] = "X" + s[0];
    s[1] = "X" + s[1];

    vector<int> ps(n + 1);
    vector<int> comp(n + 1, -1);
    vector<vector<int>> ind;
    vector<int> onedot;

    auto getdir = [&](int i) {
        if (s[0][i] == '.' && s[1][i] == 'X') return 0;
        if (s[0][i] == 'X' && s[1][i] == '.') return 1;
        return -1;
    };

    for (int i = 1, COMP = 0, lastdir = -1; i <= n; i++) {
        ps[i] = ps[i - 1];
        if (s[0][i] == '.' && s[0][i - 1] == '.' || s[1][i] == '.' && s[1][i - 1] == '.')
            comp[i] = comp[i - 1];
        else {
            lastdir = -1;
            comp[i] = ++COMP;
        }

        int curdir = getdir(i);
        if (curdir == -1) continue;
        onedot.push_back(i);

        if (comp[i] == comp[i - 1]) {
            if (lastdir != -1 && curdir != lastdir) {
                ps[i]++;
            }
        }

        lastdir = curdir;
    }

    while (q--) {
        int u, v;
        cin >> u >> v;
        int startdir = 0, enddir = 0;

        if (u > n) u -= n, startdir = 1;
        if (v > n) v -= n, enddir = 1;
        if (u > v) swap(u, v), swap(startdir, enddir);

        if (comp[u] != comp[v]) {
            cout << "-1\n";
            continue;
        }

        int i = lower_bound(onedot.begin(), onedot.end(), u) - onedot.begin();
        int j = upper_bound(onedot.begin(), onedot.end(), v) - onedot.begin() - 1;

        if (j < i) {
            cout << (startdir != enddir) + v - u << endl;
            continue;
        }

        i = onedot[i], j = onedot[j];

        int ans = v - u;
        ans += ps[j] - ps[i];

        int sdir = getdir(i);
        int edir = getdir(j);

        assert(sdir != -1);
        assert(edir != -1);

        if (sdir != startdir) ans++;
        if (edir != enddir) ans++;

        cout << ans << endl;
    }

    return 0;
}
