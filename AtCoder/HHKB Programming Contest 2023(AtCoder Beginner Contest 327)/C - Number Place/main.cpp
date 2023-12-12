// ﷽
// https://atcoder.jp/contests/abc327/tasks/abc327_c

#include <bits/stdc++.h>
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
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define minit(v, x) v = min(v, x)
#define maxit(v, x) v = max(v, x)

// There is a 
// 9×9 grid 
// A, where each cell contains an integer between 
// 1 and 
// 9, inclusive.
// Specifically, the cell at the 
// i-th row from the top and 
// j-th column from the left contains 
// A 
// i,j
// ​
//  .
//
// If 
// A satisfies all of the following conditions, print Yes. Otherwise, print No.
//
// For each row of 
// A, the nine cells in that row contain each integer from 
// 1 to 
// 9 exactly once.
// For each column of 
// A, the nine cells in that column contain each integer from 
// 1 to 
// 9 exactly once.
// Divide the rows of 
// A into three groups, each of three rows, from top to bottom, and similarly divide the columns into three groups, each of three columns, from left to right. Each 
// 3×3 grid obtained from 
// A in this way contains each integer from 
// 1 to 
// 9 exactly once.

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int grid[9][9];
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> grid[i][j];
        }
    }

    for (int i = 0; i < 9; i++) {
        int a[10] = {0};
        for (int j = 0; j < 9; j++) {
            a[grid[i][j]]++;
        }
        for (int j = 1; j < 10; j++) {
            if (a[j] != 1) {
                cout << "No" << endl;
                return 0;
            }
        }
    }

    for (int i = 0; i < 9; i++) {
        int a[10] = {0};
        for (int j = 0; j < 9; j++) {
            a[grid[j][i]]++;
        }
        for (int j = 1; j < 10; j++) {
            if (a[j] != 1) {
                cout << "No" << endl;
                return 0;
            }
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            int a[10] = {0};
            for (int k = 0; k < 3; k++) {
                for (int l = 0; l < 3; l++) {
                    a[grid[i * 3 + k][j * 3 + l]]++;
                }
            }
            for (int j = 1; j < 10; j++) {
                if (a[j] != 1) {
                    cout << "No" << endl;
                    return 0;
                }
            }
        }
    }

    cout << "Yes" << endl;

    return 0;
}
