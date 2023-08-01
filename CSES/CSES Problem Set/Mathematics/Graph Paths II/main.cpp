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

constexpr ll mod = 1000000007, INF = 2e18;

typedef vector<vector<ll>> matrix;
struct matrix_expo {
    // it must be square matrix
    matrix mat;
    matrix_expo(matrix mat) : mat(mat){};

    matrix_expo operator*(matrix_expo m) {
        assert(mat[0].size() == m.mat.size());
        matrix_expo mult = matrix(mat.size(), vector<long long>(m.mat[0].size(), INF));
        for (int i = 0; i < mat.size(); i++) {
            for (int j = 0; j < m.mat[0].size(); j++) {
                for (int k = 0; k < m.mat.size(); k++) {
                    mult.mat[i][j] = min(mult.mat[i][j], mat[i][k] + m.mat[k][j]);
                }
            }
        }
        return mult;
    }

    matrix_expo power(long long n) {
        // start with identity matrix
        matrix_expo res(matrix(mat.size(), vector<ll>(mat.size(), INF)));
        for (int i = 0; i < mat.size(); i++)
            res.mat[i][i] = 0;
        matrix_expo m = *this;
        while (n) {
            if (n & 1)
                res = res * m;
            m = m * m;
            n >>= 1;
        }
        return res;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, k;
    cin >> n >> m >> k;
    matrix mat(n, vector<ll>(n, INF));

    for (int i = 0; i < m; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        mat[b][a] = min(mat[b][a], c);
    }

    matrix_expo paths(mat);
    matrix_expo ini_paths(matrix(n, vector<ll>(1, INF)));
    ini_paths.mat[0][0] = 0;
    paths = paths.power(k) * ini_paths;
    if (paths.mat[n - 1][0] >= INF)
        cout << "IMPOSSIBLE" << endl;
    else
        cout << paths.mat[n - 1][0] << endl;
    return 0;
}
