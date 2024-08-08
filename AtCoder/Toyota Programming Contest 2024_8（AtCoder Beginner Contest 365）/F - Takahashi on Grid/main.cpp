// ﷽
// https://atcoder.jp/contests/abc365/tasks/abc365_f

#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;

#ifdef SAWALHY
#include "debug.hpp"
#else
#define debug(...) 0
#define debug_itr(...) 0
#define debug_bits(...) 0
#endif

#define ll long long
#define int long long
#define sz(v) (int) (v).size()
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define minit(v, x...) v = min({v, x})
#define maxit(v, x...) v = max({v, x})

template<class T>
using rpq = priority_queue<T, vector<T>, greater<T>>;

struct DSU {
    vector<int> size, parent, value, y;
    int forests;

    DSU(int n) : forests(n) {
        size.assign(n, 1);
        value.resize(n);
        y.resize(n);
        parent.resize(n), iota(all(parent), 0);
    }

    bool connected(int x, int y) { return find(x) == find(y); }

    int find(int x) {
        if (parent[x] == x) return x;
        // return parent[x] = find(parent[x]);
        return find(parent[x]);
    }

    pair<int, int> uni(int x, int y, bool isl) { // merge x into y
        debug(x, y);
        x = find(x), y = find(y);
        if (x == y) return {-1, -1};
        if (size[x] > size[y]) swap(x, y);
        forests--;
        parent[x] = y;
        size[y] += size[x];
        value[x] -= value[y];
        move(x, this->y[y], isl);
        return {x, y};
    }

    void move(int x, int pos, bool isl) {
        if (isl) {
            value[x] += pos - y[x];
        } else {
            value[x] -= pos - y[x];
        }
        y[x] = pos;
    }
};


void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> ranges(n);
    for (int i = 0; i < n; i++) {
        cin >> ranges[i].first >> ranges[i].second;
    }

    int q;
    cin >> q;
    vector<array<int, 5>> quer;
    vector<vector<int>> start(n + 1), end(n + 1);
    for (int i = 0; i < q; i++) {
        int sx, sy, tx, ty;
        cin >> sx >> sy >> tx >> ty;
        auto a = pair<int, int>(sx, sy);
        auto b = pair<int, int>(tx, ty);
        if (b < a) swap(a, b);
        quer.push_back({a.first, a.second, b.first, b.second, i});
        start[a.first].push_back(i);
        end[b.first].push_back(i);
    }

    DSU dsu(q);

    vector<int> ans(q);

    set<pair<int, int>> s;
    for (int i = 1; i <= n; i++) {
        auto [l, u] = ranges[i - 1];
        for (auto j: start[i]) {
            s.insert({quer[j][1], j});
            dsu.y[j] = quer[j][1];
        }

        debug(i, s);

        // move and merge
        {
            vector<int> tomove;
            while (s.size() && s.begin()->first < l) {
                tomove.push_back(s.begin()->second);
                s.erase(s.begin());
            }

            for (int i = 1; i < sz(tomove); i++) {
                auto [xx, yy] = dsu.uni(tomove[i - 1], tomove[i], true);
                assert(~yy);
                tomove[i] = yy;
            }

            if (tomove.size()) {
                s.insert({l, tomove.back()});
                dsu.move(tomove.back(), l, true);
            }
        }

        {
            vector<int> tomove;
            while (s.size() && prev(s.end())->first > u) {
                tomove.push_back(prev(s.end())->second);
                s.erase(prev(s.end()));
            }

            for (int i = 1; i < sz(tomove); i++) {
                auto [xx, yy] = dsu.uni(tomove[i - 1], tomove[i], false);
                assert(~yy);
                tomove[i] = yy;
            }

            if (tomove.size()) {
                s.insert({u, tomove.back()});
                dsu.move(tomove.back(), u, false);
            }
        }

        // answer queries

        for (auto j: end[i]) {
            debug(j);
            ans[j] += quer[j][2] - quer[j][0];
            int x = j;
            while (true) {
                ans[j] += dsu.value[x];
                if (dsu.parent[x] == x) break;
                x = dsu.parent[x];
            }
            ans[j] += abs(dsu.y[x] - quer[j][3]);
        }
    }

    for (int i = 0; i < q; i++) {
        cout << ans[i] << endl;
    }
}

namespace stress
{

void brute() {
    int n;
    cin >> n;
    vector<pair<int, int>> ranges(n);
    for (int i = 0; i < n; i++) {
        cin >> ranges[i].first >> ranges[i].second;
    }

    int q;
    cin >> q;
    vector<array<int, 5>> quer;
    vector<vector<int>> start(n + 1), end(n + 1);
    for (int i = 0; i < q; i++) {
        int sx, sy, tx, ty;
        cin >> sx >> sy >> tx >> ty;
        auto a = pair<int, int>(sx, sy);
        auto b = pair<int, int>(tx, ty);
        if (b < a) swap(a, b);
        quer.push_back({a.first, a.second, b.first, b.second, i});
        start[a.first].push_back(i);
        end[b.first].push_back(i);
    }

    vector<int> ans(q);
    vector<int> y(q);

    set<pair<int, int>> s;
    for (int i = 1; i <= n; i++) {
        auto [l, u] = ranges[i - 1];
        for (auto j: start[i]) {
            s.insert({quer[j][1], j});
            y[j] = quer[j][1];
        }

        // move and merge
        {
            while (s.size() && s.begin()->first < l) {
                auto [_, j] = *s.begin();
                s.erase(s.begin());
                ans[j] += abs(l - y[j]);
                y[j] = l;
                s.insert({l, j});
            }
        }

        // move and merge
        {
            while (s.size() && prev(s.end())->first > u) {
                auto [_, j] = *prev(s.end());
                s.erase(prev(s.end()));
                ans[j] += abs(u - y[j]);
                y[j] = u;
                s.insert({u, j});
            }
        }

        debug(i, s);

        // answer queries
        for (auto j: end[i]) {
            debug(j, y[j], quer[j][3]);
            ans[j] += quer[j][2] - quer[j][0];
            ans[j] += abs(y[j] - quer[j][3]);
            s.erase({y[j], j});
        }
    }

    for (int i = 0; i < q; i++) {
        cout << ans[i] << endl;
    }
}

mt19937 rng = mt19937(random_device()());

void seed(int s) { rng = mt19937(s); }

int rand_int(int x, int y) {
    return uniform_int_distribution<int>(x, y)(rng);
}

void generate() {
    int n = rand_int(2, 5), q = rand_int(1, 1);

    cout << n << endl;

    vector<pair<int, int>> ranges(n);

    ranges[0].first = rand_int(1, 10);
    ranges[0].second = rand_int(ranges[0].first, 10);
    for (int i = 1; i < n; i++) {
        auto [l, r] = ranges[i - 1];
        int x = rand_int(1, 10);
        if (x > r) {
            ranges[i].first = rand_int(1, r);
            ranges[i].second = x;
        } else {
            ranges[i].first = x;
            ranges[i].second = rand_int(max(x, l), 10);
        }
    }

    for (int i = 0; i < n; i++) {
        cout << ranges[i].first << ' ' << ranges[i].second << endl;
    }

    cout << q << endl;

    while (q--) {
        int sx = rand_int(1, n);
        int sy = rand_int(ranges[sx - 1].first, ranges[sx - 1].second);
        int tx = rand_int(1, n);
        int ty = rand_int(ranges[tx - 1].first, ranges[tx - 1].second);
        cout << sx << ' ' << sy << ' ' << tx << ' ' << ty << endl;
    }
}

string readAllTheFile(const string &filename) {
    ifstream file(filename);
    string content;
    string line;

    if (file.is_open()) {
        while (getline(file, line)) content += line + "\n";
        file.close();
    }
    return content;
}

void stress(int argc, char **argv) {
#ifndef STRESS
    return;
#endif
    if (argc > 1) seed(stoi(argv[1]));
    for (int iter = 0; iter < 100000; iter++) {
        cerr << iter << endl;
        FILE *input, *output;

        input = freopen("/tmp/stress-input", "w", stdout);
        generate();
        fclose(input);

        input = freopen("/tmp/stress-input", "r", stdin);
        output = freopen("/tmp/stress-main", "w", stdout);
        solve();
        fclose(input);
        fclose(output);

        input = freopen("/tmp/stress-input", "r", stdin);
        output = freopen("/tmp/stress-brute", "w", stdout);
        brute();
        fclose(input);
        fclose(output);

        string m = readAllTheFile("/tmp/stress-main");
        string b = readAllTheFile("/tmp/stress-brute");

        if (m != b) {
            string i = readAllTheFile("/tmp/stress-input");
            cerr << "input  --------------------------------" << endl;
            cerr << i << endl;
            cerr << "main   --------------------------------" << endl;
            cerr << m << endl;
            cerr << "brute  --------------------------------" << endl;
            cerr << b << endl;
            exit(1);
        }
    }
    exit(0);
}

} // namespace stress

int32_t main(int32_t argc, char **argv) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    stress::stress(argc, argv);

    int t = 1;
    // cin >> t;
    while (t--)
        // stress::brute();
        solve();

    return 0;
}
