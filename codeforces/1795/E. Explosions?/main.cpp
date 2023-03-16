// ﷽
#include <map>
#include <array>
#include <queue>
#include <vector>
#include <utility>
#include <iostream>
#include <algorithm>

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

const int N = 3e5;
ll n, h[N], ans[N];

ll arith(ll l, ll r) {
    l--;
    if (l < 0)
        l = 0;
    return r * (r + 1) / 2 - l * (l + 1) / 2;
}

void process() {
    vector<int> st;
    vector<int> ps(n + 1);
    for (int i = 0; i < n; i++)
        ps[i + 1] = h[i] + ps[i];
    vector<int> ourans(n);
    for (int i = 0; i < n; i++) {
        while (st.size() && h[st.back()] > h[i] - (i - st.back())) {
            st.pop_back();
        }
        if (st.size()) {
            ourans[i] += ps[i] - ps[st.back() + 1] - arith(h[i] - (i - st.back() - 1), h[i] - 1);
            ourans[i] += ourans[st.back()];
        } else {
            ourans[i] += ps[i] - arith(h[i] - i, h[i] - 1);
        }
        ans[i] += ourans[i];
        st.push_back(i);
    }
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        ans[i] = 0;
        cin >> h[i];
    }

    process();
    reverse(h, h + n);
    reverse(ans, ans + n);
    process();
    debug_itr(ans, n);

    ll a = 1e18;
    for (int i = 0; i < n; i++) {
        a = min(a, h[i] + ans[i]);
    }

    cout << a << endl;
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
