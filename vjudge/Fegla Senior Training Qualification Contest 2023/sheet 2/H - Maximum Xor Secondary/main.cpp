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

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n;
    cin >> n;
    ll a[n];
    for (int i = 0; i < n; i++) cin >> a[i];

    int ans = 0;
    vector<int> st;
    
    for (int i = 0; i < n; i++) {
        while (st.size() && st.back() <= a[i]) {
            ans = max(ans, st.back() ^ a[i]);
            st.pop_back();
        }

        if (st.size()) {
            ans = max(ans, st.back() ^ a[i]);
        }

        st.push_back(a[i]);
    }

    cout << ans << '\n';

    return 0;
}
