// ﷽
// https://codeforces.com/group/qxlLGDBwj5/contest/529356/problem/L

#include <bits/stdc++.h>
#include <ostream>
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
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int current = 1;
    vector<int> b;

    vector<string> ans;

    while (a.size() || b.size()) {
        int x = a.size() ? a.back() : -1;
        int y = b.size() ? b.back() : -1;

        debug(current);
        debug(a);
        debug(b);
        if (x == current) {
            current++;
            a.pop_back();
            ans.push_back("A C");
            continue;
        }

        if (y == current) {
            current++;
            b.pop_back();
            ans.push_back("B C");
            continue;
        }

        if (x == -1) {
            break;
        }

        b.push_back(x);
        a.pop_back();
        ans.push_back("A B");
    }


    if (current != n + 1) {
        cout << -1 << endl;
        return;
    }

    cout << sz(ans) << endl;
    for (auto x: ans) cout << x << endl;
}

int32_t main(int32_t argc, char **argv) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    solve();

    return 0;
}
