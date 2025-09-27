// ﷽
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
#define all(v) v.begin(), v.end()

bitset<64> a;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n, q;
    cin >> n >> q;
    for (int i = 0, x; i < n; i++) {
        cin >> x;
        a.flip(x);
    }

    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int x;
            cin >> x;
            a.flip(x);
        } else if (type == 2) {
            int l, r, up;
            cin >> l >> r >> up;
            auto temp = a;
            for (int i = l; i <= r; i++) {
                if (temp[i]) a.flip(i), a.flip(i ^ up);
            }
        } else {
            int l, r;
            cin >> l >> r;
            int x= 0;
            for (int i = l; i <= r; i++) {
                if (a[i]) x ^= i;
            }
            cout << x << endl;
        }
    }

    return 0;
}
