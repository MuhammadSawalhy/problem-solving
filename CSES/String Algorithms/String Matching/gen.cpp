#include <iostream>

using namespace std;

int gen(int a = 1, int b = 10) { return a + rand() % (b - a + 1); }

string genstr(int len) {
    string s;
    for (int i = 0; i < len; i++) 
        s += 'a' + gen(0, 3);
    return s;
}

int main(int argc, char *argv[]) {
    srand(atoi(argv[1]));
    int t = 1;
    /* cout << t << endl; */

    while (t--) {
        int l = gen(10, 20);
        cout << genstr(l) << endl;
        cout << genstr(gen(1, 4)) << endl;
    }

    return 0;
}
