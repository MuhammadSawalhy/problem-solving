#include "testlib.h"
#include <vector>
using namespace std;

int main(int argc, char **argv) {
    registerGen(argc, argv, 1);

    int n = rnd.next(1, 10);
    int x = rnd.next(0, n);

    println(1);
    println(n, x);

    for (int i = 0; i < n; i++)
        cout << rnd.next(1, 2 * n) << " \n"[i == n - 1];

    for (int i = 0; i < n; i++)
        cout << rnd.next(1, 2 * n) << " \n"[i == n - 1];
}
