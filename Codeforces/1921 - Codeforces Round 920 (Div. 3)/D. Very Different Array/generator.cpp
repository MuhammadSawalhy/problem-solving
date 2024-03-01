#include "testlib.h"
using namespace std;

int main(int argc, char **argv) {
    registerGen(argc, argv, 1);

    int n = rnd.next(1, 10);
    int m = rnd.next(n, 2 * n);

    println(1);
    println(n, m);

    for (int i = 0; i < n; i++)
        cout << rnd.next(1, 10) << " \n"[i == n - 1];
    for (int i = 0; i < m; i++)
        cout << rnd.next(1, 10) << " \n"[i == m - 1];
}
