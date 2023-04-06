// ----------------------------------------------------------------------------
// Problem : D. Count Paths
// Author  : Muahmmad Assawalhy
// Date    : 07-09-22
// ----------------------------------------------------------------------------

#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
#include "/home/ms/myp/problem-solving/debug.hpp"
#else
#define debug(...)
#define debug_itr(...)
#define debug_bits(...)
#endif

typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef unsigned long long ull;

#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define sz(x) (ll)(x).size()

constexpr ll MOD = 1e9 + 7;

template<typename T = int, int mod = MOD>
struct matrix {
    typedef vector<vector<T>> vv;
    vv mat;
    int n, m;

    matrix() { n = 0, m = 0; }
    matrix(vv mat) : mat(mat) { n = mat.size(), m = mat[0].size(); }
    matrix(int n, int m, T ini = 0) : n(n), m(m) { mat = vv(n, vector<T>(m, ini)); }

    matrix operator*(const matrix &other) const {
        matrix mat = *this;
        return mat *= other;
    }

    matrix operator+(const matrix &other) const {
        matrix mat = *this;
        return mat += other;
    }

    matrix operator-(const matrix &other) const {
        matrix mat = *this;
        return mat -= other;
    }

    matrix &operator*=(const matrix &other) {
        assert(m == other.n);
        vector<vector<T>> temp(n, vector<T>(other.m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < other.m; j++) {
                for (int k = 0; k < m; k++) {
                    temp[i][j] = (temp[i][j] + 1LL * mat[i][k] * other.mat[k][j]) % mod;
                }
            }
        }
        mat = temp;
        m = other.m;
        return *this;
    }

    matrix &operator+=(const matrix &other) {
        assert(m == other.m && n == other.n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                mat[i][j] = ((mat[i][j] + other.mat[i][j]) % mod + mod) % mod;
        }
        return *this;
    }

    matrix &operator-=(const matrix &other) {
        assert(m == other.m && n == other.n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                mat[i][j] = ((mat[i][j] - other.mat[i][j]) % mod + mod) % mod;
        }
        return *this;
    }

    matrix power(ll p) {
        assert(p >= 0);
        matrix m = *this;
        matrix res = identity(n);
        for (; p; p >>= 1, m *= m)
            if (p & 1) res *= m;
        return res;
    }

    static matrix identity(int size) {
        matrix I = vv(size, vector<T>(size));
        for (int i = 0; i < size; i++)
            I.mat[i][i] = 1;
        return I;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, q;
    cin >> n >> m >> q;

    matrix mat(n, n);

    for (int i = 0, a, b; i < m; i++) {
        cin >> a >> b, a--, b--;
        // a contributes to the next state of b
        mat.mat[a][b] = 1;
    }

    matrix<int, MOD> powers[31];
    powers[0] = mat.identity(n);
    powers[1] = mat;

    for (int i = 2; i < 31; i++) {
        powers[i] = powers[i - 1] * powers[i - 1];
    }

    int s, t, k;

    for (int i = 0; i < q; i++) {
        cin >> s >> t >> k, s--, t--;
        matrix dparr(1, n);
        dparr.mat[0][s] = 1;
        for (int x = 1; k; k >>= 1, x++)
            if (k & 1) dparr *= powers[x];
        cout << dparr.mat[0][t] << endl;
    }

    return 0;
}
