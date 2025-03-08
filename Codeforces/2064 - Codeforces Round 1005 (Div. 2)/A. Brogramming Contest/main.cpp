#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    int cnt = 0, f = 1;

    if (s.back() == '1') {
        cnt++;
        while (s.back() == '1') s.pop_back();
    }

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '1') {
            if (f) cnt+=2, f = 0;
        } else {
            f = 1;
        }
    }

    cout << cnt << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);

    int T = 1;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        solve();
    }

    return 0;
}
