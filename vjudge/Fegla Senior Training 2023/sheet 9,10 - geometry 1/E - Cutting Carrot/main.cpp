// ﷽
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
#define double     long double
#define all(v) v.begin(), v.end()

int n , h;
double area;

double get_base(double H) {
    return H / h;
}

void dfs(int cnt, double prev) {
    if (cnt == 0) return;
    double H;

    double s = prev, e = h;
    int iters = 100;
    while (iters--) {
        double mid = (s + e) / 2;
        double base = get_base(h - mid);
        debug(h-mid, base);
        if (0.5 * base * (h - mid) < cnt * area) {
            H = e = mid;
        } else {
            s = mid;
        }
    }

    dfs(cnt - 1, H);
    cout << h - H << ' ';
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> n >> h;

    area = 0.5 * h / n;
    debug(area);
    
    cout << fixed << setprecision(12);
    dfs(n - 1, 0);

    return 0;
}
