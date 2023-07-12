#include <iostream>

using namespace std;

int gen(int a, int b) { return a + rand() % (b - a + 1); }

int main(int argc, char *argv[]) {
  srand(atoi(argv[1]));
  int t = 4;
  cout << t << endl;
  int n = t + 1;
  while (t--) {
    int q = 1;
    cout << --n << " " << q << endl;

    for (int i = 1; i <= n; i++) {
      cout << 1 << " ";
    }
    cout << endl;

    int cnt = 1000;
    while (q--) {
      cout << cnt++ << " ";
    }
    cout << endl;
  }

  return 0;
}
