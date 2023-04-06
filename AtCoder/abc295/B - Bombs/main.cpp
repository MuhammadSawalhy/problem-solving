// ﷽
#include <algorithm>
#include <array>
#include <assert.h>
#include <chrono>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <string.h>
#include <utility>
#include <vector>

using namespace std;

#ifdef SAWALHY
#include "debug.hpp"
#else
#define debug(...) 0
#define debug_itr(...) 0
#define debug_bits(...) 0
#endif

#define int long long
#define ll long long
#define all(v) v.begin(), v.end()

string board[22];
int dist[22][22];
int r, c;

bool valid(int i, int j) {
    return i >= 0 && j >= 0 && i < r && j < c;
}

bool dfs(int i, int j, int d) {
    if (!valid(i, j)) return false;
    if (dist[i][j] <= d) return false;
    dist[i][j] = d;
    bool res = board[i][j] != '.' && board[i][j] != '#' && d <= board[i][j] - '0';

    res |= dfs(i + 1, j, d + 1);
    res |= dfs(i - 1, j, d + 1);
    res |= dfs(i, j - 1, d + 1);
    res |= dfs(i, j + 1, d + 1);

    debug(i, j, d, res, board[i][j]);

    return res;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> r >> c;

    for (int i = 0; i < r; i++) {
        cin >> board[i];
    }

    //         memset(dist, 0x3f, sizeof dist);
    //
    // debug(dfs(1, 1, 0));
    // return 0;

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (board[i][j] == '#') {
                memset(dist, 0x3f, sizeof dist);
                if (dfs(i, j, 0))
                    board[i][j] = '.';
            }
        }
    }


    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (board[i][j] != '#')
                board[i][j] = '.';
        }
        cout << board[i] << '\n';
    }


    return 0;
}
