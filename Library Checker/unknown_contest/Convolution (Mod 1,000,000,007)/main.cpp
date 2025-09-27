#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define all(v) begin(v), end(v)
#define rall(v) rbegin(v), rend(v)

struct Mod {
    int m, root, p2;
};

const Mod mods[] = {
        {998244353, 3, 23},
        {1004535809, 3, 21},
        {2013265921, 31, 27},
        {469762049, 3, 26},
};

int pwr(int a, int b, const Mod &mod) {
    int r = 1;
    while (b) {
        if (b & 1) r = 1LL * r * a % mod.m;
        a = 1LL * a * a % mod.m;
        b >>= 1;
    }
    return r;
}

void ntt(vector<int> &a, bool isinv, const Mod &mod) {
    int n = a.size();
    for (int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        for (; j & bit; bit >>= 1) j ^= bit;
        j ^= bit;
        if (i < j) swap(a[i], a[j]);
    }
    for (int len = 2; len <= n; len <<= 1) {
        int wlen = pwr(mod.root, (mod.m - 1) / len, mod);
        if (isinv) wlen = pwr(wlen, mod.m - 2, mod);
        for (int i = 0; i < n; i += len) {
            int w = 1;
            for (int j = 0; j < len / 2; ++j) {
                int u = a[i + j];
                int v = 1ull * a[i + j + len / 2] * w % mod.m;
                a[i + j] = (u + v < mod.m ? u + v : u + v - mod.m);
                a[i + j + len / 2] = (u - v >= 0 ? u - v : u - v + mod.m);
                w = 1ull * w * wlen % mod.m;
            }
        }
    }
    if (isinv) {
        int inv_n = pwr(n, mod.m - 2, mod);
        for (int &x: a) x = 1ull * x * inv_n % mod.m;
    }
}

vector<int> multiply(vector<int> a, vector<int> b, const Mod &mod = mods[0]) {
    int sz = 1, total = a.size() + b.size() - 1;
    while (sz < total) sz <<= 1;
    a.resize(sz);
    b.resize(sz);
    ntt(a, false, mod);
    ntt(b, false, mod);
    for (int i = 0; i < sz; ++i) a[i] = 1LL * a[i] * b[i] % mod.m;
    ntt(a, true, mod);
    a.resize(total);
    return a;
}


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;
    vector<int> a(N), b(M);
    for (int i = 0; i < N; i++)
        cin >> a[i];
    for (int i = 0; i < M; i++)
        cin >> b[i];

    const int P = sizeof(mods) / sizeof(mods[0]), MOD = mods[0].m;
    vector<vector<int>> convs;
    for (int i = 0; i < P; i++) {
        auto conv = multiply(a, b, mods[i]);
        convs.push_back(conv);
    }

    vector<vector<long long>> r(P, vector<long long>(P));
    for (int i = 0; i < P; i++) {
        for (int j = 0; j < i; j++) {
            r[j][i] = pwr(mods[j].m, mods[i].m - 2, mods[i]);
        }
    }

    vector<int> result;
    for (int k = 0; k < N + M - 1; k++) {
        vector<long long> rs;
        for (int i = 0; i < P; i++)
            rs.push_back(convs[i][k]);
        long long res = 0;
        long long product = 1;
        vector<int> x(P, 0);
        for (int i = 0; i < P; i++) {
            x[i] = rs[i];
            for (int j = 0; j < i; j++) {
                x[i] = (r[j][i] * (x[i] - x[j]) % mods[i].m + mods[i].m) % mods[i].m;
            }
            res = (res + x[i] * product) % MOD;
            product = (product * mods[i].m) % MOD;
        }
        result.push_back(res);
    }

    for (int i = 0; i < result.size(); i++) {
        if (i > 0)
            cout << " ";
        cout << result[i];
    }
    cout << endl;

    return 0;
}
