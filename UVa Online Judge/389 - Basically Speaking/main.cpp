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

int val(char c) {
    if (c >= 'A' && c <= 'F')
        return 10 + (c - 'A');
    return c - '0';
}

char ch(int x) {
    if (x > 9)
        return 'A' + (x - 10);
    return '0' + x;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    string n;
    int s, d, x, b;
    while (cin >> n >> s >> d) {
        x = 0, b = 1;
        for (int i = (int) n.size() - 1; i > -1; i--) {
            x += val(n[i]) * b;
            b *= s;
        }

        string res;
        while (x) {
            res += ch(x % d);
            x /= d;
        }
        reverse(all(res));

        cout << right << setw(7);
        if (res.size() > 7)
            cout << "ERROR" << endl;
        else if (res.size() == 0)
            cout << 0 << endl;
        else
            cout << res << endl;
    }

    return 0;
}
