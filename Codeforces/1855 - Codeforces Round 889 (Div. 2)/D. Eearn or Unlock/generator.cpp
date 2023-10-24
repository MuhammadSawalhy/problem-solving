#include "testlib.h"
#include <vector>
using namespace std;

int main(int argc, char **argv) {
    registerGen(argc, argv, 1);

    println(1);

    int n = rnd.next(1, 10);
    println(n);
    for (int i = 0; i < n; i++)
        cout << rnd.next(0, n) << " \n"[i == n - 1];

}
