#include <bits/stdc++.h>
using namespace std;

using namespace std;
#define ll long long
#define ull unsigned long long
//#define int long long
#define endl '\n'
#define Endl '\n'
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define allof(x) x, x + (sizeof(x) / sizeof(x[0]))
#define loop(n) for (int i = 0; i < (n); i++)
#define fast                 \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
#define YES cout << "YES\n"
#define NO cout << "NO\n"
double PI = 3.14159265359;
// bitwise functions ************************
#define pop_cnt(x) (__builtin_popcountll(x)) //num of ones int bits
#define LSB(x) (__builtin_ffsll(x) - 1)      // int lowbit(int x){return x&(-x);}

#define MSB(x) (64 - __builtin_clzll(x) - 1)

//******************************************
//const int dx[]{0, 1, 0, -1, -1, -1, 1, 1};
//const int dy[]{1, 0, -1, 0, -1, 1, -1, 1};

template<typename T_vector>
void output_vector(const T_vector &v, bool add_one = false, int start = -1, int end = -1) {
    if (start < 0) start = 0;
    if (end < 0) end = int(v.size());

    for (int i = start; i < end; i++)
        cout << v[i] + (add_one ? 1 : 0) << (i < end - 1 ? ' ' : '\n');
}

void file() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

#endif
}

#ifndef ONLINE_JUDGE

#else
#define debug(...)
#define debug_itr(...)
#define debug_bits(...)
#endif

constexpr int MOD = 1000000007; // 998244353


/**************** Solution start from here ***********************/

int main() {
    fast;

    int n, x;
    cin >> n >> x;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    sort(rall(a));

    vector<vector<int>> ans;
    set<pair<int, int>> s;

    for (int i = 0; i < n; i++) {
        // search for largest >= a[i] + x

        auto it = s.lower_bound({a[i] + x, -1});
        if (it == s.end()) {
            ans.push_back({a[i]});
            s.insert({a[i], ans.size() - 1});
            continue;
        }

        ans[it->second].push_back(a[i]);
        s.erase(it);
        s.insert({a[i], it->second});
    }

    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i].size() << " ";
        output_vector(ans[i]);
    }
}
