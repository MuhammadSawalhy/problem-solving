// ﷽
#include <iostream>
#include <set>

using namespace std;

#ifdef SAWALHY
#include "debug.hpp"
#else
#define debug(...)
#define debug_itr(...)
#define debug_bits(...)
#endif

#define int long long
#define ll long long
#define all(v) v.begin(), v.end()

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    int a[m];
    for (int i = 0,x ; i < m; i++)
        cin >> a[i];

    int j = 0;
    for (int i = 1; i <= n; i++) {
        int start = i;
        while (j < m && a[j] == i) {
            j++, i++;
        }
        for (int k = i; k >= start; k--)
            cout << k << " ";
    }


    return 0;
}
