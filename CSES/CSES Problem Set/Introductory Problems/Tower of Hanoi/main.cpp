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

vector<pair<int, int>> ans;

void move(int cnt, int a, int b) {
    if (cnt == 1) {
        ans.push_back({a, b});
        return;
    }

    set<int> s = {1, 2, 3};
    s.erase(a), s.erase(b);
    int c = *s.begin();
    move(cnt - 1, a, c);
    ans.push_back({a, b});
    move(cnt - 1, c, b);
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n;
    cin >> n;
    move(n, 1, 3);

    cout << ans.size() << endl;
    for (auto [a, b]: ans)
        cout << a << " " << b << endl;

    return 0;
}
