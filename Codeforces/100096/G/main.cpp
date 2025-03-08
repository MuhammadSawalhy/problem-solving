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

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n;
    cin >> n;
    pair<int, int> p;
    set<pair<int, int>> s;
    for (int i = 0; i < n; i++) {
        cin >> p.first >> p.second;
        p.second = -p.second;
        s.insert(p);
    }
    p.first = p.second = 0;
    int t;
    cin >> t;
    const int N = 1e5;
    int b = min(t, N);
    int mas[N + 1], r = 0;
    for (int i = 0; i < N; i++) {
        if (s.find(p) == s.end()) {
            s.insert(p);
            n++;
            if (r == 0) p.first--;
            else if (r == 1) p.second++;
            else if (r == 2) p.first++;
            else if (r == 3) p.second--;
            r = (r + 3) % 4;
        } else {
            s.erase(p);
            n--;
            if (r == 0) p.first++;
            else if (r == 1) p.second--;
            else if (r == 2) p.first--;
            else if (r == 3) p.second++;
            r = (r + 1) % 4;
        }
        debug(i + 1, n);
        mas[i + 1] = n;
        if (i + 1 - 114 > 0 && i % 114 == 0)
            debug(n - mas[i + 1 - 114]);
    }

    return 0;
}
