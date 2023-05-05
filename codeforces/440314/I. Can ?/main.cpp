// ﷽
#include <bits/stdc++.h>

using namespace std;

#ifdef SAWALHY
#include "debug.hpp"
#else
#define debug(...)      0
#define debug_itr(...)  0
#define debug_bits(...) 0
#endif

#define ll     long long
#define int    long long
#define all(v) v.begin(), v.end()

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int a, b;
    cin >> a >> b;

    bool vis[100]{};

    queue<pair<int, int>> q;
    q.push({a, 0});

    while (true) {
        auto [x, d] = q.front();
        q.pop();
        if (x == b) {
            cout << d << endl;
            exit(0);
        }
        if (vis[x]) continue;
        vis[x] = true;
        if (x > 1)
            q.push({x - 1, d + 1});
        if (x < b)
            q.push({x * 3, d + 1});
    }

    return 0;
}
