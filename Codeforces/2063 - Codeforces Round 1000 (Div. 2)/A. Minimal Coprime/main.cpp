#include <bits/stdc++.h>
using namespace std;

void solve() {
    int l ,r;
    cin >> l >> r;
    if (l == r && l == 1) cout << "1\n";
    else cout << (r - l) << endl;
}

int32_t main(int32_t argc, char **argv) {
    cin.tie(nullptr)->sync_with_stdio(false);

    int T = 1;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        solve();
    }

    return 0;
}
