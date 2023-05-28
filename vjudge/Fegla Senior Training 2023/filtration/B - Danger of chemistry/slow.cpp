// ﷽
#include <bits/stdc++.h>

using namespace std;

#ifdef SAWALHY
#include "debug.hpp"
#else
#define debug(...)      0
#define debug_itr(...)  0
#define debug_bits(...) 0
#endif

#define ll     long long
#define int    long long
#define all(v) v.begin(), v.end()

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        ll ans = 1e18;
        vector<int> ansfirst, anssecond;

        if (n == 1) {
            cout << 0 << endl;
            continue;
        }

        for (int mask = 0; mask < 1 << n; mask++) {
            if (__builtin_popcount(mask) != n / 2) continue;
            vector<int> first, second;
            for (int i = 0; i < n; i++) {
                if (mask >> i & 1) first.push_back(a[i]);
                else second.push_back(a[i]);
            }

            sort(all(first));
            sort(all(second));

            map<int, pair<int, vector<int>>> res1;
            map<int, pair<int, vector<int>>> res2;

            do {
                ll sum = 0;
                for (int i = 0; i + 1 < (int) first.size(); i++) {
                    sum += gcd(first[i], first[i + 1]);
                }
                if (res1.find(first.back()) == res1.end() || res1[first.back()].first > sum)
                    res1[first.back()] = {sum, first};
            } while (next_permutation(all(first)));

            do {
                ll sum = 0;
                for (int i = 0; i + 1 < (int) second.size(); i++) {
                    sum += gcd(second[i], second[i + 1]);
                }
                if (res2.find(second.front()) == res2.end() || res2[second.front()].first > sum)
                    res2[second.front()] = {sum, second};
            } while (next_permutation(all(second)));

            for (auto [x, X]: res1) {
                for (auto [y, Y]: res2) {
                    long long danger = X.first + Y.first + gcd(x, y);
                    if (danger < ans || ans == danger && (X.second < ansfirst || X.second == ansfirst && Y.second < anssecond)) {
                        ans = danger;
                        ansfirst = X.second;
                        anssecond = Y.second;
                    }
                }
            }
        }

        vector<pair<int, int>> swaps;
        vector<int> ansitems;
        for (auto i: ansfirst)
            ansitems.push_back(i);
        for (auto i: anssecond)
            ansitems.push_back(i);


        assert(ansitems.size() == n);
        // previous that didn't found a previous one
        // it is with this value and needs a[i]

        map<int, set<int>> inds;

        for (int i = 0; i < n; i++) {
            inds[a[i]].insert(i);
        }

        for (int i = 0; i < n; i++) {
            if (a[i] == ansitems[i]) {
                inds[a[i]].erase(i);
                continue;
            }

            int j = *inds[ansitems[i]].begin();
            swaps.push_back({i + 1, j + 1});
            inds[a[i]].erase(i);
            inds[a[j]].erase(j);
            swap(a[i], a[j]);
            inds[a[j]].insert(j);
        }

        cout << swaps.size() << endl;
        for (auto [x, y]: swaps)
            cout << x << ' ' << y << endl;
    }

    return 0;
}
