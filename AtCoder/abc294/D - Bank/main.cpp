// ﷽
#include <bits/stdc++.h>
#include <queue>

using namespace std;

#ifdef SAWALHY
#include "debug.hpp"
#else
#define debug(...) 0
#define debug_itr(...) 0
#define debug_bits(...) 0
#endif

#define int long long
#define ll long long
#define all(v) v.begin(), v.end()

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n, q;
    cin >> n >> q;

    set<int> notcalled, called;

    for (int i = 1; i <= n; i++)
        notcalled.insert(i);

    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            if (notcalled.size()) {
                called.insert(*notcalled.begin());
                notcalled.erase(notcalled.begin());
            }
        }

        if (t == 2) {
            int x;
            cin >> x;
            if (called.size())
                called.erase(x);
        }

        if (t == 3) {
            cout << *called.begin() << endl;
        }
    }

    return 0;
}
