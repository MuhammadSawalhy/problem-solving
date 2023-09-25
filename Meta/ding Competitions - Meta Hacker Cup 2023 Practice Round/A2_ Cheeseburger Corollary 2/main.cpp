// ﷽
// https://www.facebook.com/codingcompetitions/hacker-cup/2023/practice-round/problems/A2?source=codeforces
// Meta Coding Competitions -> Meta Hacker Cup 2023 Practice Round -> A2: Cheeseburger Corollary 2

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
    int a, b, c;
    cin >> a >> b >> c;

    if (a <= b / 2) {
        cout << c / a << endl;
        return;
    }

    if (b <= a) {
        if (c < b) {
            cout << 0 << endl;
            return;
        }

        cout << c / b * 2 - 1 << endl;
        return;
    }

    if (c < a) {
        cout << 0 << endl;
        return;
    }

    // b > a && a > b / 2
    cout << ((c - a) / b * 2 + 1) << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
        cout << "Case #" << i << ": ", solve();

    return 0;
}
