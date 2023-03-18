// ﷽
#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <utility>
#include <vector>
#include <assert.h>

using namespace std;

#ifdef SAWALHY
#include "debug.hpp"
#else
#define debug(...)
#define debug_itr(...)
#define debug_bits(...)
#endif

#define ll long long
#define all(v) v.begin(), v.end()

template<typename T>
struct Node {
    T value;

    Node(T value = 1e18) : value(value) {}

    void operator+=(const Node &other) {
        value = min(value, other.value);
    }

    Node operator+(const Node &other) {
        return min(value, other.value);
    }
};

// source: https://codeforces.com/blog/entry/18051
template<typename T>
struct segtree {
    int n;
    vector<Node<T>> tree;

    segtree(int n) : n(n) {
        tree.resize(n * 2);
    }

    void build() {
        for (int i = n - 1; i > 0; --i)
            tree[i] = tree[i << 1] + tree[i << 1 | 1];
    }

    void update(int i, T val) {
        for (tree[i += n] = val; i > 1; i >>= 1)
            tree[i >> 1] = tree[i] + tree[i ^ 1];
    }

    void relative_update(int i, T val) {
        for (tree[i += n] += val; i > 1; i >>= 1)
            tree[i >> 1] = tree[i] + tree[i ^ 1];
    }

    T query(int l, int r) {
        Node<T> res;
        for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {
            if (l & 1) res += tree[l++];
            if (r & 1) res += tree[--r];
        }
        return res.value;
    }
};

const int N = 2e5 + 1;
int n, k, m;
int key[N], cost[N], keymin[N];
segtree<ll> sg(N + 1);
ll inf = 1e18;

bool valid(int x) {
    sg.update(0, 0);
    for (int i = 0; i < n; i++) {
        if (x < keymin[i]) {
            sg.update(i + 1, inf);
        } else {
            ll mn = sg.query(max(0, i + 1 - k), i);
            sg.update(i + 1, mn + cost[i]);
        }
    }

    return sg.query(max(0, n + 1 - k), n) <= m;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    vector<int> primes;
    vector<bool> isprime(31800, true);
    for (int i = 2; i < 31800; i++) {
        if (!isprime[i]) continue;
        primes.push_back(i);
        for (int j = i * i; j < 31800; j += i) {
            isprime[j] = false;
        }
    }

    scanf("%d%d%d", &n, &k, &m);

    for (int i = 0; i < n; i++) {
        scanf("%d", &key[i]);
        keymin[i] = key[i];
        for (auto p: primes) {
            if (key[i] % p == 0) {
                keymin[i] = p;
                break;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        scanf("%d", &cost[i]);
    }

    int s = -1, e = 1e9 + 5;

    int ans = -1;
    while (e - s > 1) {
        int mid = (s + e) / 2;
        if (valid(mid)) {
            e = ans = mid;
        } else {
            s = mid;
        }
    }

    printf("%d\n", ans);

    return 0;
}
