// ﷽
// https://codeforces.com/contest/1866/problem/G
// Codeforces -> COMPFEST 15 - Preliminary Online Mirror (Unrated, ICPC Rules, Teams Preferred) -> G. Grouped Carriages

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
#define all(v) v.begin(), v.end()

char in[1 << 24];
struct scanner {
    char const *o;
    scanner() : o(in) { load(); }
    void load() { in[fread(in, 1, sizeof(in) - 4, stdin)] = 0; }
    unsigned readInt() {
        unsigned u = 0;
        while (*o && *o <= 32)
            ++o;
        while (*o >= '0' && *o <= '9')
            u = u * 10 + (*o++ - '0');
        return u;
    }
};

void solve() {
    scanner sc;

    int n = sc.readInt();

    vector<int> a(n), d(n);
    for (int &i: a) i = sc.readInt();
    for (int &i: d) i = sc.readInt();

    auto check = [&](int x) -> bool {
        set<int> ind;
        vector<int> B(n);
        vector<int> A = a;
        priority_queue<pair<int, int>> pq;

        for (int i = 0; i < n; i++) {
            pq.push({-min(i + d[i], n - 1), i});
            ind.insert(i);

            // try to empty him what is ending here
            while (pq.size() && -pq.top().first == i) {
                int j = pq.top().second;
                pq.pop();

                while (A[j] > 0) {
                    auto it = ind.lower_bound(j - d[j]);
                    if (it == ind.end()) break;
                    int k = *it;
                    int toempty = min(x - B[k], A[j]);
                    A[j] -= toempty;
                    B[k] += toempty;
                    if (B[k] == x) ind.erase(it);
                }

                if (A[j] > 0) return false;
            }
        }

        return true;
    };

    int s = -1, e = 1e9 + 9;
    while (e - s > 1) {
        int x = (e + s) / 2;
        if (check(x)) e = x;
        else s = x;
    }

    cout << e << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    solve();

    return 0;
}
