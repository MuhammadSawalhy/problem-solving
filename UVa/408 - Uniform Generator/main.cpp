// ﷽
#include <bits/stdc++.h>

using namespace std;

#ifdef SAWALHY
#include "debug.hpp"
#else
#define debug(...)
#define debug_itr(...)
#define debug_bits(...)
#endif

#define int long long
#define ll long long
#define all(v) v.begin(), v.end()

int32_t main() {
    int step, mod;
    while (cin >> step >> mod) {
        
        // -> 1. Remainder is always a multiple of the gcd
        //    2. We can can always get to 0 again (at least after MOD steps)
        //    3. Is that any repetition before getting back to 0?
        //       NO, because that means we need we will stuck at infinite
        //       loop and never get to 0 again which is obviously not what happens
        //    4. Continuing observation 1, will we traverse all these multiples of gcd we need?
        //       YES, we will get all multiples of the gcd and the only way to get 0 again
        //       is that x*STEP itself is a multiple of MOD and also x*gcd is a multiple of MOD
        //       when gcd = 1, x (the number of steps) has to be MOD which what we need,
        //       we need MOD steps to get back to 0
        //    5. When (gcd != 1) we won't get all remainders in range [0, STEP - 1]
        //
        // -> So we conclude:
        //    - gcd(STEP, MOD) == 1  --> good
        //    - gcd(STEP, MOD) != 1  --> bad

        // ANOTHER PROOF
        //
        // -> we start with 0 and keep adding STEP, and after x steps we have x*STEP
        //    1. we need exactly MOD steps to get back to 0:
        //      now, we can prove that we need MOD steps to get back to 0 again and
        //      because if we get to a value and came back to it we will stuck in that look
        //      for example 0 -> 1 -> 2 -> 3 -> 2 -> 3 .... because 2 will always result in the same sequence
        //      --- so the requirement of a good choice is to come back to 0 after exactly MOD steps
        //      we can assure that all value [0 ... MOD-1] are covered
        //    2. the only way to get back after MOD step is when STEP and MOD are coprime:
        //      STEP + STEP + ... + STEP (addition x times) = x * STEP
        //      we need to get the multiple of MOD (so that x * step % MOD == 0) only MOD steps
        //      so LCM(STEP, MOD) is the first multiple of MOD we encounter
        //      so it is required that gcd(STEP, MOD) == 1

        string res = "Good Choice";
        if (__gcd(mod, step) != 1)
            res = "Bad Choice";
        printf("%10lld%10lld    %s\n", step, mod, res.c_str());
        puts("");
    }
    return 0;
}
