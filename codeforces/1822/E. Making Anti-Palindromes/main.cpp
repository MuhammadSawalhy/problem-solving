// ﷽
#include <bits/stdc++.h>

using namespace std;

#ifdef SAWALHY
#include "debug.hpp"
#else
#define debug(...)      0
#define debug_itr(...)  0
#define debug_bits(...) 0
#endif

#define ll     long long
#define int    long long
#define all(v) v.begin(), v.end()

int solve(int n, string s) {
    map<char, int> fr;
    int mxfr = 0;
    for (int i = 0; i < n; i++) {
        fr[s[i]]++;
        mxfr = max(mxfr, fr[s[i]]);
    }

    if (n & 1 || mxfr > n / 2) {
        return -1;
    }

    int cnt = 0;

    vector<int> tochange(26);
    int sum = 0;
    for (int i = 0, j = n - 1; i < j; i++, j--) {
        if (s[i] == s[j])
            tochange[s[i] - 'a']++, sum++;
    }

    sort(all(tochange));
    if (tochange[25] > sum / 2) {
        return tochange[25];
    } else {
        return ++sum / 2;
    }
}


int zyad(int n, string str) {
    if (n % 2) {
        return -1;
    }

    //if char more than half!;

    ll f[26]{};
    for (int i = 0; i < n; i++) {
        if (++f[str[i] - 'a'] > n / 2) {
            return -1;
        }
    }


    ll left = 0, right = n - 1;

    ll fa[26]{};
    while (left < right) {
        if (str[left] == str[right]) {
            fa[str[left] - 'a']++;
        }
        left++;
        right--;
    }
    return max((ll) (accumulate(fa, fa + 26, 0) + 1) / 2, *max_element(fa, fa + 26));
}

int gen(int a, int b) {
    assert(b >= a);
    return rand() % (b - a + 1) + a;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    // for (int i = 0; i < 500; i++) {
    //     cerr << i << endl;
    //     srand(i);
    //     int n = gen(1, 10);
    //     string s;
    //     for (int i = 0; i < n; i++)
    //         s += 'a' + gen(0, 25);
    //     int a = solve(n, s);
    //     int b = zyad(n, s);
    //     if (a != b) {
    //         debug(n, s);
    //         debug(a, b);
    //         return 0;
    //     }
    // }
    // return 0;

    int t;
    cin >> t;
    while (t--) {
        int n;
        string s;
        cin >> n >> s;
        cout << solve(n, s) << endl;
    }

    return 0;
}
