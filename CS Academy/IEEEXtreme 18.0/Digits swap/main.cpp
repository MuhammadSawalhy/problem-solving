#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

unordered_map<string, unordered_map<int, string>> memo;

string maximizeNumberRec(string digits, int k) {
    if (k == 0) {
        return digits;
    }

    if (memo.find(digits) != memo.end() && memo[digits].find(k) != memo[digits].end()) {
        return memo[digits][k];
    }

    string maxNumber = digits;

    int n = digits.size();
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            // Swap only if it creates a larger number
            if (digits[j] > digits[i]) {
                swap(digits[i], digits[j]);

                // Recursively call with one less swap
                string candidate = maximizeNumberRec(digits, k - 1);
                maxNumber = max(maxNumber, candidate);

                // Backtrack to restore the original number
                swap(digits[i], digits[j]);
            }
        }
    }

    // Memoize the result for the current configuration and remaining swaps
    memo[digits][k] = maxNumber;
    return maxNumber;
}

int main() {
    long long N;
    int K;
    cin >> N >> K;

    string digits = to_string(N); // Convert the integer to a string of digits
    cout << maximizeNumberRec(digits, K) << endl;

    return 0;
}
