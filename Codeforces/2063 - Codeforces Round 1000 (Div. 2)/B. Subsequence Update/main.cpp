#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, l, r;
    cin >> n >> l >> r;
    l--, r--;
    vector<int> a(n);
    long long ans = 0;
    vector<int> left, right, in;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (i < l) {
            left.push_back(a[i]);
        } else if (i > r) {
            right.push_back(a[i]);
        } else {
            ans += a[i];
            in.push_back(a[i]);
        }
    }

    sort(in.rbegin(), in.rend());
    sort(left.begin(), left.end());
    sort(right.begin(), right.end());

    long long ans1 = ans, ans2 = ans;

    for (int i = 0; i < min(left.size(), in.size()); i++) {
        ans1 += min(0, left[i] - in[i]);
    }

    for (int i = 0; i < min(right.size(), in.size()); i++) {
        ans2 += min(0, right[i] - in[i]);
    }

    cout << min(ans1, ans2) << endl;
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
