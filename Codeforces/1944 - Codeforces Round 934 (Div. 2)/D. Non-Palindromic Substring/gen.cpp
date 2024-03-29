#include "testlib.h"
using namespace std;

struct Gen {
    static void tree_parents(int n) {
        vector<int> p(n - 1);
        auto a = rnd.distinct(n, n);
        shuffle(a.begin() + 1, a.end());
        for (int i = 1; i < n; i++)
            p[i - 1] = a[rnd.next(0, i - 1)] + 1;
        println(p);
    }

    static void tree_edges(int n) {
        auto a = rnd.perm(n);
        for (int i = 1; i < n; i++)
            println(a[i] + 1, a[rnd.next(0, i - 1)] + 1);
    }

    static void str(int n) {
        string s;
        for (int i = 0; i < n; i++)
            s += rnd.next('a', 'z');
        println(s);
    }
};

int main(int argc, char **argv) {
    registerGen(argc, argv, 1);

    int n = rnd.next(2, 20), q = rnd.next(1, 5);

    println(1);
    println(n, q);
    Gen::str(n);

    while (q--) {
        int l = rnd.next(1, n - 1);
        int r = rnd.next(l, n);
        println(l, r);
    }
}
