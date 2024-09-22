// ﷽
// https://atcoder.jp/contests/abc371/tasks/abc371_b

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
#define sz(v) (int) (v).size()
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define minit(v, x...) v = min({v, x})
#define maxit(v, x...) v = max({v, x})

template<class T>
using rpq = priority_queue<T, vector<T>, greater<T>>;

void solve() {
    int n , m;
    cin >> n >> m;

    map<int, int> mp;

    for (int i = 0; i < m; i++) {
        int a;
        char b;
        cin >> a >> b;
        if (b == 'M') {
            if (!mp[a]) {
                mp[a] = true;
                cout << "Yes\n";
                continue;
            } 
        }
        cout << "No\n";
    }
}

int32_t main(int32_t argc, char **argv) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int t = 1;
    while (t--)
        solve();

    return 0;
}