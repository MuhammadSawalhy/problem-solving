#include <algorithm>
#include <stdio.h>
using namespace std;

int main() {
    int n, b, s = 0, c = 0, h[20000];
    scanf("%d %d", &n, &b);
    for (int i = 0; i < n; i++) scanf("%d", &h[i]);
    sort(h, h + n);
    for (int i = n - 1; i >= 0; i--) {
        s += h[i], c++;
        if (s >= b) break;
    }
    printf("%d\n", c);
    return 0;
}

