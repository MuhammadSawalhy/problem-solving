// ﷽
#include <bits/stdc++.h>
#include "testlib.h"

using namespace std;

#define int long long
#define all(v) v.begin(), v.end()

void interact() {
    // cout to the solution and cin from it, interact and enjoy
    int n = rnd.next(1, 100);
    println(n);
    int ans, correct = sin(n);
    cin >> ans;
    assert(correct == ans);
}

int32_t main(int32_t argc, char *argv[]) {
    registerGen(argc, argv, 1);

    int t = 1;
    cout << t << endl;
    while (t--) {
        interact();
    }

    return 0;
}
