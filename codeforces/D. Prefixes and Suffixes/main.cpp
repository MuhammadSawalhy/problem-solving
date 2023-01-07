// Date: 21-12-2022
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define all(v) v.begin(), v.end()
#define debug(...)
#ifdef SAWALHY
#include "debug.hpp"
#endif

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    string s;
    cin >> s;
    int n = s.length();

    int fr[n];
    int table[n];
    table[0] = 0;
    memset(fr, 0, sizeof fr);

    for (int i = 1, k = 0; i < n; i++) {
        while (k > 0 && s[k] != s[i])
            k = table[k - 1];
        if (s[k] == s[i])
            table[i] = ++k;
        else
            table[i] = k;
        fr[table[i]]++;
    }

    vector<pair<int, ll>> ans = {{n, 1}};

    int next = table[n - 1];

    for (int k = n - 1; k > 0; k--) {
        fr[table[k - 1]] += fr[k];
    };

    for (int k = n - 1; k > 0; k--) {
        if (k == next) {
            ans.push_back({k, fr[k] + 1});
            next = table[k - 1];
        }
    }

    reverse(all(ans));
    cout << ans.size() << endl;
    for (auto [l, f]: ans)
        cout << l << " " << f << endl;

    return 0;
}
