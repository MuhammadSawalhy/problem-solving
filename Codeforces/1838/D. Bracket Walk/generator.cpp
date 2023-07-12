#include "testlib.h"
#include <vector>
using namespace std;

int main(int argc, char **argv) {
    registerGen(argc, argv, 1);

    int n = rnd.next(1, 10);
    int q = 3;

    println(n, q);

    for (int i = n; i; i--)
        cout << (rnd.next(2) ? '(' : ')');
    cout << endl;

    while (q--)
        cout << rnd.next(1, n) << endl;
}

