// ﷽
#include <bits/stdc++.h>

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

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int a, b, c, d;
    cin >> a >> b >> c >> d;

    int s = 0, x = 0, i = 0, j = 0;
    while (s < a) {
        s += i++;
    }

    if (s != a) {
        cout << "Impossible" << endl;
        return 0;
    }

    while (x < d) {
        x += j++;
    }

    if (i == 0 && b + c == 0) {
        j = max(j, 1LL);
    } else if (i == 0) {
        i = 1;
    }

    if (j == 0 && b + c == 0) {
        i = max(i, 1LL);
    } else if (j == 0) {
        j = 1;
    }

    if (x != d || b + c != 1LL * i * j) {
        cout << "Impossible" << endl;
        return 0;
    }

    vector<int> ones(i + 1);

    int o = 0;

    for (int k = i; k > 0; k--) {
        while (b >= k) {
            ones[k]++;
            o++;
            b -= k;
        }
    }

    assert(b == 0);
    assert(o <= j);
    j -= o;
    while (j--)
        cout << '1';

    for (int k = 0; k < i; k++) {
        cout << '0';
        while (ones[k + 1]--) {
            cout << '1';
        }
    }

    return 0;
}
