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
    else
        srand(time(NULL));
    int t = 1;
    // cout << t << endl;
    while (t--) {
        int n = 1, m = gen(1, 3) * 4;
        cout << n << " " << m << endl;
        while (m--)
            cout << gen(0, 1);
        cout << endl;
    }

    return 0;
}
