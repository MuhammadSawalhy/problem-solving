#include "testlib.h"
#include <vector>
using namespace std;

int main(int argc, char **argv) {
    registerGen(argc, argv, 1);

    int size = opt<int>("size", rnd.next(0, (int) 2e8));
    bool valid = opt<bool>("valid", false);

    const int MAX = 1e6;
    int w = rnd.next(0, size / 2);
    int h = w == 0 ? size : size / w;
    if (valid) h = min(h, w);

    int ymin = opt<int>("ymin", rnd.next(-MAX, MAX));
    int ymax = rnd.next(max(-MAX, valid ? ymin : ymin - h), min(MAX, ymin + h));

    int s, e;
    if (valid) {
        s = rnd.next(min(ymin, ymax), max(ymin, ymax));
        e = rnd.next(min(ymin, ymax), max(ymin, ymax));
        if (abs(s - e) % 2 != w % 2)
            e++;
    } else {
        s = rnd.next(max(-MAX, min(ymin, ymax) - h), min(MAX, max(ymin, ymax) + h));
        e = rnd.next(max(-MAX, min(ymin, ymax) - h), min(MAX, max(ymin, ymax) + h));
    }

    println(ymin, ymax, s, e, w);
}
