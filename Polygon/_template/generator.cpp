#include "testlib.h"
#include <vector>
using namespace std;

int main(int argc, char **argv) {
    registerGen(argc, argv, 1);

    int n = opt<int>("n", rnd.next(2e5) + 1);
    println(n);
}
