#include <bits/stdc++.h>
using namespace std;
int n, a[3000], dp[3000], mod = 1e9 + 7;
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) {
        int l = i, r = i;
        while (l > 0 && a[l - 1] > a[i]) l--;
        while (r < n - 1 && a[r + 1] > a[i]) r++;
        for (int j = l; j <= r; j++)
            dp[j] = (dp[j] + (j > 0 ? dp[j - 1] : 1)) % mod;
    }
    cout << dp[n - 1];
}
