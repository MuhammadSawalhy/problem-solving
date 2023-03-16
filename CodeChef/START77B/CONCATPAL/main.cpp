// ﷽
#include <algorithm>
#include <array>
#include <iostream>
#include <map>
#include <queue>
#include <utility>
#include <vector>
#include <set>

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
    int n, m;
    cin >> n >> m;
    string a, b;
    cin >> a >> b;
    if (n < m) swap(a, b);

    map<char, int> fr, frB;
    for (auto c : b) frB[c]++;
    for (auto c : a) {
        if (frB[c]) {
            frB[c]--;
        } else {
            fr[c]++;
        }
    }


    int odds = 0;

    for (char c = 'a'; c <= 'z'; c++) {
        if (frB[c]) {
            return cout << "NO" << endl, void();
        }
        odds += fr[c] & 1;
    }

    if (odds > 1) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
    }
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
