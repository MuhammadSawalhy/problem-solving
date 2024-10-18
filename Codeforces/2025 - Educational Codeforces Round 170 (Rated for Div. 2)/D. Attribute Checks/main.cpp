// ﷽
// https://codeforces.com/contest/2025/problem/D

#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T, null_type, std::less<T>, rb_tree_tag, tree_order_statistics_node_update>;

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
#define vi vector<int>
#define vvi vector<vector<int>>
#define pii pair<int, int>
#define vvi vector<vector<int>>
#define sz(v) (int) (v).size()
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define minit(v, x...) v = min({v, x})
#define maxit(v, x...) v = max({v, x})

template<class T>
using rpq = priority_queue<T, vector<T>, greater<T>>;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> r(n);
    for (int i = 0; i < n; i++) {
        cin >> r[i];
    }

    ordered_set<pii> os[m + 1][2];


    int i = 0, k = 0;
    while (i < n && r[i] != 0) {
        if (r[i] > 0) os[0][0].insert({r[i], i});
        else os[0][1].insert({-r[i], i});
        i++;
    }

    for (; i < n;) {
        k++;
        int j = i + 1;
        while (j < n && r[j] != 0) {
            if (r[j] > 0) os[k][0].insert({r[j], j});
            else os[k][1].insert({-r[j], j});
            j++;
        }
        i = j;
    }

    assert(k == m);

    vi dp(m + 1);

    for (int i = 0; i < m; i++) {
        vi newdp(m + 1);

        for (int j = 0; j <= i; j++) {
            {
                int x = j, y = i + 1 - j;
                int delta1 = os[i + 1][0].order_of_key({x + 1, 0});
                int delta2 = os[i + 1][1].order_of_key({y + 1, 0});
                maxit(newdp[j], dp[j] + delta1 + delta2);
            }
            {
                int x = j + 1, y = i + 1 - j - 1;
                int delta1 = os[i + 1][0].order_of_key({x + 1, 0});
                int delta2 = os[i + 1][1].order_of_key({y + 1, 0});
                debug(os[i + 1][1]);
                maxit(newdp[j + 1], dp[j] + delta1 + delta2);
            }
        }

        swap(dp, newdp);
        debug(i, dp);
    }

    cout << *max_element(all(dp)) << '\n';
}

int32_t main(int32_t argc, char **argv) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int T = 1;
    for (int t = 1; t <= T; t++) {
        debug("--------", t);
        solve();
    }

    return 0;
}
