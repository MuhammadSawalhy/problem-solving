#include <bits/stdc++.h>
using namespace std;
#define int long long

map<vector<int>, int> val;

int doit(vector<int> a) {
    if (val.count(a)) {
        return val[a];
    }

    int n = a.size();
    int ans = accumulate(a.begin(), a.end(), 0LL);
    if (n == 1) {
        return val[a] = ans;
    }

    vector<int> b(n - 1);
    for (int i = 0; i < n - 1; i++) {
        b[i] = a[i + 1] - a[i];
    }

    ans = max(ans, doit(b));

    reverse(a.begin(), a.end());
    for (int i = 0; i < n - 1; i++) {
        b[i] = a[i + 1] - a[i];
    }

    ans = max(ans, doit(b));

    return val[a] = ans;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    val.clear();

    cout << doit(a) << endl;
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
