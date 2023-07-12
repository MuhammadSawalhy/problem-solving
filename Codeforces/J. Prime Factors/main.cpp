#include <bits/stdc++.h>
#include <iostream>
#define FAST
#define endd "\n"
#define ll long long
#define ld long double
#define ull unsigned long long
using namespace std;
bool isprime(ll n) {
  if (n == 2 || n == 3)
    return true;
  if (n <= 1 || n % 2 == 0)
    return false;
  for (int i = 3; i * i <= n; i += 2) {
    if (n % i == 0) {
      return false;
    }
  }
  return true;
}
// sum of odd numbers at a given range [l,r] (inclusive)
long long sumRange(long long l, long long r) {
  return (r * (r + 1)) / 2 - ((l - 1) * ((l - 1) + 1)) / 2;
}

// sum of even numbers at a given range [l,r] (inclusive)
long long sumEvenRange(long long l, long long r) {
  return (r / 2) * (r / 2 + 1) - ((l - 1) / 2) * ((l - 1) / 2 + 1);
}

// sum of odd numbers at a given range [l,r] (inclusive)
long long sumOddRange(long long l, long long r) {
  return sumRange(l, r) - sumEvenRange(l, r);
}

ll f(ll a, ll b, ll q) {
  if (q == 1)
    return a;
  if (q == 2)
    return b;
  if (q % 3 == 0)
    return (a ^ b);
  else if ((q + 1) % 3 == 0)
    return b;
  else
    return a;
}
ll factoril(ll n) {
  ll num = 1;
  while (n > 0) {
    num *= n;

    n--;
  }
  return num;
}
ll numofdigits(ll n) {
  ll num = factoril(n);
  ll cnt = 0;
  while (num > 0) {
    cnt++;
    num /= 10;
  }
  return cnt;
}
// Function to find the largest number
// smaller than or equal to N
// that is divisible by K
int findSmallNum(int N, int K) {
  // Finding the remainder when N is
  // divided by K
  int rem = N % K;

  // If the remainder is 0, then the
  // number itself is divisible by K
  if (rem == 0)
    return N;
  else

    // Else, then the difference between
    // N and remainder is the largest number
    // which is divisible by K
    return N - rem;
}

// Function to find the smallest number
// greater than or equal to N
// that is divisible by K
int findLargeNum(int N, int K) {
  // Finding the remainder when N is
  // divided by K
  int rem = (N + K) % K;

  // If the remainder is 0, then the
  // number itself is divisible by K
  if (rem == 0)
    return N;
  else

    // Else, then the difference between
    // N and remainder is the largest number
    // which is divisible by K
    return N + K - rem;
}
int sumDivisibles(int A, int B, int M) {
  // Variable to store the sum
  int sum = 0;
  int first = findSmallNum(A, M);
  int last = findLargeNum(B, M);

  // To bring the smallest and largest
  // numbers in the range [A, B]
  if (first < A)
    first += M;

  if (last > B)
    first -= M;

  // To count the number of terms in the AP
  int n = (B / M) - (A - 1) / M;

  // Sum of n terms of an AP
  return n * (first + last) / 2;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  FAST int N;
  cin >> N;
  ull mum = sqrt(N);
  ull arr[mum + 1] = {};
  ll nn = N;
  memset(arr, 0, sizeof(N));
  // i <= sqrt(N) >> Square both sides >> i * i <= N
  // sqrt(N) take O(log(N)) , i * i take O(1), so it is faster
  int mx = INT_MIN;
  for (int i = 2; i * i <= N; i++) {
    while (N % i == 0) {
      // cout << i << " ";
      arr[i]++;
      if (i > mx)
        mx = i;
      N /= i;
    }
  }

  if (N == nn) {
    cout << "(" << N << "^" << 1 << ")" << endd;
    return 0;
  }

  if (N > 1) // To Handle if N is a prime number
  {
    // cout << N << endl;
    if (N > mx)
      mx = N;

    arr[N]++;
  }

  for (int i = 2; i <= mx; i++) {
    if (arr[i] >= 1) {
      cout << "(" << i << "^" << arr[i] << ")";
      if (i != mx)
        cout << "*";
    }
  }

  cout << endd;

  return 0;
}
