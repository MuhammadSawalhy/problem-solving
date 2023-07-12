#include <iostream>

using namespace std;

int gen(int a, int b) { return a + rand() % (b - a + 1); }

int main(int argc, char *argv[]) {
  srand(atoi(argv[1]));
  int t = gen(1, 10);
  cout << t << endl;
  while (t--) {
    int n, k;
    n = gen(2, 10);
    k = gen(0, n - 1);

    cout << n << " " << k << endl;

    for (int i = 2; i <= n; i++) {
      cout << gen(1, i - 1) << " ";
    }

    cout << endl;
  }

  return 0;
}
