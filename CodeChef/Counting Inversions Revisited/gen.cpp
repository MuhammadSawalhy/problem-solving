#include <iostream>

using namespace std;

int gen(int a, int b) { return a + rand() % (b - a + 1); }

int main(int argc, char *argv[]) {
  srand(atoi(argv[1]));
  int t = gen(1, 10);
  cout << t << endl;
  while (t--) {
    int n, k;
    n = gen(1, 4);
    k = gen(1, 4);

    cout << n << " " << k << endl;

    while (n--)
      cout << gen(1, 100) << " ";

    cout << endl;
  }

  return 0;
}
