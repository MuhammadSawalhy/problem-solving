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

#define int long long
#define ll long long
#define all(v) v.begin(), v.end()

void solve() {
    string s;
    int a, b, c, d;
    long double length = 0;

    getline(cin, s);
    while (true) {
        getline(cin, s);
        if (s == "") break;
        istringstream is(s);
        is >> a >> b >> c >> d;
        length += sqrtl((a - c) * (a - c) + (b - d) * (b - d));
    }

    length /= 20000;
    length *= 2;
    double fractional, whole;
    fractional = std::modf(length, &whole);

    if (round(fractional * 60) >= 60.0) {
        fractional = 0;
        whole += 1;
    }

    cout << whole << ":" << setfill('0') << setw(2) << round(fractional * 60) << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int t;
    cin >> t;
    cin.ignore();
    cin.ignore();
    while (t--)
        solve(), t && (cout << '\n');

    return 0;
}
