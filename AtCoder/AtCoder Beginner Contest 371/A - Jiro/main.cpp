// ﷽
// https://atcoder.jp/contests/abc371/tasks/abc371_a

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
    char ab, ac, bc;
    cin >> ab >> ac >> bc;


    if (ab == '<') {
        if (bc == '<') {
            cout << 'B' << endl;
        } else if (ac == '<') {
            cout << 'C' << endl;
        } else {
            cout << 'A' << endl;
        }
    }

    // a c b 

    if (ab == '>') {
        if (bc == '>') {
            cout << 'B' << endl;
        } else if (ac == '>') {
            cout << 'C' << endl;
        } else {
            cout << 'A' << endl;
        }
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
