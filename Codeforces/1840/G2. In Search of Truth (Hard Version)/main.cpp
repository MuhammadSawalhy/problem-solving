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

const int N = 1e6 + 6;
vector<vector<int>> factors(N);

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int x;
    cin >> x;

    for (int i = 1; i <= N; i++) {
        for (int j = i; j <= N; j += i) {
            factors[j].push_back(i);
        }
    }

    set<int> s;

    for (int i = 1; i <= 1000; i++) {
        int sum = 0;
        for (int j = i; j <= 1000; j++) {
            sum += j;
            for (auto f: factors[sum]) {
                s.insert(f);
            }
        }
    }

    debug(s.size());

    return 0;
}
