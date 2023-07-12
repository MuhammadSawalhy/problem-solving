// Date: 11-12-2022
#include <bits/stdc++.h>

using namespace std;

#define debug(...)
#define ll long long
#define all(v) v.begin(), v.end()
#ifdef SAWALHY
#include "debug.hpp"
#endif

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n;
    cin >> n;

    vector<vector<int>> cons(n + 1, vector<int>(n + 1));
    for (int i = 1; i <= n; i++) {
        cin >> cons[i][i];
        for (int j = i + 1; j <= n; j++) {
            cin >> cons[i][j];
        }
    }

    int ans;
    cin >> ans;

    int correct = 0;

    auto test = [&](int x) {
        bool ok = true;
        for (int i = 1; i <= n; i++) {
            set<int> s;
            for (int j = i; j <= n; j++) {
                s.insert(x >> (n - j) & 1);
                if (cons[i][j] == 1 && s.size() == 2) {
                    return false;
                }
                if (cons[i][j] == 2 && s.size() != 2) {
                    return false;
                }
            }
        }
        return ok;
    };

    for (int i = 0; i < 1 << n; i++) {
        correct += test(i);
    }

    if (correct != ans) {
        cerr << "Wrong answer: " << ans << endl;
        cerr << "Correct     : " << correct << endl;
        exit(1);
    }

    return 0;
}
