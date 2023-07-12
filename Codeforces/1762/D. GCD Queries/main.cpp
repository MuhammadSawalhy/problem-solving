// Date: 15-12-2022
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define all(v) v.begin(), v.end()
#define debug(...)
#ifdef SAWALHY
#include "debug.hpp"
#endif

int query(int i, int j) {
    cout << "? " << i << " " << j << endl;
    int ans;
    cin >> ans;
    return ans;
}

void solve() {
    // lcm of all queries to know which number is your pivot
    // if lcm > n then your pivot is zero

    int n;
    cin >> n;

    for (int i = 2; i <= n; i++) {
        int g = query(1, i);
        if (g) == 1
    }

    int result;
    cin >> result;
    assert(result == 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
