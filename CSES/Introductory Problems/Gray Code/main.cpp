// Date: 02-01-2023
#include <bits/stdc++.h>

#define debug(...)
#ifdef SAWALHY
#include "debug.hpp"
#endif

#define int long long
#define ll long long
#define all(v) v.begin(), v.end()

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n;
    cin >> n;

    vector<string> ans {"0", "1"};
    n--;

    while (n--) {
        vector<string> newans = ans;
        for (int i = 0; i < (int)ans.size(); i++) {
            ans[i] = "0" + ans[i];
            newans[i] = "1" + newans[i];
        }
        for (int i = (int)newans.size() - 1; ~i; i--) {
            ans.push_back(newans[i]);
        }
    }

    for (auto s : ans)
        cout << s << endl;

    return 0;
}
