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

int solve_1(vector<int> atk, vector<int> mine) {
    int ans = 0, i = 1;
    while (i <= min(atk.size(), mine.size())) {
        int val = mine[mine.size() - i] - atk[i - 1];
        if (val < 0) break;
        ans += val;
        i++;
    }
    debug(ans);
    return ans;
}

int solve_2(vector<int> atk, vector<int> def, vector<int> mine) {
    int ans = 0;
    multiset<int> MINE;
    for (auto i: mine) MINE.insert(i);

    // use the min possible to take all def
    // does order of erasing matter? NO!
    while (def.size()) {
        int x = def.back();
        def.pop_back();
        auto it = MINE.upper_bound(x);
        if (it == MINE.end()) return 0;
        MINE.erase(it);
    }

    while (MINE.size() && atk.size()) {
        int x = *prev(MINE.end());
        if (x < atk.back()) return 0;
        ans += x - atk.back();
        atk.pop_back();
        MINE.erase(prev(MINE.end()));
    }

    if (atk.size()) return 0;

    while (MINE.size()) {
        ans += *prev(MINE.end());
        MINE.erase(prev(MINE.end()));
    }

    return ans;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    string type;
    int x;

    vector<int> atk, def;

    for (int i = 0; i < n; i++) {
        cin >> type >> x;
        if (type == "ATK")
            atk.push_back(x);
        else {
            def.push_back(x);
        }
    }

    vector<int> mine(m);
    for (int i = 0; i < m; i++) {
        cin >> mine[i];
    }

    sort(all(atk));
    sort(all(def));
    sort(all(mine));
    debug(atk);
    debug(mine);

    cout << max(solve_1(atk, mine), solve_2(atk, def, mine)) << endl;

    return 0;
}
