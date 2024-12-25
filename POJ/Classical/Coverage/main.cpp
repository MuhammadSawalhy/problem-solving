#include <bits/stdc++.h>
using namespace std;

const int N = 5005;
int comp[N], sz[N], cnt;
double x[N], y[N];
vector<int> adj[N];
vector<int> near[N];

vector<pair<double, double>> intersection(int i, int j, double r) {
    double dx = x[i] - x[j], dy = y[i] - y[j];
    double d = sqrt(dx * dx + dy * dy);

    if (d > 2 * r || d == 0) return {};

    double mx = (x[i] + x[j]) / 2;
    double my = (y[i] + y[j]) / 2;
    double h = sqrt(r * r - (d / 2) * (d / 2));
    double dx_perp = -dy / d;
    double dy_perp = dx / d;

    return {{mx + h * dx_perp, my + h * dy_perp},
            {mx - h * dx_perp, my - h * dy_perp}};
}

void dfs(int i, int c) {
    comp[i] = c, sz[c]++;
    for (auto j: adj[i])
        if (comp[j] == 0) dfs(j, c);
}

int32_t main(int32_t argc, char **argv) {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> x[i] >> y[i];

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            double dx = x[i] - x[j], dy = y[i] - y[j];
            double d = sqrt(dx * dx + dy * dy);
            if (d <= 2) adj[i].push_back(j), adj[j].push_back(i);
            if (d <= 20) near[i].push_back(j), near[j].push_back(i);
        }
    }

    int ans = 0;

    for (int i = 0; i < n; i++) {
        if (comp[i] == 0) dfs(i, ++cnt);
        ans = max(ans, sz[comp[i]] + 1);
    }

    for (int i = 0; i < n; i++) {
        for (auto j: near[i]) {
            auto points = intersection(i, j, 2);
            if (points.empty()) continue;
            for (auto [px, py]: points) {
                set<int> comps{comp[i], comp[j]};
                for (auto k: near[i]) {
                    double dx = x[k] - px, dy = y[k] - py;
                    double d = sqrt(dx * dx + dy * dy);
                    if (d <= 2) comps.insert(comp[k]);
                }
                int cur = 1;
                for (auto c: comps) cur += sz[c];
                ans = max(ans, cur);
            }
        }
    }

    cout << ans << endl;

    return 0;
}
