// ﷽
#include <map>
#include <array>
#include <queue>
#include <vector>
#include <utility>
#include <iostream>
#include <algorithm>

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

const int N = 402;
int mat[N][N];
int path[N], pathlen;
int n, m, s, v, nn;

int getpath(int i, int j) {
    queue<int> qu;
    vector<long long> mx(nn, 0);
    vector<int> parent(nn, -1);
    qu.push(i);
    mx[i] = 1e18;

    while (qu.size()) {
        int k = qu.front();
        qu.pop();

        for (int l = 0; l < nn; l++) {
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
    // step 1:
    // connect `src` to all gophers with edge with capacity = 1
    //
    // step 2:
    // connect all gophers to their reachable holes
    //
    // step 3:
    // connect all holes outpus to `sink`

    cin >> m >> s >> v;
    nn = (n + m) + 2;

    int src = (n + m);
    int sink = (n + m) + 1;

    for (int i = 0; i < nn; i++)
        for (int j = 0; j < nn; j++)
            mat[i][j] = 0;

    double gophers[n][2];
    for (int i = 0; i < n; i++) {
        cin >> gophers[i][0] >> gophers[i][1];
        // step 1:
        // any integer > 0 will work
        mat[src][i] = 1;
    }

    for (int i = n; i < n + m; i++) {
        double x, y;
        cin >> x >> y;

        for (int j = 0; j < n; j++) {
            double dx = gophers[j][0] - x, dy = gophers[j][1] - y;
            double d = dx * dx + dy * dy;
            if (d <= v * s * v * s) {
                // step 2:
                mat[j][i] = 1;
            }
        }

        // step 3:
        mat[i][sink] = 1;
    }

    cout << n - maxflow(src, sink) << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    while (cin >> n)
        solve();

    return 0;
}
