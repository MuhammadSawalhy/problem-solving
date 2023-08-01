// ﷽
#include <bits/stdc++.h>

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

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n;
    cin >> n;
    pair<int, int> a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i].first, a[i].second = i;
    }

    stack<pair<int, int>> st;

    int ans[n];
    memset(ans, 0, sizeof ans);
    for (int i = n - 1; ~i; i--) {
        while (st.size() && st.top().first > a[i].first) {
            ans[st.top().second] = i + 1;
            st.pop();
        }
        st.push(a[i]);
    }

    for (int i = 0; i < n; i++)
        cout << ans[i] << " ";

    return 0;
}
