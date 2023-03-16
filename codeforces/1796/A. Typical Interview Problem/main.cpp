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

string s;

void solve() {
    int n;
    cin >> n;
    string t;
    cin >> t;

    if (s.find(t) != string::npos)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    for (int i = 1; i < 200; i++) {
        if (i % 3 == 0)
            s += 'F';
        if (i % 5 == 0)
            s += 'B';
    }

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
