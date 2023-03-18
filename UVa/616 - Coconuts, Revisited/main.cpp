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

int c;

int calc(int n) {
    long long x = 0, y = ();

}

bool valid(int n) {
    return calc(n) <= c;
}

void solve() {
    int s = 2, e = 1e9;

    while (e - s > 1) {
        int mid = (s + e) / 2;
        if (valid(mid))
            s = mid;
        else
            e = mid;
    }

    if (calc(s) == c)
        return void(cout << s << " people and 1 monkey" << endl);

    cout << "no solution" << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    while (cin >> c, c > 0)
        cout << c << " coconuts, ", solve();

    return 0;
}
