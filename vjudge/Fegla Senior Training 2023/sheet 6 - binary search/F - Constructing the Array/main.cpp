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

const int N = 3e5;
int a[N];

struct comp {
    bool operator()(array<int, 3> &f, array<int, 3> &s) {
        if (f[0] != s[0])
            return f[0] < s[0];
        else
            return f[1] > s[1];
    }
};

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        memset(a, 0, n * (sizeof(a[0])));

        int op = 0;

        priority_queue<array<int, 3>, vector<array<int, 3>>, comp> qu;
        qu.push({n, 1, n});
        while (qu.size()) {
            auto [_, l, r] = qu.top();
            qu.pop();
            if (l > r) continue;
            int p = (l + r) / 2;
            a[p] = ++op;
            qu.push({p - l, l, p - 1});
            qu.push({r - p, p + 1, r});
        }

        for (int i = 1; i <= n; i++)
            cout << a[i] << ' ';
        cout << '\n';
    }

    return 0;
}
