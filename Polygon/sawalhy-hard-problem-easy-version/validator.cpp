#include "testlib.h"

using namespace std;

int main(int argc, char *argv[]) {
    registerValidation(argc, argv);

    int ymin = inf.readInt(-1e6, 1e6, "ymin");
    inf.readSpace();
    int ymax = inf.readInt(-1e6, 1e6, "ymax");
    inf.readSpace();
    int s = inf.readInt(-1e6, 1e6, "s");
    inf.readSpace();
    int e = inf.readInt(-1e6, 1e6, "e");
    inf.readSpace();
    int w = inf.readInt(0, 2e8, "w");
    inf.readEoln();
    inf.readEof();
    inf.quitif(abs(ymax - ymin) * w > 2e8, _fail, "");
}
