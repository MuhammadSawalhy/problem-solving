#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

bool isFeasible(const vector<int>& A, ll x, ll M) {
    ll total_subsidy = 0;
    for (int a : A) {
        total_subsidy += min((ll)a, x);
        if (total_subsidy > M) return false;
    }
    return total_subsidy <= M;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    ll M;
    cin >> N >> M;
    vector<int> A(N);
    
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    ll left = 0;
    ll right = *max_element(A.begin(), A.end());
    
    // Check if the total subsidy can be infinite
    ll total_subsidy = 0;
    for (int a : A) {
        total_subsidy += a;
    }
    if (total_subsidy <= M) {
        cout << "infinite" << endl;
        return 0;
    }
    
    // Binary search for the maximum x
    while (left < right) {
        ll mid = left + (right - left + 1) / 2;  // Prevent infinite loop, prefer the upper half
        if (isFeasible(A, mid, M)) {
            left = mid;
        } else {
            right = mid - 1;
        }
    }
    
    cout << left << endl;
    return 0;
}

