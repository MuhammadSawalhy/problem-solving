// ﷽
#include <algorithm>
#include <array>
#include <iostream>
#include <map>
#include <queue>
#include <utility>
#include <vector>

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

const int N = 201;
int n, mat[N][N];
int path[N], pathlen;

int getpath(int i, int j) {
    queue<int> qu;
    vector<long long> mx(n, 0);
    vector<int> parent(n, -1);
    qu.push(i);
    mx[i] = 1e18;

    while (qu.size()) {
        int k = qu.front();
        qu.pop();

        for (int l = 0; l < n; l++) {
            if (min(mx[k], mat[k][l]) <= mx[l]) continue;
            mx[l] = min(mx[k], mat[k][l]);
            parent[l] = k;
            qu.push(l);
        }
    }

    i = j;
    pathlen = 0;
    while (i != -1) {
        path[pathlen++] = i;
        i = parent[i];
    }

    reverse(path, path + pathlen);
    return mx[j];
}

int maxflow(int src, int sink) {
    int mf = 0;
    while (true) {
        int f = getpath(src, sink);
        if (f <= 0) break;
        for (int i = 1; i < pathlen; i++) {
            mat[path[i - 1]][path[i]] -= f;
            mat[path[i]][path[i - 1]] += f;
        }
        mf += f;
    }
    return mf;
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            mat[i][j] = 0;
    }
    for (int i = 0; i < n - 1; i++) {
        int m;
        cin >> m;
        for (int j = 0, a; j < m; j++) {
            cin >> a;
            if (i == 0 || a == n)
                mat[i][a - 1] = 1;
            else
                mat[i][a - 1] = 1e9;
        }
    }

    cout << maxflow(0, n - 1) << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
