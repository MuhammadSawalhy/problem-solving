#include <iostream>

using namespace std;

int gen(int a = 1, int b = 10) { return a + rand() % (b - a + 1); }

int main(int argc, char *argv[]) {
    srand(atoi(argv[1]));
    int t = 1;
    cout << t << endl;
    while (t--) {
        int n;
        n = gen();
        cout << n << endl;

        while (n--) {
            cout << gen() << " ";
        }
        cout << endl;
    }

    return 0;
}
