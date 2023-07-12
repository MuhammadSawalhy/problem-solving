#include <iostream>

using namespace std;

int gen(int a = 1, int b = 10) { return a + rand() % (b - a + 1); }

int main(int argc, char *argv[]) {
    srand(atoi(argv[1]));
    int t = 1;
    /* cout << t << endl; */
    while (t--) {
        int n;
        n = gen(1, 10);
        cout << n << endl;
        for (int i = 0; i < n; i++)
            for (int j = i; j < n; j++)
                cout << gen(0,2) << " \n"[j==n-1];
        cout << endl;
    }

    return 0;
}
