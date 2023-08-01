// ﷽
#include <bits/stdc++.h>

using namespace std;

#ifdef SAWALHY
#include "debug.hpp"
#else
#define debug(...)
#define debug_itr(...)
#define debug_bits(...)
#endif

#define int long long
#define ll long long
#define all(v) v.begin(), v.end()

int mod(int i, int m) {
    return i >= m ? i - m : i;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    string s;
    cin >> s;

    int n = s.size();
    queue<array<int, 3>> qu;
    string dist(n, 'z');
    int ans;

    vector<int> fr(130);
    for (int i = 0; i < n; i++) fr[s[i]]++;

    for (int c = 'a'; c <= 'z'; c++) {
        if (fr[c]) {
            bool ok = true;
            dist[0] = c;
            for (int i = 0; i < n; i++) {
                if (s[i] == c && ok) qu.push({0, i, (int) qu.size() + 1}), ok = false;
                if (s[i] != c) ok = true;
            }
            break;
        }
    }

    vector<int> ids(n);
    vector<bool> merged(n + 1);

    s += s;
    while (qu.size()) {
        debug(qu);
        auto [d, i, id] = qu.front();
        qu.pop();
        if (s[i + d] > dist[d]) continue;
        if (d == n - 1) continue;
        // I think we should merge two ways
        if (ids[mod(i + d, n)])
            merged[ids[mod(i + d, n)]] = true;
        ids[mod(i + d, n)] = id;
        if (merged[id] && qu.size()) continue;
        dist[d + 1] = min(dist[d + 1], s[i + d + 1]);
        qu.push({d + 1, i, id});
    }

    cout << dist;

    return 0;
}
