// ﷽
// 12 جُمادى الآخرة 1444
// Jan 04, 2023
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

    int n, k;
    cin >> n;

    set<int> s;

    for (int i = 0; i < n; i++) {
        s.insert(i + 1);
    }

    auto it = s.begin();
    while (true) {
        if (s.size() == 1) {
            cout << *it << endl;
            break;
        }

        set<int>::iterator toremove, next;
        if (++it == s.end()) it = s.begin();
        toremove = it;
        if (++it == s.end()) it = s.begin();
        cout << *toremove << " ";
        s.erase(toremove);
    }

    return 0;
}
