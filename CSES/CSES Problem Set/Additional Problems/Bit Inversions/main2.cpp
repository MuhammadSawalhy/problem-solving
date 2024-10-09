// ﷽
// https://cses.fi/problemset/task/1188

#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
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
    string s;
    cin >> s;

    set<pii> parts;
    multiset<int> len;

    auto getpart = [&](int i) {
        return *prev(parts.lower_bound({i + 1, 0}));
    };

    auto addpart = [&](pii part) {
        parts.insert(part);
        len.insert(part.second - part.first + 1);
    };

    auto rempart = [&](pii part) {
        parts.erase(part);
        len.erase(len.find(part.second - part.first + 1));
    };

    int n = sz(s);
    for (int i = 0, j = 0; i < n;) {
        while (j < n && s[i] == s[j]) j++;
        addpart({i, j - 1});
        i = j;
    }

    int m;
    cin >> m;
    while (m--) {
        int i;
        cin >> i, i--;

        auto part = getpart(i);
        rempart(part);
        debug(i, part);

        if (i > part.first) {
            addpart({part.first, i - 1});
        }

        if (i < part.second) {
            addpart({i + 1, part.second});
        }

        int l = i, r = i;

        if (i > 0 && i == part.first && s[i] != s[i - 1]) {
            // merge with right
            auto another = getpart(i - 1);
            rempart(another);
            l = another.first;
        }

        if (i < n - 1 && i == part.second && s[i] != s[i + 1]) {
            // merge with left
            auto another = getpart(i + 1);
            rempart(another);
            r = another.second;
        }

        debug(l, r);
        debug(parts);

        addpart({l, r});
        cout << *len.rbegin() << ' ';

        s[i] = (s[i] == '1' ? '0' : '1');
    }
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
