// ﷽
#include <algorithm>
#include <array>
#include <assert.h>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string.h>
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

struct dsu {
    vector<int> rank, parent;
    int forests;

    dsu(int n) {
        forests = n;
        rank = vector<int>(n);
        parent = vector<int>(n);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    bool connected(int x, int y) { return find(x) == find(y); }

    int find(int x) {
        if (parent[x] == x)
            return x;
        return parent[x] = find(parent[x]);
    }

    bool uni(int x, int y) {
        x = find(x), y = find(y);
        if (x == y)
            return false;
        parent[y] = x;
        return true;
    }
};

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    multiset<pair<int, int>> edges;
    vector<pair<int, int>> schedule[m];
    vector<vector<int>> connections(n, vector<int>(2, -1));
    dsu monkeys(n);

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        if (~a) {
            edges.insert({ i, a - 1 });
            connections[i][0] = a - 1;
        }
        if (~b) {
            edges.insert({ i, b - 1 });
            connections[i][1] = b - 1;
        }
    }

    for (int i = 0; i < m; i++) {
        int p, h;
        cin >> p >> h;
        p--, h--;
        assert(~connections[p][h]);
        pair<int, int> edge = { p, connections[p][h] };
        schedule[i].push_back(edge);
        edges.erase(edges.find(edge));
    }

    vector<int> ans(n, -1), sequence, parent(n, -1);

    for (auto [a, b] : edges) {
        schedule[m - 1].push_back({ a, b });
    }
    reverse(all(schedule[m - 1]));

    debug(connections);
    debug_itr(schedule, m, 1);

    for (int sec = m - 1; sec >= 0; sec--) {
        for (auto [a, b] : schedule[sec]) {
            if (!monkeys.connected(a, b)) {
                a = monkeys.find(a);
                b = monkeys.find(b);
                if (b == 0) swap(a, b);
                if (a == 0) {
                    ans[b] = sec;
                    monkeys.uni(a, b);
                    continue;
                }
                sequence.push_back(b);
                parent[b] = a;
                monkeys.uni(a, b);
            }
        }
    }

    debug(sequence);
    debug(ans);

    assert(sequence.size() < n);

    while (sequence.size()) {
        int mon = sequence.back();
        assert(~parent[mon]);
        ans[mon] = ans[parent[mon]];
        assert(~ans[mon]);
        sequence.pop_back();
    }

    assert(ans[0] == -1);
    for (auto i : ans)
        cout << i << '\n';

    return 0;
}
