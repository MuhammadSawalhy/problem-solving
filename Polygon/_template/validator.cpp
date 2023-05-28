#include "testlib.h"

using namespace std;

int main(int argc, char *argv[]) {
    registerValidation(argc, argv);

    int testCaseCount = inf.readInt(1, 1e4, "t");
    inf.readEoln();

    int sumofn = 0;

    for (int testCase = 1; testCase <= testCaseCount; testCase++) {
        setTestCase(testCase);
        int n = inf.readInt(1, 3e5, "n");
        inf.readEoln();
        inf.readInts(n, -1e9, 1e9, "a");
        n += sumofn;
        inf.readEoln();
    }

    inf.readEof();
    inf.quitif(sumofn > 3e5, _fail, "sum of n over all test cases should be <= 3e5");
}
