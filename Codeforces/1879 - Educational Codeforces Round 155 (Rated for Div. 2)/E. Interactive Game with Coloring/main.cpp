// ﷽
// https://codeforces.com/contest/1879/problem/E
// Codeforces -> Educational Codeforces Round 155 (Rated for Div. 2) -> E. Interactive Game with Coloring

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

const int N = 101;
vector<int> color(N);
vector<int> adj[N];
bool two_is_used = false;

int dfs(int i, int my_color, bool can_change) {
    // the first node with deg 2 should have prev = 0
    // if it already like that, fake the change to prevent it from happening
    //
    // if a change is done, no more changed can be done

    assert(two_is_used && !can_change || !two_is_used);
    debug(i, my_color + 1, can_change);
    color[i] = my_color;
    int changed = 0;

    if (adj[i].size() == 1 && my_color == 1 && can_change) {
        changed = 1;
    }

    if (adj[i].size() == 1 && i != 0) {
        can_change = false;
    }

    int k = 0;
    for (int j = 0; j < adj[i].size(); j++) {
        int next_color;

        if (adj[i].size() == 1 && my_color != 2 && (my_color ^ (changed & 1))) {
            next_color = 2;
            two_is_used = true;
        } else if (my_color == 2) {
            next_color = 0;
        } else {
            next_color = my_color ^ changed & 1 ^ 1;
        }

        int prev = changed;
        changed |= dfs(adj[i][j], next_color, can_change && (!changed || i == 0) && !two_is_used);
        if (prev & 1 ^ changed & 1) {
            k = j;
        }
    }

    for (int j = 0; j < k; j++) {
        int next_color;

        if (adj[i].size() == 1 && my_color != 2 && (my_color ^ (changed & 1))) {
            next_color = 2;
            two_is_used = true;
        } else if (my_color == 2) {
            next_color = 0;
        } else {
            next_color = my_color ^ changed & 1 ^ 1;
        }

        int prev = changed;
        changed |= dfs(adj[i][j], next_color, can_change && (!changed || i == 0) && !two_is_used);
        if (prev & 1 ^ changed & 1) {
            k = j;
        }
    }

    debug(i, color[i], changed);

    if (changed & 1 && i != 0) {
        assert(color[i] != 2);
        color[i] ^= 1;
    }

    return changed | ((adj[i].size() == 1) << 1);
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n;
    cin >> n;

    for (int i = 1, p; i < n; i++) {
        cin >> p, p--;
        adj[p].push_back(i);
    }

    dfs(0, 2, true);

    int k = *max_element(color.begin() + 1, color.begin() + n) + 1;
    cout << k << endl;
    assert(k <= 3);

    for (int i = 1; i < n; i++) {
        cout << color[i] + 1 << " ";
        assert(0 <= color[i]);
    }

    cout << endl;

    int ans;
next_iter:
    while (cin >> ans) {
        if (ans == 1 || ans == -1) return 0;
        assert(ans == 0);
        int fr[3] = {};

        for (int i = 0; i < k; i++) {
            cin >> fr[i];
        }

        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                if (fr[i] == 1 && fr[j] > 1) {
                    cout << i + 1 << endl;
                    goto next_iter;
                }

        if (fr[0] && fr[1]) {
            cout << 1 << endl;
            goto next_iter;
        }

        if (fr[1] && fr[2]) {
            cout << 2 << endl;
            goto next_iter;
        }

        if (fr[2] && fr[0]) {
            cout << 3 << endl;
            goto next_iter;
        }

        for (int i = 0; i < 3; i++)
            if (fr[i]) {
                cout << i + 1 << endl;
                goto next_iter;
            }
    }

    return 0;
}
