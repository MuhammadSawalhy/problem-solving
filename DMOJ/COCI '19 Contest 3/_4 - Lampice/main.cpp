#include <bits/stdc++.h>
using namespace std;

#ifdef SAWALHY
#include "debug.hpp"
#else
#define debug(...) 0
#define debug_itr(...) 0
#define debug_bits(...) 0
#endif

vector<long long> B;
const long long mod = (1LL << 61) - 1;

inline long long mul(long long a, long long b) {
    return __int128(a) * b % mod;
}

void setB(int n) {
    if (B.size() == 0) {
        mt19937 rng(random_device{}());
        B = {1, uniform_int_distribution<long long>(1, mod - 1)(rng)};
    }
    while ((int) B.size() <= n) B.push_back(mul(B.back(), B[1]));
}

const int N = 50005;
string s;
vector<int> adj[N], sz(N);
vector<long long> temp1, temp2;
set<long long> s1, s2;
long long down[N], up[N];
bool removed[N];
int n, len, node[N], depth[N], ans = 1;

void prepare(int i, int p) {
    depth[i] = p == -1 ? 0 : depth[p] + 1;
    sz[i] = 1;
    for (int j: adj[i]) {
        if (j == p || removed[j]) continue;
        prepare(j, i);
        sz[i] += sz[j];
    }
}

int find_centroid(int i, int p, int n) {
    for (int j: adj[i]) {
        if (j == p || removed[j]) continue;
        if (sz[j] > n / 2) return find_centroid(j, i, n);
    }
    return i;
}

bool check(int i, int p) {
    node[depth[i]] = i;

    if (p != -1) {
        down[i] = (down[p] + mul(s[i], B[depth[i]])) % mod;
        up[i] = (mul(up[p], B[1]) + s[i]) % mod;
    }

    if (depth[i] == len - 1) return down[i] == up[i];

    int l = len - 1 - depth[i];

    if (depth[i] - l >= 0) {
        int j = node[depth[i] - l];
        long long par = depth[i] - l > 0 ? up[node[depth[i] - l - 1]] : 0;
        long long hash = (up[i] - mul(par, B[l + 1]) + mod) % mod;
        if (up[j] == down[j]) {
            if (s2.count(hash)) return true;
            if (s1.count(hash)) ans = max(ans, depth[i] * 2 + 1);
            temp1.push_back(hash);
        }
    } else {
        if (s1.count(up[i])) return true;
        if (s2.count(up[i])) ans = max(ans, depth[i] * 2 + 1);
        temp2.push_back(up[i]);
    }

    for (int j: adj[i]) {
        if (j == p || removed[j]) continue;
        if (check(j, i)) return true;
    }

    return false;
}


bool check_len(int i) {
    if (len > n) return false;

    prepare(i, -1);
    int c = find_centroid(i, -1, sz[i]);
    prepare(c, -1);

    debug(c);

    s1.clear(), s2.clear();
    node[depth[c]] = c;
    up[c] = down[c] = s[c];
    for (int x: adj[c])
        if (!removed[x]) {
            temp1.clear(), temp2.clear();
            if (check(x, c)) return true;
            debug(x, temp1);
            debug(x, temp2);
            for (auto x: temp1) s1.insert(x);
            for (auto x: temp2) s2.insert(x);
        }

    removed[c] = true;
    for (int x: adj[c])
        if (!removed[x] && check_len(x)) return true;

    return false;
}

int32_t main(int32_t argc, char **argv) {
    cin.tie(nullptr)->sync_with_stdio(false);

    cin >> n >> s;
    setB(n + 1);

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int l, r;

    r = n, l = 0;
    while (r - l > 1) {
        int mid = (l + r) / 2;
        len = mid * 2;
        for (int i = 0; i < n; i++) removed[i] = false;
        debug("-----", len);
        if (check_len(0)) {
            l = mid;
        } else {
            r = mid;
        }
    }
    ans = max(ans, 2 * l);

    r = n, l = 0;
    while (r - l > 1) {
        int mid = (l + r) / 2;
        len = mid * 2 + 1;
        for (int i = 0; i < n; i++) removed[i] = false;
        if (check_len(0)) {
            l = mid;
        } else {
            r = mid;
        }
    }

    ans = max(ans, 2 * l + 1);
    cout << ans << endl;

    return 0;
}

