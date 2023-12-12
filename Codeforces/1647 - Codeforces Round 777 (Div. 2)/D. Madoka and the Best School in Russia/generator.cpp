#include "testlib.h"
#include <vector>
using namespace std;

bool is_beautiful(int val, int d) {
    int cnt = 0;
    while (val % d == 0) cnt++, val /= d;
    return cnt == 1;
}

int main(int argc, char **argv) {
    registerGen(argc, argv, 1);

    int t = 3;
    println(t);

    while (t--) {
        int d = rnd.next(2, 10000);
        int x;
        do {
            x = rnd.next(1, 100000) * d;
        } while (!is_beautiful(x, d));
        println(x, d);
    }
}
