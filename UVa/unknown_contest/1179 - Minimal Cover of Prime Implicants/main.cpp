#include <bits/stdc++.h>
using namespace std;

bool cov(const string &pi, const string &mt) {
    for (int i = 0; i < pi.size(); ++i) {
        if (pi[i] != '-' && pi[i] != mt[i]) return false;
    }
    return true;
}

void solve() {
    int t = 1;
    while (true) {
        int n, m, p;
        cin >> n >> m >> p;
        if (n == 0 && m == 0 && p == 0) break;

        vector<string> mts(m), pis(p);
        for (int i = 0; i < m; ++i) cin >> mts[i];
        for (int i = 0; i < p; ++i) cin >> pis[i];

        vector<vector<bool>> table(p, vector<bool>(m));
        for (int i = 0; i < p; ++i)
            for (int j = 0; j < m; ++j)
                table[i][j] = cov(pis[i], mts[j]);

        vector<bool> cov(m);
        vector<int> res;
        int cnt = 0;
        while (cnt < m) {
            int best = -1, maxCov = 0, minCost = n + 1;

            for (int i = 0; i < p; ++i) {
                int curCov = 0, curCost = 0;
                for (int j = 0; j < m; ++j)
                    if (!cov[j] && table[i][j]) ++curCov;
                for (char c: pis[i])
                    if (c != '-') ++curCost;

                if (!curCov) continue;
                if (curCov > maxCov || (curCov == maxCov && curCost < minCost)) {
                    best = i;
                    maxCov = curCov;
                    minCost = curCost;
                }
            }

            if (best == -1) break;

            res.push_back(best);
            for (int j = 0; j < m; j++)
                if (!cov[j] && table[best][j]) ++cnt, cov[j] = true;
        }

        cout << "Test #" << t++ << ": ";
        if (cnt == m) cout << "No of required PIs = " << res.size() << "\n";
        else cout << "PIs don't cover all MTs\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}

