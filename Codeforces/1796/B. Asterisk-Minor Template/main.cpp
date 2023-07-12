// ﷽
#include <map>
#include <cmath>
#include <array>
#include <queue>
#include <vector>
#include <utility>
#include <assert.h>
#include <iostream>
#include <algorithm>

using namespace std;

#ifdef SAWALHY
#include "debug.hpp"
#else
#define debug(...)
#define debug_itr(...)
#define debug_bits(...)
#endif

#define int long long
#define ll long long
#define all(v) v.begin(), v.end()

void solve() {
    string a, b;
    cin >> a >> b;

    if (a[0] == b[0]) {
        cout << "YES" << endl;
        cout << a[0] << "*" << endl;
        return;
    }

    if (a.back() == b.back()) {
        cout << "YES" << endl;
        cout << "*" << a.back() << endl;
        return;
    }


    for (int i = 1; i < a.size(); i++) {
        if (b.find(a.substr(i - 1, 2)) != string::npos) {
            cout << "YES" << endl;
            cout << '*' << a.substr(i - 1, 2) << '*' << endl;
            return;
        }
    }

    cout << "NO" << endl;
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
