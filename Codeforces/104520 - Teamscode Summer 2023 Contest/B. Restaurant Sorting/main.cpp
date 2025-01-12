#include <bits/stdc++.h>
using namespace std;

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        int val = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] != i + 1) {
                val = n - i;
                break;
            }
        }
        cout << val << endl;
    }

    return 0;
}
