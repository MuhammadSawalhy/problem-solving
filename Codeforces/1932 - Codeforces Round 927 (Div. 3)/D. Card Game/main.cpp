// ﷽
// https://codeforces.com/contest/1932/problem/D

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

void solve() {
    int n;
    cin >> n, n = n * 2;
    char c;
    cin >> c;
    string s[n];
    map<char, map<int, int>> fr;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        fr[s[i][1]][s[i][0] - '0']++;
    }

    vector<pair<string, string>> ans;
    vector<string> nons, ts;

    for (char s: "CDHS") {
        if (s == c) continue;
        int l = 2, r = 9;
        while (l < r) {
            if (fr[s][r] == 0) {
                r--;
                continue;
            }

            if (fr[s][l] == 0) {
                l++;
                continue;
            }

            ans.push_back({to_string(l) + s, to_string(r) + s});

            fr[s][r]--;
            fr[s][l]--;
        }

        while (fr[s][l]--) {
            nons.push_back(to_string(l) + s);
        }
    }

    int l = 2, r = 9;

    while (l < r) {
        if (fr[c][r] == 0) {
            r--;
            continue;
        }
        if (fr[c][l] == 0) {
            l++;
            continue;
        }

        if (fr[c][l] && nons.size() > ts.size()) {
            fr[c][l]--;
            ts.push_back(to_string(l) + c);
            continue;
        }

        ans.push_back({to_string(l) + c, to_string(r) + c});

        fr[c][r]--;
        fr[c][l]--;
    }

    while (fr[c][l]-- && nons.size() > ts.size()) {
        ts.push_back(to_string(l) + c);
    }

    if (ts.size() != nons.size()) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        while (ts.size()) {
            ans.push_back({nons.back(), ts.back()});
            nons.pop_back();
            ts.pop_back();
        }
        for (auto p: ans) {
            cout << p.first << " " << p.second << endl;
        }
    }
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
