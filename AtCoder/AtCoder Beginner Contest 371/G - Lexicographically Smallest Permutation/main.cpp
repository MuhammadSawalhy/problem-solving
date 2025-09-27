#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define all(v) begin(v), end(v)
#define rall(v) rbegin(v), rend(v)

// returns (x,y) such that:
// a * x + b * y = gcd(a, b)
// b * x + (a%b) * y       = gcd(a,b)
// b * x + (a-(a/b)*b) * y = gcd(a,b)
// a * y + b * (x-(a/b)*y) = gcd(a,b)
// x2 = y1, y2 = x1 - (a/b)*y1
pair<long long, long long> exgcd(long long a, long long b) {
    if (!b) return {1, 0};
    pair<long long, long long> p = exgcd(b, a % b);
    return {p.second, p.first - (a / b) * p.second};
}

// v = a1 mod b1
// v = a2 mod b2
// v = a1 + x * b1 = a2 + y * b2
// x * b1 + y * -b2 = a2 - a1
bool is_solvable(pair<int, int> a, pair<int, int> b) {
    auto [x, y] = exgcd(a.second, -b.second);
    int d = b.first - a.first;
    int g = gcd(a.second, b.second);
    if (d % g) return false;
    return true;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;
    int p[n];
    int a[n];

    for (int i = 0; i < n; i++) cin >> p[i], p[i]--;
    for (int i = 0; i < n; i++) cin >> a[i], a[i]--;

    vector<int> pos(n, -1);
    vector<int> cyid(n, -1);
    int cnt = 0;
    vector<int> inds[n];
    for (int i = 0; i < n; i++) {
        if (~pos[i]) continue;
        int j = i;
        pos[i] = 0;
        cnt++;
        while (true) {
            cyid[j] = cnt - 1;
            inds[cnt - 1].push_back(j);
            if (~pos[p[j]]) break;
            pos[p[j]] = pos[j] + 1;
            j = p[j];
        }
    }

    vector<pair<int, int>> equations;

    vector<int> shift(n, -1);
    for (int i = 0; i < n; i++) {
        int id = cyid[i], sz = inds[id].size();
        if (shift[id] != -1) continue;
        int f = 1e9, ff;
        for (auto j: inds[id]) {
            // t = -pos[j] mod sz
            auto eq = make_pair(-pos[j], sz);
            bool ok = true;
            for (auto e: equations) {
                ok &= is_solvable(e, eq);
            }
            if (ok && a[j] < f) {
                f = a[j];
                ff = j;
            }
        }
        assert(f < 1e9);
        equations.push_back({-pos[ff], sz});
        shift[id] = sz - pos[ff];
    }

    for (int i = 0; i < n; i++) {
        int id = cyid[i];
        /*cout << id << ' ' << shift[id] << endl;*/
        assert(inds[id][pos[i]] == i);
        int j = inds[id][(pos[i] - shift[id] + inds[id].size()) % inds[id].size()];
        cout << a[j] + 1 << ' ';
    }

    return 0;
}
