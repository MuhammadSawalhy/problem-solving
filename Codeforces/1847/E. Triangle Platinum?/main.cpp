// ﷽
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

bool is_good(int a, int b, int c) {
    return a + b > c && a + c > b && b + c > a;
}

int area(int a, int b, int c) {
    int s = a + b + c;
    return s * (s - 2 * a) * (s - 2 * b) * (s - 2 * c);
}

map<array<int, 3>, int> dp;

int ask(int i, int j, int k) {
    i++, j++, k++;
    if (dp.count({i, j, k}))
        return dp[{i, j, k}];
    cout << "? " << i << ' ' << j << ' ' << k << endl;
    int ans;
    cin >> ans;
    dp[{i, j, k}] = ans;
    return ans;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n;
    cin >> n;

    map<pair<int, int>, vector<int>> good, bad;

    for (int a = 1; a <= 4; a++) {
        for (int b = a; b <= 4; b++) {
            for (int c = 1; c <= 4; c++) {
                if (a + b > c && a + c > b && b + c > a) {
                    good[{a, b}].push_back(c);
                } else {
                    bad[{a, b}].push_back(c);
                }
            }
        }
    }

    for (int a = 1; a <= 4; a++) {
        for (int b = a; b <= 4; b++) {
            debug(pair<int, int>{a, b}, good[{a, b}]);
        }
    }

    for (int a = 1; a <= 4; a++) {
        for (int b = a; b <= 4; b++) {
            debug(pair<int, int>{a, b}, bad[{a, b}]);
        }
    }

    map<int, set<vector<int>>> areas;

    for (int a = 1; a <= 4; a++) {
        for (int b = 1; b <= 4; b++) {
            for (int c = 1; c <= 4; c++) {
                if (is_good(a, b, c)) {
                    vector<int> v{a, b, c};
                    sort(all(v));
                    areas[area(a, b, c)].insert(v);
                }
            }
        }
    }

    for (auto [a, v]: areas) {
        debug(a, v);
    }

    set<int> ind;
    vector<int> ops(n);
    vector<set<int>> a(n);

    for (int i = 0; i < n; i++) {
        ind.insert(i);
        for (int j = 1; j <= 4; j++)
            a[i].insert(j);
    }

    for (int i = 0; i < 15; i++) {
        
    }

    return 0;
}
