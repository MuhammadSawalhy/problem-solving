#include "testlib.h"
#include <vector>
using namespace std;

int main(int argc, char **argv) {
    registerGen(argc, argv, 1);

    int t = 1;
    println(t);
    int a = rnd.next(1, 100);
    int b = rnd.next(1, 100);
    int c = rnd.next(1, 100);
    println(a, b, c);
}
