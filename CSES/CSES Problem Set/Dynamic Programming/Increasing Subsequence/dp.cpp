#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &i: a) cin >> i;
    vector<int> dp;
    for (int i = 0; i < n; i++) {
        int j = lower_bound(begin(dp), end(dp), a[i]) - begin(dp);
        if (j < dp.size()) {
            dp[j] = a[i];
        } else {
            dp.push_back(a[i]);
        }
    }
    cout << dp.size();
    return 0;
}
