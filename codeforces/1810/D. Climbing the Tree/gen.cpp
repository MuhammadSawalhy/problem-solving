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
        int n;
        n = gen();
        cout << n << endl;
        while (n--) {
            int t = gen(1, 2);
            int a = gen(2, 10);
            int b = gen(1, a - 1);
            if (t == 1) {
                cout << t << " " << a << " " << b << " " << gen() << endl;
            } else {
                cout << t << " " << a << " " << b << endl;
            }
        }
            
        cout << endl;
    }

    return 0;
}
