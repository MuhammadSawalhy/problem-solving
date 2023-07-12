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
int n; 
bool check(vector<int> a, vector<int> b) {
    for (int i = 0; i < n - 1; i++) {
        if (a[i] > a.back()) {
            swap(a[i], b[i]);
        }
        if (a[i] > a.back() || b[i] > b.back()) return false;
    }

    return true;
}

void solve() {
    cin >> n; vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    if (!check(a, b)) {
        swap(a.back(), b.back());
    }

    cout << (check(a, b) ? "YES" : "NO") << endl;
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
