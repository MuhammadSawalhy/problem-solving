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

const int H = 10;
int h, w, a[H][H];
int ans;

void dfs(int i, int j, set<int> values) {
    if (i >= h || j >= w) return;
    values.insert(a[i][j]);

    if (i == h - 1 && j == w - 1) {
        if (values.size() == w + h - 1) ans++;
        return;
    }

    dfs(i + 1, j, values);
    dfs(i, j + 1, values);
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> h >> w;

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++)
            cin >> a[i][j];
    }

    dfs(0, 0, {});

    cout << ans << endl;

    return 0;
}
