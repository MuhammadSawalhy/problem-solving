#include <cmath>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

int main() {
  /*
          k^n = p
          (k^n)^(1/n) = p^(1/n)
          k = p^(1/n)

          Or
          k^n = p
          ln(k^n) = ln(p)   --> ln(n^power) == power*ln(n)
          n*ln(k) = ln(p)
          ln(k) = ln(p)/n   --> ln(x) == e^x, e = 2.71828182845904523536
          k = e^(ln(p)/n)
  */
  double n, p;
  while (scanf("%lf%lf", &n, &p) != EOF) {
    printf("%.0lf\n", pow(p, 1 / n));
  }
}
