// ﷽
// https://cses.fi/problemset/task/1740

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
#define rall(v) v.rbegin(), v.rend()
#define minit(v, x) v = min(v, x)
#define maxit(v, x) v = max(v, x)

template<class T, int... Ns>
struct BIT {
    T val = 0;
    void update(T v) { val += v; }
    T query() { return val; }
};

template<class T, int N, int... Ns>
struct BIT<T, N, Ns...> {
    BIT<T, Ns...> bit[N + 1];
    template<typename... Args>
    void update(int pos, Args... args) {
        for (pos++; pos <= N; pos += (pos & -pos)) bit[pos].update(args...);
    }
    template<typename... Args>
    T sum(int r, Args... args) {
        T res = 0;
        for (r++; r; r -= (r & -r)) res += bit[r].query(args...);
        return res;
    }
    template<typename... Args>
    T query(int l, int r, Args... args) {
        return sum(r, args...) - sum(l - 1, args...);
    }
}; // BIT<int,10,10> gives a 2D BIT

const int N = 2000001;
BIT<int, N> bit;
vector<pair<int, int>> todel, toadd;
vector<array<int, 3>> lines;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n;
    cin >> n;

    int ans = 0;
    for (int i = 0; i < n; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x1 += 1e6, x2 += 1e6, y1 += 1e6, y2 += 1e6;
        if (y1 == y2) {
            // horizontal
            toadd.push_back({x1, y1});
            todel.push_back({x2, y1});
        } else {
            // vertical
            assert(x1 == x2);
            if (y1 > y2) swap(y1, y2);
            lines.push_back({x1, y1, y2});
        }
    }

    sort(rall(lines));
    sort(rall(todel));
    sort(rall(toadd));

    for (int x = 0; x <= 2e6; x++) {
        while (!todel.empty() && todel.back().first == x) {
            bit.update(todel.back().second, -1);
            todel.pop_back();
        }
        while (!lines.empty() && lines.back()[0] == x) {
            int y1 = lines.back()[1], y2 = lines.back()[2];
            ans += bit.query(y1, y2);
            lines.pop_back();
        }
        while (!toadd.empty() && toadd.back().first == x) {
            bit.update(toadd.back().second, 1);
            toadd.pop_back();
        }
    }

    cout << ans << endl;
    return 0;
}
