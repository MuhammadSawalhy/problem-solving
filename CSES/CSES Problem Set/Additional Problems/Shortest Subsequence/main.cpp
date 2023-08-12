// ﷽
// https://cses.fi/problemset/task/1087
// CSES -> CSES Problem Set -> Shortest Subsequence

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

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    string s;
    cin >> s;

    int n = s.length();

    set<char> c;

    int len = 0;
    string ss;
    for (int i = 0; i < n;) {
        while (i < n && c.size() < 4) {
            c.insert(s[i++]);
        }
        if (c.size() == 4) {
            ss += s[i - 1];
            c.clear();
        }
    }

    for (auto ch : "ACGT") {
        if (!c.count(ch)) {
            ss += ch;
            break;
        }
    }

    cout << ss;

    return 0;
}
