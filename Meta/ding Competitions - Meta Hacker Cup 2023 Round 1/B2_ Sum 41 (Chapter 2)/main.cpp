// ﷽
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

map<ll, ll> primefacts(ll n) {
    map<ll, ll> result;
    int r = 0;

    while (n % 2 == 0) {
        r++;
        n = n / 2;
    }

    if (r > 0)
        result[2] = r;

    int sqn = sqrt(n);
    for (int i = 3; i <= sqn; i += 2) {
        r = 0;
        while (n % i == 0) {
            r++;
            n = n / i;
        }
        if (r > 0)
            result[i] = r;
    }

    if (n > 2)
        result[n] = 1;

    return result;
}

vector<int> get_facts(int p) {
    vector<int> facts;
    for (int i = 1; i * i <= p; i++) {
        if (p % i)
            continue;
        facts.push_back(i);
        if (i * i != p)
            facts.push_back(p / i);
    }

    sort(all(facts));
    return facts;
}

void solve() {
    int p;
    cin >> p;
    auto facts = get_facts(p);
    int m = facts.size();
    constexpr int inf = 1e9;
    vector<vector<int>> cnt(m, vector<int>(42, inf));
    vector<vector<int>> par(m, vector<int>(42, -1));
    vector<vector<int>> fac(m);

    auto get_id = [&](int f) {
        return lower_bound(all(facts), f) - facts.begin();
    };

    for (int i = 0; i < m; i++) {
        fac[i] = get_facts(facts[i]);
    }

    for (int i = 0; i < m; i++) {
        if (fac[i].back() <= 41) cnt[i][fac[i].back()] = 1;
        for (auto f: fac[i]) {
            if (f == fac[i].back()) continue;
            int id = get_id(fac[i].back() / f);
            for (int j = 1; f + j <= 41; j++) {
                if (cnt[id][j] + 1 < cnt[i][f + j]) {
                    cnt[i][f + j] = cnt[id][j] + 1;
                    par[i][f + j] = f;
                }
            }
        }
    }

    int mn = inf;
    int sum = -1;
    for (int i = 1; i <= 41; i++) {
        if (cnt[m - 1][i] + 41 - i < mn) {
            mn = cnt[m - 1][i] + 41 - i;
            sum = i;
        }
    }
    debug(p, mn);

    if (sum == -1) {
        cout << "-1\n";
        return;
    }

    vector<int> ans;
    int id = get_id(p);
    while (~par[id][sum]) {
        ans.push_back(par[id][sum]);
        sum = sum - ans.back();
        p /= ans.back();
        id = get_id(p);
    };

    ans.push_back(p);
    ans.resize(mn, 1);
    cout << mn << ' ';
    for (auto &i: ans) cout << i << " \n"[&i == &ans.back()];
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    cout << fixed << setprecision(10);
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cout << "Case #" << i << ": ", solve();
    }

    return 0;
}

