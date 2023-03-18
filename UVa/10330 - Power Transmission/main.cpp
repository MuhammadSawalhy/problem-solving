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

const int N = 203;
ll n, mat[N][N];
int path[N], pathlen;

int getpath(int i, int j) {
    queue<int> qu;
    vector<long long> mx(2 * n + 2, 0);
    vector<int> parent(2 * n + 2, -1);
    qu.push(i);
    mx[i] = 1e18;

    while (qu.size()) {
        int k = qu.front();
        qu.pop();

        for (int l = 0; l < 2 * n + 2; l++) {
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
    debug(n);
    for (int i = 0; i < 2 * n + 2; i++)
        for (int j = 0; j < 2 * n + 2; j++)
            mat[i][j] = 0;

    for (int i = 1, x; i <= n; i++) {
        cin >> x;
        mat[2 * i][2 * i + 1] = x;
    }

    int m;
    cin >> m;

    for (int i = 0, a, b, c; i < m; i++) {
        cin >> a >> b >> c;
        // output of a into input of b
        mat[2 * a + 1][2 * b] += c;
    }

    // source is 0, sink is 1
    // each node i will be represented with 2 * i and 2 * i + 1

    int b, d;
    cin >> b >> d;

    for (int i = 0, x; i < b; i++) {
        cin >> x;
        mat[0][2 * x] = 1e12;
    }

    int sink = 1;
    for (int i = 0, x; i < d; i++) {
        cin >> x;
        mat[2 * x + 1][sink] = 1e12;
    }

    cout << maxflow(0, sink) << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    while (cin >> n)
        solve();

    return 0;
}
