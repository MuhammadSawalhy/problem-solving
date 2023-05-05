// ﷽
#include <bits/stdc++.h>

using namespace std;

#ifdef SAWALHY
#include "debug.hpp"
#else
#define debug(...)      0
#define debug_itr(...)  0
#define debug_bits(...) 0
#endif

#define ll     long long
#define int    long long
#define all(v) v.begin(), v.end()

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    string s; cin >> s;

    map<char, int> fr;
    for (auto c : s) {
        fr[c]++;
    }

    int cnt = 0;
    for (auto [c, f] : fr) {
        if (f != 2) {
            cout << "No\n";
            exit(0);
        }

        cnt++;
    }

    if (cnt != 2) {
        cout << "No\n";
    } else {
        cout << "Yes\n";
    }

    return 0;
}
