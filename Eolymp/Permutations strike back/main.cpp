#include <bits/stdc++.h>
using namespace std;

const int B = 300;

vector<vector<int>> blks;
vector<int> a;
int n, m;

void init() {
    int blk_cnt = (n + B - 1) / B;
    blks.resize(blk_cnt);
    for (int i = 0; i < n; ++i) {
        blks[i / B].push_back(a[i]);
    }
    for (auto& blk : blks) {
        sort(blk.begin(), blk.end());
    }
}

void update(int idx, int val) {
    int b = idx / B;
    auto& blk = blks[b];
    blk.erase(lower_bound(blk.begin(), blk.end(), a[idx]));
    blk.insert(lower_bound(blk.begin(), blk.end(), val), val);
    a[idx] = val;
}

int query(int l, int r, int k, int u) {
    int lb = l / B, rb = r / B, cnt = 0;

    if (lb == rb) {
        for (int i = l; i <= r; ++i)
            if (a[i] >= k && a[i] <= u) ++cnt;
    } else {
        int le = (lb + 1) * B - 1;
        for (int i = l; i <= min(r, le); ++i)
            if (a[i] >= k && a[i] <= u) ++cnt;

        for (int b = lb + 1; b < rb; ++b) {
            auto& blk = blks[b];
            cnt += upper_bound(blk.begin(), blk.end(), u) - lower_bound(blk.begin(), blk.end(), k);
        }

        int rs = rb * B;
        for (int i = max(l, rs); i <= r; ++i)
            if (a[i] >= k && a[i] <= u) ++cnt;
    }

    return cnt;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> n >> m;
    a.resize(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    init();

    for (int i = 0; i < m; ++i) {
        string op;
        cin >> op;
        if (op == "SET") {
            int idx, val;
            cin >> idx >> val;
            update(idx - 1, val);
        } else if (op == "GET") {
            int l, r, k, u;
            cin >> l >> r >> k >> u;
            cout << query(l - 1, r - 1, k, u) << '\n';
        }
    }

    return 0;
}

