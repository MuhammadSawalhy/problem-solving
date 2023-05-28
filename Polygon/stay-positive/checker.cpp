#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

int t, n, sumofn;

inline void readAndCheckAnswer() {
    for (int T = 1; T <= t; T++) {
        setTestCase(T);
        int n = inf.readInt(1, 3e5, "n");
        int pa = ouf.readInt(-1, n, "participant answer");
        int ja = ans.readInt(-1, n, "jury answer");
        vector<int> a = inf.readInts(n, -1e9, 1e9, "a");

        if (pa == 0)
            ouf.quitf(_wa, "invalid output 0");
        if (ja == 0)
            ans.quitf(_fail, "invalid output 0");

        if (pa != -1) {
            long long sum = 0;
            for (int i = pa - 1; i < pa - 1 + n; i++) {
                sum += a[i % n];
                if (sum < 0)
                    ouf.quitf(_wa, "the sum became negative");
            }
        }

        if (ja != -1) {
            long long sum = 0;
            for (int i = ja - 1; i < ja - 1 + n; i++) {
                sum += a[i % n];
                if (sum < 0)
                    ans.quitf(_fail, "the sum became negative");
            }
        }

        if (ja == pa) continue;
        if (pa == -1)
            ouf.quitf(_wa, "there exists a valid answer but found -1");
        if (ja == -1)
            ans.quitf(_fail, "there exists an answer and jury is wrong");
    }
}

int main(int argc, char *argv[]) {
    registerTestlibCmd(argc, argv);
    t = inf.readInt(1, 1e4, "t");
    readAndCheckAnswer();
    quitf(_ok, "corrent answer(s)");
}
