#include <iostream>

using namespace std;

int gen(int a, int b) { return a + rand() % (b - a + 1); }

int main(int argc, char *argv[]) {
  srand(atoi(argv[1]));
  int t = 1;

  int n, m = gen(1, 20);
  do {
    n = gen(1, 3);
  } while (n & 1);

  cout << n << " " << m << endl;
  return 0;
}
