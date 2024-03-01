#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <functional>

typedef long long ll;
typedef unsigned long ul;
typedef unsigned long long ull;
typedef long double ld;
typedef unsigned int uint;
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
#define allof(x) x, x + (sizeof(x) / sizeof(x[0]))
#define endl "\n"
#define int ll
#define pop_cnt(x) (__builtin_popcountll(x))
#define LSB(x) (__builtin_ffsll(x) - 1)
#define MSB(x) (64 - __builtin_clzll(x) - 1)

using namespace std;
using namespace __gnu_pbds;

template <typename dt>
using oset = tree<dt, null_type, less<dt>, rb_tree_tag,
                  tree_order_statistics_node_update>;
// find_by_order(k), order_of_key(k)

#ifdef DEBUG
#include "debug\debug.hpp"
#else
#define debug(...)
#define debug_itr(...)
#define debug_bits(...)
#define debug_pq(...)
#define debug_q(...)
#endif

// using L = __int128;

void file(string s = "me") {
#ifdef DEBUG
    freopen("me.in", "r", stdin);
    freopen("me.out", "w", stdout);
#else
    if (s != "me") {
        freopen((s + ".in").c_str(), "r", stdin);
        freopen((s + ".out").c_str(), "w", stdout);
    }
#endif
}

// loop to 4 get only NSWE
const int dx[]{0, 1, 0, -1, -1, -1, 1, 1};
const int dy[]{1, 0, -1, 0, -1, 1, -1, 1};

const ll INF = 1e18 + 5;


void solve() {
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n, 0), b(m, 0);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }
    sort(all(b));
    sort(all(a));
    ll la = 0, lb = 0, ra = n - 1, rb = m - 1, ans = 0;
    while(la <= ra){
        ll l1 = abs(a[la] - b[lb]);
        ll l2 = abs(a[la] - b[rb]);
        ll r1 = abs(a[ra] - b[lb]);
        ll r2 = abs(a[ra] - b[rb]);
        // debug(a[la], a[ra], b[lb], b[rb]);
        // debug(l1, l2, r1, r2);
        // debug(la, ra, lb, rb);
        // debug(max({l1, l2, r1, r2}) + ans);
        if(l1 >= l2 && l1 >= r1 && l1 >= r2){
            la++; lb++;
        }
        else if(l2 >= l1 && l2 >= r1 && l2 >= r2){
            la++; rb--;
        }
        else if(r1 >= l1 && r1 >= l2 && r1 >= r2){
            ra--; lb++;
        }
        else{
            ra--; rb--;
        }
        ans += max({l1, l2, r1, r2});
    }
    cout << ans << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    file();
    int T = 1;
    cin >> T;
    for (int TT = 1; TT <= T; TT++) {
        solve();
    }
    cout.flush();
    return 0;
}
