// ﷽
// https://www.spoj.com/problems/HEADSHOT/

#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
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
#define vi vector<int>
#define vvi vector<vector<int>>
#define pii pair<int, int>
#define vii vector<pii>
#define sz(v) (int) (v).size()
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define minit(v, x...) v = min({v, x})
#define maxit(v, x...) v = max({v, x})

template<class T>
using rpq = priority_queue<T, vector<T>, greater<T>>;

int32_t main(int32_t argc, char **argv) {
    cin.tie(nullptr)->sync_with_stdio(false);

    string s;
    cin >> s;
    int n = s.size();

    int zz = 0, z = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') z++;
        if (s[i] == '0' && s[(i + 1) % n] == 0) zz++;
    }

    if (zz * n == z * z) {
        cout << "EQUAL\n";
    } else if (zz * n > z * z) {
        cout << "SHOOT" << endl;
    } else {
        cout << "ROTATE\n";
    }

    return 0;
}
