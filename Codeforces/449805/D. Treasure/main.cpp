// ﷽
#include <bits/stdc++.h>

using namespace std;

#ifdef SAWALHY
#include "debug.hpp"
#else
#define debug(...) 0
#define debug_itr(...) 0
#define debug_bits(...) 0
#endif

#define ll long long
#define int long long
#define all(v) v.begin(), v.end()

vector<int> kemo(string s) {
    vector<int> ans;
    int l = 0, r = 0, h = 0, lastl = 0, lastr = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '(') l++;
        else if (s[i] == ')') r++;
        else {
            if (l > r) {
                h++, r++,
                lastl = l, lastr = r;
            } else {
                return {-1};
            }
        }
    }
    if (l < r) {
        return {-1};
    }

    int x = l - r, start = lastr + lastl;
    lastr += x;
    for (int i = start - 1; i < s.size(); ++i) {
        if (s[i] == '(') lastl++;
        else if (s[i] == ')') lastr++;
        if (lastr > lastl) {
            return {-1};
        }
    }

    for (int i = 0; i < h - 1; ++i) {
        ans.push_back(1);
    }
    ans.push_back(x + 1);
    return ans;
}

vector<int> sawalhy(string s) {
    int val = 0, cnt = 0;
    int j, valj;

    for (int i = 0; i < (int) s.length(); i++) {
        if (s[i] == '(') {
            val++;
        } else {
            val--;
        }

        if (val < 0) {
            return {-1};
        }

        if (s[i] == '#') {
            j = i, valj = val;
            cnt++;
        }
    }

    if (valj - val < 0) { return {-1}; }

    for (int i = j + 1, x = valj - val; i < (int) s.length(); i++) {
        if (s[i] == '(') x++;
        else x--;
        if (x < 0) { return {-1}; }
    }

    vector<int> ans(cnt, 1);
    ans.back() = val + 1;
    return ans;
}

mt19937 rng = mt19937(random_device()());

void seed(int s) { rng = mt19937(s); }

int rand_int(int x, int y) {
    return uniform_int_distribution<int>(x, y)(rng);
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);


    for (int i = 0; i < 1000; i++) {
        debug(i);

        string s;
        int n = rand_int(1, 10);
        bool ok = false;

        for (int i = 0; i < n; i++) {
            int x = rand_int(0, 2);
            s += "()#"[x];
            if (s.back() == '#') ok = true;
        }

        if (!ok) continue;

        auto ans = sawalhy(s);
        auto asd = kemo(s);

        if (ans != asd) {
            debug(s);
            break;
        }
    }


    return 0;
}
