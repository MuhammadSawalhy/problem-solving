#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

struct Mat {
    vector<int> sum;
    vector<vector<int>> a;
    int n, m;
    Mat(int n, int m) : n(n), m(m) { a.resize(n, vector<int>(m)), sum.resize(m); }
    Mat operator*(Mat &b) {
        Mat c(n, b.m);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < b.m; j++) {
                for (int k = 0; k < m; k++)
                    c.a[i][j] = (c.a[i][j] + 1LL * a[i][k] * b.a[k][j]) % mod;
                c.sum[j] = (c.a[i][j] + c.sum[j]) % mod;
            }
        return c;
    }
};

int32_t main(int32_t argc, char **argv) {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n;
    cin >> n;

    Mat A(27, 1);
    A.a[26][0] = 1;

    for (int i = 0; i < n; i++) {
        string s;
        int k;
        cin >> s >> k;
        Mat All(27, 27);
        for (int i = 0; i < 27; i++) All.a[i][i] = 1;
        for (int i = 0; i < s.size(); i++) {
            Mat M(27, 27);
            for (int j = 0; j < 27; j++) {
                M.a[s[i] - 'a'][j] = 1;
            }

            for (int j = 0; j < 26; j++) {
                if (j != s[i] - 'a') {
                    M.a[j][j] = 1;
                }
            }

            All = M * All;
        }
        while (k--) A = All * A;
    }

    int ans = 0;
    for (int i = 0; i < 26; i++)
        ans = (ans + A.a[i][0]) % mod;
    cout << ans << endl;

    return 0;
}

