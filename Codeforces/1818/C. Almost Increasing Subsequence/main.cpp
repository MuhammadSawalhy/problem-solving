// ﷽
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, q;
    
    cin >> n >> q;
    int a[n];
    
    int x[n];
    memset(x, 0, sizeof x);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (i > 1 && a[i - 2] >= a[i - 1] && a[i - 1] >= a[i])
            x[i] = -1;
        if (i > 0)
            x[i] += x[i - 1];
        // cout << x[i] << ' ';
    }
    // cout << endl;
    
    int l, r;
    while (q--) {
        cin >> l >> r;
        l--, r--;
        int y = 0;
        if (r - l + 1 > 2)
            y = x[r] - x[l + 1];
        cout << r - l + 1 + y << '\n';
    }
    
    
    return 0;
}
