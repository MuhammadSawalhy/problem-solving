// Date: 31-12-2022
#include <bits/stdc++.h>

#define debug(...)
#ifdef SAWALHY
#include "debug.hpp"
#endif

#define int    long long
#define ll     long long
#define all(v) v.begin(), v.end()

using namespace std;

vector<int> KMP(const string &a, const string &b) {
    // search for b in a
    vector<int> ans;
    int n = a.length(), m = b.length();
    int b_table[n];
    b_table[0] = 0;

    for (int i = 1, k = 0; i < m; i++) {
        while (k > 0 && b[k] != b[i])
            k = b_table[k - 1];
        k += b[i] == b[k];
        b_table[i] = k;
    }

    for (int i = 0, k = 0; i < n; i++) {
        while (k > 0 && b[k] != a[i])
            k = b_table[k - 1];
        k += b[k] == a[i];
        debug(k);
        if (k == m) {
            k = b_table[k - 1];
            ans.push_back(i - m + 1);
        }
    }

    return ans;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int m;
    string needle, haystash;

    bool first = true;
    while (cin >> m >> needle >> haystash) {
        auto ans = KMP(haystash, needle);
        if (ans.size()) {
            if (!first) cout << '\n';
            for (auto i: ans)
                cout << i << '\n';
            first = false;
        }
    }

    return 0;
}
