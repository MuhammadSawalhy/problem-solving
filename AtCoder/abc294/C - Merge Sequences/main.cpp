// ﷽
#include <bits/stdc++.h>

using namespace std;

#ifdef SAWALHY
#include "debug.hpp"
#else
#define debug(...) 0
#define debug_itr(...) 0
#define debug_bits(...) 0
#endif

#define int long long
#define ll long long
#define all(v) v.begin(), v.end()

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    int a[n], b[m];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++)
        cin >> b[i];

    sort(a, a + n);
    sort(b, b + m);

    int A[n], B[m];
    int i = 0, j = 0;

    int k = 1;
    while (i <= n || j <= m) {
        debug(i, j);
        if (j == m || i < n && a[i] < b[j]) {
            A[i++] = k++;
        } else if (i == n || j < m && a[i] > b[j]) {
            B[j++] = k++;
        }
        if (i == n && j == m)
            break;
    }

    assert(i == n);
    assert(j == m);

    for (int i = 0; i < n; i++)
        cout << A[i] << " \n"[i == n - 1];
    for (int i = 0; i < m; i++)
        cout << B[i] << " \n"[i == m - 1];

    return 0;
}
