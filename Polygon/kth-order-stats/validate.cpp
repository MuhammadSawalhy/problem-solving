#include "testlib.h"

using namespace std;

int main(int argc, char *argv[]) {
    registerValidation(argc, argv);

    int n = inf.readInt(1, 2e5, "n");
    inf.readEoln();

    set<char> valid{'-', '+', '?'};
    set<int> s;
    for (int i = 1; i <= n; i++) {
        char c = inf.readChar();
        inf.quitif(valid.count(c) == 0, _fail, "invalid instruction %c", c);
        if (c == '?') {
            inf.readEoln();
        } else if (c == '-') {
            inf.readSpace();
            int x = inf.readInt(1, 1e9, "x");
            inf.quitif(s.count(x) == 0, _fail, "the value %d doesn't exist during removal", x);
            inf.readEoln();
            s.erase(x);
        } else {
            inf.readSpace();
            int x = inf.readInt(1, 1e9, "x");
            inf.quitif(s.count(x) != 0, _fail, "the value %d already exist during adding", x);
            inf.readEoln();
            s.insert(x);
        }
    }

    inf.readEof();
}
