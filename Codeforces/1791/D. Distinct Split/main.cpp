// ﷽
#include <bits/stdc++.h>

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

void solve() {
    int n;
    string s;
    cin >> n >> s;
    int ans = 0;
    vector<int> a(200), b(200);

    for (int i = 0; i < n; i++)
        b[s[i]]++;

    for (int i = 0; i < n - 1; i++) {
        b[s[i]]--, a[s[i]]++;
        int A = 0, B=  0;
        for (char c = 'a'; c <= 'z'; c++) {
            A += a[c] > 0;
            B += b[c] > 0;
        }
        ans = max(ans, A + B);
    }
    cout << ans << endl;
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
