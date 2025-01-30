#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int32_t main(int32_t argc, char **argv) {
    cin.tie(nullptr)->sync_with_stdio(false);

    string s;
    cin >> s;
    int n = s.size();

    int ans = 1, cnt = 0;

    for (int i = 0; i < n; i++) {
        if (s[i] == 'b') ans = 1ll * ans * (cnt + 1) % mod, cnt = 0;
        if (s[i] == 'a') cnt++;
    }

    ans = 1ll * ans * (cnt + 1) % mod, cnt = 0;
    ans = (ans - 1 + mod) % mod;
    cout << ans << endl;

    return 0;
}
