// ﷽
#include <bits/stdc++.h>

using namespace std;

#ifdef SAWALHY
#include "debug.hpp"
#else
#define debug(...)
#define debug_itr(...)
#define debug_bits(...)
#endif

#define int long long
#define ll long long
#define all(v) v.begin(), v.end()

int n;

vector<int> min_left(vector<int> &a) {
    vector<pair<int, int>> stack;
    stack.push_back({-1e9, -1});
    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
        while (stack.size() && stack.back().first >= a[i]) {
            stack.pop_back();
        }
        ans[i] = stack.back().second;
        stack.push_back({ a[i], i });
    }
    return ans;
}

vector<int> min_right(vector<int> &a) {
    reverse(all(a));
    auto ans = min_left(a);
    reverse(all(a));
    for (int i = 0; i < n; i++) {
        ans[i] = n - 1 - ans[i];
    }
    reverse(all(ans));
    return ans;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<int> left = min_left(a), right = min_right(a);

    vector<pair<int, int>> ranges;

    for (int i = 0; i < n; i++) {
        int j = left[i], k = right[i];
        j++;
        ranges.emplace_back(a[i], k - j);
    }

    sort(all(ranges), greater<pair<int, int>>());
    debug(ranges);

    for (int i = 1, j = 0; i <= n; i++) {
        while (ranges[j].second < i) {
            j++;
        }
        cout << ranges[j].first << " ";
    }

    return 0;
}
