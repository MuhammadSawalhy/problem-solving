// ﷽
#include <bits/stdc++.h>

// #pragma GCC optimize("O3")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC target("avx,avx2,fma")

using namespace std;

#ifdef SAWALHY
#include "debug.hpp"
#else
#define debug(...) 0
#define debug_itr(...) 0
#define debug_bits(...) 0
#endif

#define int long long
#define ll long long
#define all(v) v.begin(), v.end()

const int N = 5e5 + 5, K = 26;
int dp[N][K];
int parent[N][K];
int n, k;

string out;
void print(int i, int j, int r) {
    if (i == -1) return;
    assert(r == -1 || j != r);
    print(i - 1, parent[i][j], j);
    out += char('A' + j);
}

vector<int> two_mins(int i) {
    vector<array<int, 2>> mins;
    for (int j = 0; j < k; j++) {
        mins.push_back(array<int, 2>{dp[i][j], j});
    }
    sort(all(mins));
    return vector<int>{mins[0][1], mins[1][1]};
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    string colors;
    cin >> n >> k;
    cin >> colors;

    if (n == 1) {
        cout << "0\n";
        cout << colors;
        return 0;
    }

    memset(dp, 0x3f, sizeof dp);

    for (int i = 0; i < k; i++)
        dp[0][i] = colors[0] - 'A' != i;

    int ans = 1e9, cur = 0;
    for (int i = 1; i < n; i++) {
        int c = colors[i] - 'A';
        auto pp = two_mins(i - 1);
        for (int j = 0; j < k; j++) {
            for (auto r: pp) {
                if (r == j) continue;
                int val = dp[i - 1][r] + (c != j);
                if (val < dp[i][j] && (i < n - 1 || val < ans)) {
                    dp[i][j] = val;
                    parent[i][j] = r;
                    if (i == n - 1) {
                        ans = val;
                        cur = j;
                    }
                }
            }
        }
    }

    cout << ans << '\n';
    print(n - 1, cur, -1);

    cout << out;

    return 0;
}
