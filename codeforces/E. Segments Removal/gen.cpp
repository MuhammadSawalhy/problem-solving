#include <iostream>

using namespace std;

int gen(int a, int b) { return a + rand() % (b - a + 1); }

int main(int argc, char *argv[]) {
  srand(atoi(argv[1]));
  int n = gen(1, 10);

  cout << n << endl;
  while (n--) {
    cout << gen(1, 3) << "\n "[!!n];
  }

  return 0;
}
