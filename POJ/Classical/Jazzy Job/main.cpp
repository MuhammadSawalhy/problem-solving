#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100001, inf = 1e9;
vector<pair<int, int>> adj[MAXN];
vector<int> newadj[MAXN];
int ss[MAXN], dd[MAXN];
int S, D, N, R;

vector<int> dist() {
    vector<int> d(N, inf);

    queue<int> qu;
    for (int i = 0; i < S; i++) d[ss[i]] = 0, qu.push(ss[i]);

    while (qu.size()) {
        int i = qu.front();
        qu.pop();
        for (auto j: newadj[i])
            if (d[i] + 1 < d[j]) d[j] = d[i] + 1, qu.push(j);
    }

    return d;
};

void solve() {
    cin >> S >> D >> N;
    for (int i = 0; i < S; i++) cin >> ss[i];
    for (int i = 0; i < D; i++) cin >> dd[i];

    cin >> R;
    for (int i = 0; i < R; i++) {
        int S, C, A;
        cin >> S >> C >> A;
        adj[S].push_back({C, A});
    }

    int lo = 0, hi = 1e9 + 1;

    while (hi - lo > 1) {
        int mid = (lo + hi) / 2;
        for (int i = 0; i < N; i++) {
            for (auto [j, A]: adj[i])
                if (A <= mid) newadj[i].push_back(j);
        }

        auto d = dist();
        bool ok = true;
        for (int i = 0; i < D; i++)
            if (d[dd[i]] == inf) ok = false;
        if (ok) hi = mid;
        else lo = mid;
        for (int i = 0; i < N; i++) newadj[i].clear();
    }

    int sum = 0;
    for (int i = 0; i < N; i++) {
        for (auto [j, A]: adj[i])
            if (A <= hi) newadj[i].push_back(j);
    }

    auto d = dist();
    for (int i = 0; i < D; i++) sum = min(inf, sum + d[dd[i]]);

    if (sum == inf) {
        cout << "Excessive Energy." << endl;
    } else {
        cout << hi << ' ' << sum << endl;
    }

    for (int i = 0; i < N; i++) newadj[i].clear();
    for (int i = 0; i < N; i++) adj[i].clear();
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
