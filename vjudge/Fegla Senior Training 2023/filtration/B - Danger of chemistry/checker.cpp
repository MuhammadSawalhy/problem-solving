#include "testlib.h"
#include <bits/stdc++.h>

#define all(v) (v).begin(), (v).end()
using namespace std;

vector<int> getcorrect(vector<int> a) {
    sort(all(a));

    long long mn = 1e18;
    vector<int> ans;

    do {
        long long sum = 0;
        for (int i = 0; i + 1 < (int) a.size(); i++) {
            sum += gcd(a[i], a[i + 1]);
        }
        if (sum < mn || sum == mn && a < ans) {
            mn = sum;
            ans = a;
        }
    } while (next_permutation(all(a)));
    return ans;
}

int main(int argc, char *argv[]) {
    registerTestlibCmd(argc, argv);

    int t = inf.readInt(1, 1e5, "t");

    for (int T = 1; T <= t; T++) {
        setTestCase(T);
        int n = inf.readInt(1, 1e5, "n");
        auto a = inf.readInts(n, 1, 1e5, "a");

        auto cor = getcorrect(a);
        int m = ouf.readInt(0, n, "m");

        while (m-- > 0) {
            int l = ouf.readInt(1, n, "l");
            int r = ouf.readInt(1, n, "r");
            l--, r--;
            swap(a[l], a[r]);
        }

        if (cor != a) {
            ouf.quitf(_wa, "wrong answer");
        }
    }

    quitf(_ok, "corrent answer(s)");
}
