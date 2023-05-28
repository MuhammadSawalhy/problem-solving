#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

int t, n;

inline void readAndCheckAnswer() {
    for (int T = 1; T <= t; T++) {
        setTestCase(T);
    }
}

int main(int argc, char *argv[]) {
    registerTestlibCmd(argc, argv);
    t = inf.readInt(1, 1e4, "t");
    readAndCheckAnswer();
    quitf(_ok, "corrent answer(s)");
}
