#include "testlib.h"
#include <vector>
using namespace std;

int main(int argc, char **argv) {
    registerGen(argc, argv, 1);

    int k = rnd.next(1, 4);
    vector<int> seeds(1 << k);

    vector<int> perm = rnd.perm(1 << k);
    for (auto &i: perm) i++;

    for (int i = 0; i < 1 << k; i++) {
        int r = rnd.wnext(-10, 10, -1);
        if (r < 0) seeds[i] = -1;
        else seeds[i] = perm[i];
    }

    println(k);
    println(seeds);
}
