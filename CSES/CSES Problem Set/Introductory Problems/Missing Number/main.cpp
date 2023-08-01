// Date: 01-01-2023
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

    int n; cin >> n;
    set<int> nums;
    int a;
    for (int i = 1; i <= n - 1; i++)
        cin >> a, nums.insert(a);
        
    for (int i = 1; i <= n; i++)
        if (!nums.count(i)) cout << i << endl;

    return 0;
}
