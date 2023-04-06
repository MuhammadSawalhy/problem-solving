#include <iostream>

using namespace std;

int gen(int a = 1, int b = 10) { return a + rand() % (b - a + 1); }

string genstr(int len) {
    string s;
    for (int i = 0; i < len; i++) 
        s += 'a' + gen(0, 25);
    return s;
}

int main(int argc, char *argv[]) {
    if (argc > 1) srand(atoi(argv[1]));
    else srand(time(NULL));
    int t = 1;
    cout << t << endl;
    while (t--) {
        int s, l, r;
        s = gen(0, 100);
        l = gen(0, 100);
        r = gen(l, 100);
        cout << s << " " << l << " " << r << endl;
    }

    return 0;
}
