// ﷽
// 10 جُمادى الآخرة 1444
// Jan 02, 2023
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

    string s;
    cin >> s;

    vector<string> ans;

    sort(all(s));

    do {
        ans.push_back(s);
    } while (next_permutation(all(s)));

    cout << ans.size() << endl;
    for (auto s: ans)
        cout << s << endl;

    return 0;
}
