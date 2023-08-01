// Date: 02-01-2023
#include <bits/stdc++.h>

#define debug(...)
#ifdef SAWALHY
#include "debug.hpp"
#endif

#define int long long
#define ll long long
#define all(v) v.begin(), v.end()

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    string s;
    cin >> s;

    int fr[200] = {};

    for (char c: s) fr[c]++;
    int odds = 0;
    for (int i = 'A'; i <= 'Z'; i++) odds += fr[i] & 1;

    if (odds > 1) return !bool(cout << "NO SOLUTION" << endl);

    string ans;

    for (int i = 'A'; i <= 'Z'; i++)
        for (int j = 0; j < fr[i] / 2; j++)
            ans += i;
    string t = ans;
    reverse(all(t));

    char oddch;

    for (int i = 'A'; i <= 'Z'; i++)
        if (fr[i] & 1) oddch = i;

    if (odds)
        cout << ans << oddch << t << endl;
    else
        cout << ans << t << endl;

    return 0;
}
