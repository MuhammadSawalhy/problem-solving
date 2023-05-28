#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
    registerTestlibCmd(argc, argv);

    int t = inf.readInt(1, 1e5, "t");

    for (int T = 1; T <= t; T++) {
        setTestCase(T);
        int n = inf.readInt(1, 1e5, "n");
        auto a = inf.readInts(n, 1, n, "a");
    }

    quitf(_ok, "corrent answer(s)");
}
