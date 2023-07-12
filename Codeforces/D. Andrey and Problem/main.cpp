// Date: 14-10-2022
#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include "debug.hpp"
#else
#define debug(...)
#endif

const int N = 100;
int n;
double p[N + 1];

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> p[i];
    sort(p, p + n);
    if (p[n - 1] == 1) return void(cout << 1.0 << endl);
    double P = 1, S = 0;
    for (int i = n - 1; ~i; i--) {
        P *= 1 - p[i];
        S += p[i] / (1 - p[i]);
        if (S >= 1) break;
    }

    cout << P * S << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    cout << setprecision(12) << fixed;

    solve();

    return 0;
}
