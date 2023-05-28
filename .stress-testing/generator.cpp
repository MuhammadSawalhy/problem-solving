#include "testlib.h"
#include <vector>
using namespace std;

int main(int argc, char **argv) {
    registerGen(argc, argv, 1);

    int n = rnd.next(10) + 1;
    int q = rnd.next(10) + 1;

    println(n, q);

    while (n--)
        cout << rnd.next(1, 100) << ' ';
    cout << endl;

    while (q--)
        cout << rnd.next(1, 100) << ' ';
    cout << endl;
}
