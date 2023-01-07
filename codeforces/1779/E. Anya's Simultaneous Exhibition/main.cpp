// ﷽
// 11 جُمادى الآخرة 1444
// Jan 03, 2023
#include <bits/stdc++.h>

#define debug(...)
#ifdef SAWALHY
#include "debug.hpp"
#endif

#define int long long
#define ll long long
#define all(v) v.begin(), v.end()

using namespace std;

int n;

int ask(int i, vector<int> quest) {
    string s;
    for (int j = 1; j <= n; j++)
        s += quest[i] ? "1" : "0";
    cout << "? " << i << " " << s << endl;
    int ans;
    cin >> ans;
    return ans;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> n;
    bool ans[n];
    memset(ans, 0, sizeof ans);

    for (int i = 1; i <= n; i++) {
        int ans = ask(i);
        if (ans == n - 1) {
        }
    }

    cout << "! ";
    for (int i = 0; i < n; i++)
        cout << ans[i];
    cout << endl;

    return 0;
}
