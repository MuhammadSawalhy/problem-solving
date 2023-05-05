// ﷽
#include <bits/stdc++.h>

using namespace std;

#ifdef SAWALHY
#include "debug.hpp"
#else
#define debug(...)      0
#define debug_itr(...)  0
#define debug_bits(...) 0
#endif

#define ll     long long
#define int    long long
#define all(v) v.begin(), v.end()

void solve() {
    int k;
    string s;
    cin >> k >> s;
    int n = s.size();

    stack<int> st;
    vector<int> values;

    int ans = 0;

    for (int i = 0; i < n; i++) {
        if (s[i] == '(') {
            st.push(i);
        } else {
            ans += st.size() - 1;
            int len = i - st.top() - 1;
            values.push_back(len / 2);
            assert(len % 2 == 0);
            assert(len >= 0);
            st.pop();
        }
    }

    sort(values.rbegin(), values.rend());
    for (int i = 0; i < min(k, (int)values.size()); i++) {
        ans -= values[i];
    }
    assert(ans >= 0);
    cout << ans << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
