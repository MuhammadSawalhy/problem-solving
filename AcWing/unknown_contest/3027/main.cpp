#include <bits/stdc++.h>
using namespace std;

#define int long long

struct Val {
    bool done = false;
    int x, y;
    friend Val operator-(int c, const Val &v) {
        return {true, -v.x, c - v.y};
    }
    friend bool operator==(const Val &a, const Val &b) {
        return a.x == b.x && a.y == b.y;
    }
};

const int N = 1001;
int a[N][N];
vector<int> row[N], col[N];
Val rowval[N];
Val colval[N];

bool dfs(int i, int j) {
    assert(colval[j].done);
    assert(rowval[i].done);
    auto next_i = upper_bound(col[j].begin(), col[j].end(), i);
    auto next_j = upper_bound(row[i].begin(), row[i].end(), j);

    if (next_i != col[j].end()) {
        int ii = *next_i;
        Val v = a[ii][j] - colval[j];
        if (rowval[ii].done) {
            if (!(v == rowval[ii])) return false;
        } else {
            rowval[ii] = v;
            if (!dfs(ii, j)) return false;
        }
    }

    next_i--;
    if (next_i != col[j].begin()) {
         int ii = *(next_i - 1);
        Val v = a[ii][j] - colval[j];
        if (rowval[ii].done) {
            if (!(v == rowval[ii])) return false;
        } else {
            rowval[ii] = v;
            if (!dfs(ii, j)) return false;
        }
    }

    if (next_j != row[i].end()) {
        int jj = *next_j;
        Val v = a[i][jj] - rowval[i];
        if (colval[jj].done) {
            if (!(v == colval[jj])) return false;
        } else {
            colval[jj] = v;
            if (!dfs(i, jj)) return false;
        }
    }

    next_j--;
    if (next_j != row[i].begin()) {
        int jj = *(next_j - 1);
        Val v = a[i][jj] - rowval[i];
        if (colval[jj].done) {
            if (!(v == colval[jj])) return false;
        } else {
            colval[jj] = v;
            if (!dfs(i, jj)) return false;
        }
    }

    return true;
}

void solve() {
    int n, m, k;
    cin >> n >> m >> k;

    pair<int, int> emeralds;
    for (int i = 0; i < k; i++) {
        int x, y, c;
        cin >> x >> y >> c;
        x--, y--;
        a[x][y] = c;
        row[x].push_back(y);
        col[y].push_back(x);
    }

    for (int i = 0; i < n; i++) sort(row[i].begin(), row[i].end());
    for (int i = 0; i < m; i++) sort(col[i].begin(), col[i].end());

    for (int i = 0; i < n; i++) {
        if (rowval[i].done == false && row[i].size()) {
            int j = row[i].front();
            rowval[i] = {true, 1, 0};
            colval[j] = a[i][j] - rowval[i];
            if (!dfs(i, j)) {
                cout << "No\n";
                return;
            }
        }
    }

    cout << "Yes\n";

    for (int i = 0; i < m; i++) colval[i].done = false, col[i].clear();
    for (int i = 0; i < n; i++) rowval[i].done = false, row[i].clear();
}

int32_t main(int32_t argc, char **argv) {
    cin.tie(nullptr)->sync_with_stdio(false);

    int T = 1;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        solve();
    }

    return 0;
}
