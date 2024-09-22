// ﷽
// https://codeforces.com/contest/792/problem/C

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

    int n = sz(s), sum = 0, i = 0, one = 0, two = 0;

    for (int i = 0; i < n; i++) {
        sum = (sum + s[i] - '0') % 3;
        one += (s[i] - '0') % 3 == 1;
        two += (s[i] - '0') % 3 == 2;
    }

    vector<string> ans;

    auto remove = [&](int x, int cnt) {
        string t = s;
        for (int i = n - 1; i >= 0 && cnt; i--)
            if ((s[i] - '0') % 3 == x) t.erase(t.begin() + i), cnt--;
        ans.push_back(t);
    };

    if (sum == 0) ans.push_back(s);
    else if (sum == 1) {
        if (one >= 1) remove(1, 1);
        if (two >= 2) remove(2, 2);
    } else {
        if (one >= 2) remove(1, 2);
        if (two >= 1) remove(2, 1);
    }

    debug(ans);
    string t;
    for (auto a: ans) {
        int i = 0;
        while (i < sz(a) - 1 && a[i] == '0') i++;
        if (sz(a) - i > sz(t)) t = a.substr(i);
    }

    if (sz(t) == 0) return void(cout << -1 << endl);

    cout << t << endl;
    /*270461*/
    /*210101*/
}

int32_t main(int32_t argc, char **argv) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int t = 1;
    while (t--)
        solve();

    return 0;
}
