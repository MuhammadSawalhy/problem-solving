// ﷽
#include <bits/stdc++.h>

using namespace std;

#ifdef SAWALHY
#include "debug.hpp"
#else
#define debug(...)
#define debug_itr(...)
#define debug_bits(...)
#endif

#define int long long
#define ll long long
#define all(v) v.begin(), v.end()

template<class T>
void choose(int cnt, vector<T> &v, vector<vector<T>> &res, int i = 0,
            vector<T> choosen = vector<T>()) {

    if (cnt == 0) {
        res.push_back(choosen);
        return;
    }

    if (i >= (int) v.size())
        return;

    choosen.push_back(v[i]);
    choose(cnt - 1, v, res, i + 1, choosen);
    choosen.pop_back();
    choose(cnt, v, res, i + 1, choosen);
}

int n, k;
string a, b;

long long solve(vector<char> &x) {
    string A = a;
    vector<bool> e(200);
    for (int i = 0; i < (int) x.size(); i++) {
        e[x[i]] = true;
    }
    for (int i = 0; i < n; i++) {
        if (e[A[i]]) {
            A[i] = b[i];
        }
    }
    debug(x, A);

    long long ans = 0;

    long long cnt = 0;
    for (int i = 0; i < n; i++) {
        if (A[i] == b[i]) {
            cnt++;
        } else {
            ans += cnt * (cnt + 1) / 2;
            cnt = 0;
        }
    }

    ans += cnt * (cnt + 1) / 2;

    return ans;
}

void solve() {
    cin >> n >> k;
    cin >> a >> b;

    set<char> chars;
    for (int i = 0; i < n; i++) {
        chars.insert(a[i]);
    }

    vector<char> c(all(chars));
    vector<vector<char>> ch;

    if (c.size() <= k) {
        cout << solve(c) << endl;
        return;
    }

    choose(k, c, ch);

    long long ans = 0;
    for (auto &x: ch) {
        ans = max(ans, solve(x));
    }

    cout << ans << endl;
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
