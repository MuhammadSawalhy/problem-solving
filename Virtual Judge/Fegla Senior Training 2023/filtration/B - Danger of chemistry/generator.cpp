#include "testlib.h"
#include <vector>
using namespace std;

int main(int argc, char **argv) {
    registerGen(argc, argv, 1);

    int t = 1;
    println(t);

    while (t--) {
        int n = rnd.next(8) + 1;
        println(n);
        while (n--)
            cout << rnd.next(1, (int)1e9) << ' ';
        cout << endl;
    }
}
