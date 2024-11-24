#include <bits/stdc++.h>

const int N = 3e5 + 5;
int a[2 * N], n, L;

using namespace std;
int main() {
    cin.tie(0)->sync_with_stdio(false);

    cin >> n >> L;

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    sort(a, a + n);

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        a[i + n] = a[i] + L;
    }

    long long outside = 0;

    for (int i = 0; i < n; ++i) {
        int cnt = lower_bound(a, a + 2 * n, a[i] + (L - 1) / 2 + 1) - (a + i) - 1;
        outside += 1LL * cnt * (cnt - 1) / 2;
    }

    cout << 1LL * n * (n - 1) * (n - 2) / 6 - outside;

    return 0;
}
