// ﷽
#include <algorithm>
#include <array>
#include <assert.h>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <utility>
#include <vector>

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

const int N = 1e5 + 5;
vector<int> adj[N];
int n, m;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> n >> m;
    vector<int> outdeg(n);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        adj[b].push_back(a);
        outdeg[a]++;
    }

    priority_queue<int> pq;

    for (int i = 0; i < n; i++) {
        if (outdeg[i] == 0) {
            pq.push(i);
        }
    }

    vector<int> labels(n);

    for (int label = n - 1; label >= 0; label--) {
        int node = pq.top();
        pq.pop();

        labels[node] = label;

        for (auto i: adj[node]) {
            outdeg[i]--;
            if (outdeg[i] == 0) {
                pq.push(i);
            }
        }
    }

    vector<int> ans(n);

    for (int i = 0; i < n; i++) ans[labels[i]] = i;

    for (auto i: labels) {
        cout << i + 1 << " ";
    }

    return 0;
}

