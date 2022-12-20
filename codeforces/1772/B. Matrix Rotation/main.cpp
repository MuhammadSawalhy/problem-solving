// Date: 18-12-2022
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define all(v) v.begin(), v.end()
#define debug(...)
#ifdef LOCAL
#include "debug.hpp"
#endif

int mat[2][2];

void rotate() {
    int rot[2][2]; 
    rot[0][0] = mat[1][0];
    rot[0][1] = mat[0][0];
    rot[1][0] = mat[1][1];
    rot[1][1] = mat[0][1];

    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            mat[i][j] = rot[i][j];
}

bool valid() {
    return mat[0][0] > mat[0][1] && mat[1][0] > mat[1][1] && mat[0][0] > mat[1][0] && mat[0][1] > mat[1][1];
}

void solve() {
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            cin >> mat[i][j];

    for (int i = 0; i < 4; i++) {
        rotate();
        if (valid()) {
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
