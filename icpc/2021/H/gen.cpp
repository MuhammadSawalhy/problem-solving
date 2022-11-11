#include <iostream>

using namespace std;

int gen(int a, int b) { return a + rand() % (b - a + 1); }

int main(int argc, char *argv[]) {
  srand(atoi(argv[1]));
  int t = 1;
  // cout << t << endl;
  while (t--) {
    int n;
    n = gen(2, 5);
    cout << n << endl;

    while (n--) {
      int l = gen(2, 10);
      while (l--) {
        cout << "()"[gen(0, 1)];
      }
      cout << endl;
    }
  }

  return 0;
}
