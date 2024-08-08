#include "testlib.h"
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T, null_type, std::less<T>, rb_tree_tag, tree_order_statistics_node_update>;


int main(int argc, char **argv) {
    registerGen(argc, argv, 1);

    int n = opt<int>("n", rnd.next(1, (int) 2e5));
    int mx = opt<int>("mx", (int) 1e9);
    int isaddonly = opt<bool>("addonly", false);
    println(n);

    ordered_set<int> s;

    for (int i = 0; i < n; i++) {
        int ins = rnd.next(1, 10);
        if (ins <= 5 && s.size() < mx / 2 || ins <= 7 && s.size() == 0 || ins <= 7 && isaddonly) {
            int x;
            do {
                x = rnd.next(1, mx);
            } while (s.find(x) != s.end());
            println('+', x);
            s.insert(x);
        } else if (ins <= 5 && s.size() >= mx / 2 || ins <= 7) {
            int ind = rnd.next(0, (int) s.size() - 1);
            int x = *s.find_by_order(ind);
            println('-', x);
            s.erase(x);
        } else {
            println('?');
        }
    }
}
