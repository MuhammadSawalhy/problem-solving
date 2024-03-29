// ﷽
// https://codeforces.com/contest/1950/problem/C

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
#define int long long
#define sz(v) (int) (v).size()
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define minit(v, x...) v = min({v, x})
#define maxit(v, x...) v = max({v, x})

template<class T>
using rpq = priority_queue<T, vector<T>, greater<T>>;

void solve() {
    // Given the time in 24-hour format, output the equivalent time in 12-hour format.
    // 09:41 => 09:41 AM
    // 18:06 => 06:06 PM

    string s;
    cin >> s;

    int h = stoi(s.substr(0, 2));
    int m = stoi(s.substr(3, 2));

    string suf;

    if (h >= 12) {
        suf = "PM";
        if (h > 12) h -= 12;
    } else {
        suf = "AM";
    }

    if (h == 0) {
        h = 12;
    }

    cout << setw(2) << std::setfill('0') << h;
    cout << ":";
    cout << setw(2) << std::setfill('0') << m;
    cout << " " << suf << endl;
}

int32_t main(int32_t argc, char **argv) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
