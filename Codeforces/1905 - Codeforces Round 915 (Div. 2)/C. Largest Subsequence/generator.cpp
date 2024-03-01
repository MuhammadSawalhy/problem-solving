#include "testlib.h"
using namespace std;

int main(int argc, char **argv) {
    registerGen(argc, argv, 1);

    println(1);
    int n = rnd.next(10) + 1;
    println(n);
    string s;
    for (int i = 0; i < n; i++) {
        s += 'a' + (int) rnd.next(26);
    }
    println(s);
}
