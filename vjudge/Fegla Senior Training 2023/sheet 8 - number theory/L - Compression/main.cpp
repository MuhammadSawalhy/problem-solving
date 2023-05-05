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

const int N = 5202;
int a[N][N];

int fromhex(char c) {
    if (c >= 'A') return 10 + c - 'A';
    return c - '0';
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n;
    scanf("%lld", &n);

    char buffer[n / 4 + 1];
    for (int i = 0; i < n; i++) {
        scanf("%s", buffer);
        int l = strlen(buffer);
        for (int j = 0; j < n; j += 4) {
            int val = fromhex(buffer[j / 4]);
            for (int k = 0; k < 4; k++)
                a[i + 1][j + k + 1] = val >> (3 - k) & 1;
        }
    }

    debug_itr(a, n + 1, n + 1);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            a[i][j] += a[i][j - 1]; 
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            a[i][j] += a[i - 1][j]; 
        }
    }

    vector<int> divs;

    for (int i = 1; i * i <= n; i++) {
        if (n % i != 0) continue;
        divs.push_back(i);
        divs.push_back(n / i);
    }

    sort(divs.rbegin(), divs.rend());

    auto check = [&](int d) -> bool {
        debug(d);
        for (int i = 0; i < n; i += d) {
            for (int j = 0; j < n; j += d) {
                int sum = a[i + d][j + d] + a[i][j] - a[i][j + d] - a[i + d][j];
                if (sum != 0 && sum != d * d)
                    return false;
            }
        }
        return true;
    };

    for (auto d: divs) {
        if (check(d)) {
            printf("%lld\n", d);
            break;
        }
    }

    return 0;
}
