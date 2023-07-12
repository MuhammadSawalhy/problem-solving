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

void solve() {
    int sz;
    cin >> sz;

    vector<int> wi, iw, in, ni, wn, nw;

    string s[sz];
    for (int j = 0; j < sz; j++) {
        cin >> s[j];
        int w = (s[j][0] == 'w') + (s[j][1] == 'w') + (s[j][2] == 'w');
        int i = (s[j][0] == 'i') + (s[j][1] == 'i') + (s[j][2] == 'i');
        int n = (s[j][0] == 'n') + (s[j][1] == 'n') + (s[j][2] == 'n');

        if (w > 1 && i == 0) wi.push_back(j);
        if (w > 1 && n == 0) wn.push_back(j);
        if (i > 1 && w == 0) iw.push_back(j);
        if (i > 1 && n == 0) in.push_back(j);
        if (n > 1 && i == 0) ni.push_back(j);
        if (n > 1 && w == 0) nw.push_back(j);
    }

    vector<pair<pair<int, char>, pair<int, char>>> ans;

    auto doit = [&]() {
        while (iw.size() && wi.size()) {
            ans.push_back({{iw.back(), 'i'}, {wi.back(), 'w'}});
            iw.pop_back();
            wi.pop_back();
        }

        while (ni.size() && in.size()) {
            ans.push_back({{ni.back(), 'n'}, {in.back(), 'i'}});
            in.pop_back();
            ni.pop_back();
        }

        while (nw.size() && wn.size()) {
            ans.push_back({{nw.back(), 'n'}, {wn.back(), 'w'}});
            nw.pop_back();
            wn.pop_back();
        }
    };

    doit();

    vector<pair<tuple<vector<int> &, vector<int> &, vector<int> &>, pair<char, char>>> x = {
            {{wn, iw, in}, {'w', 'i'}},
            {{wi, ni, ni}, {'w', 'n'}},
            {{ni, wn, wi}, {'n', 'w'}},
            {{nw, in, iw}, {'n', 'i'}},
            {{in, wi, wn}, {'i', 'w'}},
            {{iw, ni, nw}, {'i', 'n'}},
    };

    for (auto &[v, c]: x) {
        auto &[source, target, other] = v;
        auto &[c1, c2] = c;

        while (source.size() && target.size()) {
            ans.push_back({{source.back(), c1}, {target.back(), c2}});
            target.pop_back();
            other.push_back(source.back());
            source.pop_back();
        }

        doit();
    }

    cout << ans.size() << endl;
    for (auto [s, e]: ans) {
        auto [i, c] = s;
        auto [j, k] = e;
        cout << i + 1 << " " << c << " " << j + 1 << " " << k << endl;
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
