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

const int M = 5e5;
int n, m;
int f[M];

int calc_mx() {
    int twos = m / 4;
    for (int i = 0; i < m - 1; i++) {
        if (twos && ( (f[i] ^ f[i + 1]) == 1 || f[i] == 0 )) {
            twos--;
            i++;
        }
    }
    return m / 4 - twos;
}

int calc_mn() {
    int twos = m / 4;
    for (int i = 0; i < m - 1; i++) {
        if (twos && f[i] == 1 && f[i + 1] == 1) {
            twos--;
            i++;
        }
    }
    return m / 4 - twos;
}
 
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> n >> m;

    int mn = 0, mx = 0;

    string s;
    for (int i = 0; i < n; i++) {
        cin >> s;
        int ones = 0;
        for (int j = 0; j < m; j++)
            ones += (f[j] = s[j] - '0');
        mn += ones - calc_mn();
        mx += ones - m / 4 + calc_mx();
    }

    cout << mn << " " << mx << endl;

    return 0;
}
