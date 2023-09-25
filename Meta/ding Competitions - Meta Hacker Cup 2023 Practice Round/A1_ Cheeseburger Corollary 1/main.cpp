// ﷽
// https://www.facebook.com/codingcompetitions/hacker-cup/2023/practice-round/problems/A1?source=codeforces
// Meta Coding Competitions -> Meta Hacker Cup 2023 Practice Round -> A1: Cheeseburger Corollary 1

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

void solve() {
    int s, d, k;
    cin >> s >> d >> k;
    int buns = (s + d) * 2;
    int patty = s + 2 * d;

    cout << (patty >= k && buns >= k + 1 ? "YES" : "NO") << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t)
        cout << "Case #" << t << ": ", solve();

    return 0;
}
