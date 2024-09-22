// ﷽
// https://codeforces.com/contest/2003/problem/C

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
    int n;
    cin >> n;
    string s;
    cin >> s;

    vector<pii> fr(26);

    for (int i = 0; i < 26; i++) {
        fr[i].second = i;
    }
    for (int i = 0; i < n; i++) {
        fr[s[i] - 'a'].first++;
    }

    sort(rall(fr));

    string t;
    while (fr.back().first == 0) fr.pop_back();
    while (fr.size()) {
        for (int i = 0; i < sz(fr); i++) {
            t += fr[i].second + 'a';
            fr[i].first--;
        }
        while (fr.size() && fr.back().first == 0) fr.pop_back();
    }

    cout << t << endl;
}

int32_t main(int32_t argc, char **argv) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int t = 1;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
