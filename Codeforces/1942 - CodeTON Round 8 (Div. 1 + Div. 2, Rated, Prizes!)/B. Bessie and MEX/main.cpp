// ﷽
// https://codeforces.com/contest/1942/problem/B

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
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }


    set<int> nums;
    for (int i = 0; i < n; i++) nums.insert(i);

    if (a[0] < 0) {
        cout << -a[0] << ' ';
        nums.erase(-a[0]);
        a[0] = 0;
    } else {
        cout << 0 << ' ';
        assert(a[0] == 1);
        nums.erase(0);
    }

    for (int i = 1; i < n; i++) {
        // mn to to make a[i] > a[i - 1]
        auto it = nums.lower_bound(a[i - 1] - a[i]);
        assert(it != nums.end());
        a[i] += *it;
        cout << *it << ' ';
        nums.erase(it);
    }

    cout << endl;
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
