// ﷽
// https://cses.fi/problemset/task/1142

#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
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
    int n;
    cin >> n;

    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> st;
    vector<int> l(n, -1);
    vector<int> r(n, n);

    for (int i = n - 1; ~i; i--) {
        while(st.size() && a[st.back()] > a[i]) {
            l[st.back()] = i;
            st.pop_back();
        }
        st.push_back(i);
    }

    st.clear();

    for (int i = 0; i < n; i++) {
        while(st.size() && a[st.back()] > a[i]) {
            r[st.back()] = i;
            st.pop_back();
        }
        st.push_back(i);
    }


    int ans = 0;
    for (int i = 0; i < n; i++) {
        maxit(ans, (r[i] - 1 - l[i]) * a[i]);
    }
    cout << ans << endl;
}

int32_t main(int32_t argc, char **argv) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    solve();

    return 0;
}
