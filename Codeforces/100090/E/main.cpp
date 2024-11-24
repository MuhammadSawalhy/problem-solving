#include <bits/stdc++.h>
using namespace std;

int n, m;
 
int main () {
    double p, q;
    cin >> p >> q;
    p /= 100, q /= 100;
	double first_prop = p / (p + q);
	double second_prop = q / (p + q);
    cout << fixed << setprecision(7) << p * first_prop + q * second_prop << endl;
    return 0;
}

