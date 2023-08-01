// ﷽
#include <bits/stdc++.h>

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

using namespace std;

constexpr ll MOD = 1e9 + 7;

template<typename T = int, int mod = MOD>
struct matrix {
    typedef vector<vector<T>> vv;
    vv mat;
    int n, m;

    matrix(vv mat) : mat(mat) {
        n = mat.size();
        m = mat[0].size();
    }

    matrix(int n, int m) : n(n), m(m) { mat = vv(n, vector<T>(m)); }

    matrix operator*(matrix other) {
        assert(m == other.n);
        matrix mult = vv(n, vector<T>(other.m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < other.m; j++) {
                for (int k = 0; k < m; k++) {
                    mult.mat[i][j] += mat[i][k] * other.mat[k][j] % mod;
                    mult.mat[i][j] %= mod;
                }
            }
        }
        return mult;
    }

    matrix operator+(matrix other) {
        assert(m == other.m && n == other.n);
        matrix s = mat;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                s.mat[i][j] += other.mat[i][j];
                s.mat[i][j] %= mod;
            }
        }
        return s;
    }

    matrix operator-(matrix other) {
        assert(m == other.m && n == other.n);
        matrix s = mat;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                s.mat[i][j] -= other.mat[i][j];
                s.mat[i][j] %= mod;
            }
        }
        return s;
    }

    matrix power(ll p) {
        // start with identity matrix
        matrix res = identity(n);
        matrix m = *this;
        while (p) {
            if (p & 1)
                res = res * m;
            m = m * m;
            p >>= 1;
        }
        return res;
    }

    ll det() {
        assert(n == m);
        if (n == 2)
            return mat[0][0] * mat[1][1] - mat[1][0] * mat[0][1];
        ll d = 0;
        int sign = 1;
        for (int i = 0; i < n; i++) {
            matrix submat(n - 1, n - 1);
            for (int j = 0; j < n - 1; j++) {
                int x = 0;
                for (int k = 0; k < n; k++) {
                    if (i == k)
                        continue;
                    submat.mat[j][x++] = mat[j + 1][k];
                }
            }
            debug(sign * mat[0][i], submat.mat);
            d += sign * mat[0][i] * submat.det();
            sign *= -1;
        }

        return d;
    }

    static matrix identity(int size) {
        matrix I = vv(size, vector<ll>(size));
        for (int i = 0; i < size; i++)
            I.mat[i][i] = 1;
        return I;
    }
};

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    ll n;
    cin >> n;
    matrix mat = vector<vector<int>>{{0, 1}, {1, 1}};
    mat = mat.power(n);
    
    cout << mat.mat[0][1] << endl;

    return 0;
}
