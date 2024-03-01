// ﷽
// https://codeforces.com/contest/1937/problem/C

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

char ask(int a, int b, int c, int d) {
    cout << "? " << a << " " << b << " " << c << " " << d << endl;
    char x;
    cin >> x;
    return x;
}

void answer(int i, int j) {
    cout << "! " << i << " " << j << endl;
}

void solve() {
    int n;
    cin >> n;

    if (n == 2) {
        answer(0, 1);
        return;
    }

    int nminusone = 0;
    for (int i = 1; i < n; i++) {
        if (ask(nminusone, nminusone, i, i) == '<') {
            nminusone = i;
        }
    }

    int comp = 0;
    for (int i = 1; i < n; i++) {
        if (i == nminusone) continue;
        char res = ask(nminusone, comp, nminusone, i);
        if (res == '<') {
            comp = i;
        } else if (res == '=') {
            // comp vs. i
            if (ask(comp, comp, i, i) == '>') {
                comp = i;
            }
        }
    }

    answer(comp, nminusone);
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
