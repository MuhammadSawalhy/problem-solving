// ﷽
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

template<typename Edge>
class DirectedEulerian {
public:
    int n, m;
    vector<vector<pair<int, Edge>>> adj;
    DirectedEulerian(int n, int m, vector<vector<pair<int, Edge>>> adj) : adj(adj), n(n), m(m) {}

    vector<Edge> path(bool circuit = false) {
        vector<Edge> path;
        int in = 0, out = 0;

        calc_deg();
        int start = -1, end = -1;
        for (int i = 0; i < n; i++) {
            if (indeg[i] > outdeg[i])
                in += indeg[i] - outdeg[i], end = i;
            else if (indeg[i] < outdeg[i])
                out += outdeg[i] - indeg[i], start = i;
        }

        if (m == 0 || !((in == 0 && out == 0) || (in == 1 && out == 1 && !circuit))) {
            return {};
        }

        if (start == -1) {
            assert(end == -1);
            for (int i = 0; i < n; i++) {
                if (outdeg[i] > 0) {
                    start = end = i;
                    break;
                }
            }
        }

        dfs(start, {}, path);

        path.pop_back();
        reverse(all(path));

        return path;
    }

private:
    vector<int> indeg, outdeg;

    void calc_deg() {
        indeg.assign(n, 0);
        outdeg.assign(n, 0);
        for (int i = 0; i < n; i++) {
            outdeg[i] = adj[i].size();
            for (auto &j: adj[i]) indeg[j.first]++;
        }
    }

    void dfs(int i, Edge e, vector<Edge> &path) {
        while (outdeg[i] > 0)
            outdeg[i]--, dfs(adj[i][outdeg[i]].first, adj[i][outdeg[i]].second, path);
        path.push_back(e);
    }
};

int val(char c) {
    if (c >= 'a')
        return 100 - 26 + c - 'a';
    if (c >= 'A')
        return 50 - 26 + c - 'A';
    return c - '0';
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n;
    cin >> n;

    vector<vector<pair<int, string>>> adj(100 * 100);

    string s;
    for (int i = 0; i < n; i++) {
        cin >> s;
        int a = val(s[0]), b = val(s[1]), c = val(s[2]);
        adj[a * 100 + b].push_back({ b * 100 + c, s });
    }

    auto path = DirectedEulerian<string>(100 * 100, n, adj).path();

    if (path.size() != n) {
        cout << "NO" << endl;
        return 0;
    }

    cout << "YES" << endl;
    for (int i = 0; i < path.size() - 1; i++) {
        cout << path[i][0];
    }
    cout << path.back();

    return 0;
}
