#include <bits/stdc++.h>
using namespace std;

template<int N = 3>
struct bigint {
    // stores up to base^N
    using ull = unsigned long long;
    const static ull base = 1e18;
    ull nums[N]{};

    bigint() = default;
    bigint(ull x) { nums[0] = x; }

    bigint &operator+=(const bigint &rhs) {
        for (int i = 0; i < N; i++) {
            nums[i] += rhs.nums[i];
            if (nums[i] >= base) nums[i + 1]++, nums[i] -= base;
        }
        return *this;
    }

    string to_str() {
        string res;
        int cnt = N - 1;
        while (~cnt && !nums[cnt]) cnt--;

        if (cnt == -1) return "0";
        res += to_string(nums[cnt]);
        for (int i = cnt - 1; ~i; i--) {
            string a = to_string(nums[i]);
            a.insert(0, 18 - a.size(), '0');
            res += a;
        }

        return res;
    }
};

const int N = 10001;
bigint<6> dp[N];

signed main() {
    cin.tie(0)->sync_with_stdio(0);

    dp[0] = 1;

    for (int i = 1; i < N; i++) {
        for (int j = i; j < N; j++) dp[j] += dp[j - i];
    }

    for (int i = 0; i < N; i++) cout << dp[i].to_str() << ' ';

    return 0;
}
