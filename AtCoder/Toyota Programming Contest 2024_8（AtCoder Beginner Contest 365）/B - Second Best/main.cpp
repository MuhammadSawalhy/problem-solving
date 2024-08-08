#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<int> A(N);
    
    for(int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    
    // Find the largest and second largest elements
    int first_largest = -1;
    int second_largest = -1;
    
    for(int i = 0; i < N; ++i) {
        if (A[i] > first_largest) {
            second_largest = first_largest;
            first_largest = A[i];
        } else if (A[i] > second_largest) {
            second_largest = A[i];
        }
    }
    
    // Find the 1-based index of the second largest element
    int index = -1;
    for(int i = 0; i < N; ++i) {
        if (A[i] == second_largest) {
            index = i + 1;  // Convert 0-based index to 1-based index
            break;
        }
    }
    
    cout << index << endl;
    return 0;
}

