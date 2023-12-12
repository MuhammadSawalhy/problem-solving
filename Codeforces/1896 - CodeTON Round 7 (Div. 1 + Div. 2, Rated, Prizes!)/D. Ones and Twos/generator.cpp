#include "testlib.h"
#include <vector>
using namespace std;

int main(int argc, char **argv) {
    registerGen(argc, argv, 1);

    int n = rnd.next(10) + 1;
    int q = rnd.next(10) + 1;

    println(1);
    println(n, q);

    for (int i = 0; i < n; i++)
        cout << rnd.next(1, 2) << " \n"[i == n - 1];

    for (int i = 0; i < q; i++) {
        int t = rnd.next(1, 2);
        cout << t << " ";
        if (t == 1) {
            cout << rnd.next(1, 2 * n) << " \n";
        } else {
            cout << rnd.next(1, n) << " " << rnd.next(1, 2) << " \n";
        }
    }
}
