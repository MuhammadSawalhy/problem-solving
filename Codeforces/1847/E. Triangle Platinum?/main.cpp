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

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    // vector<vector<pair<int, int>>> good(5), bad(5);
    // map<int, int> cntgood, cntbad;
    //
    // for (int a = 1; a <= 4; a++) {
    //     for (int b = 1; b <= 4; b++) {
    //         for (int c = 1; c <= 4; c++) {
    //             if (a + b > c && a + c > b && b + c > a) {
    //                 good[a].push_back({b, c});
    //                 cntgood[a] = good[a].size();
    //             } else {
    //                 bad[a].push_back({b, c});
    //                 cntbad[a] = bad[a].size();
    //             }
    //         }
    //     }
    // }
    //
    // debug(good);
    // debug(bad);
    // debug(cntgood);
    // debug(cntbad);

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


    return 0;
}
