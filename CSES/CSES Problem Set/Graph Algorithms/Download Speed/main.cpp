// ﷽
// https://cses.fi/problemset/task/1694
// CSES -> CSES Problem Set -> Download Speed

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

const int N = 505;
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

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int m;
    cin >> n >> m;

    for (int i = 0, a, b, c; i < m; i++) {
        cin >> a >> b >> c;
        a--, b--;
        mat[a][b] += c;
    }

    cout << maxflow(0, n - 1);

    return 0;
}
