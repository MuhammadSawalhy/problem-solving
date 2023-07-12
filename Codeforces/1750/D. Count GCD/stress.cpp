#include <bits/stdc++.h>
using namespace std;
int mod = 998244353;
struct Mint
{
    int val;
    Mint(int _val = 0)
    {
        val = _val % mod;
    }
    Mint(long long _val = 0)
    {
        val = _val % mod;
    }
    Mint operator+(Mint oth)
    {
        return val + oth.val;
    }
    Mint operator*(Mint oth)
    {
        return 1LL * val * oth.val;
    }
    Mint operator-(Mint oth)
    {
        return val - oth.val + mod;
    }
    void operator+=(Mint oth)
    {
        val = (Mint(val) + oth).val;
    }
    void operator-=(Mint oth)
    {
        val = (Mint(val) - oth).val;
    }
    void operator*=(Mint oth)
    {
        val = (Mint(val) * oth).val;
    }
};
vector<int> get_primes(int n)
{
    int d = 2;
    vector<int> ans;
    while (d * d <= n)
    {
        bool este = false;
        while (n % d == 0)
        {
            n /= d;
            este = true;
        }
        if (este)
        {
            ans.push_back(d);
        }
        d++;
    }
    if (n != 1)
    {
        ans.push_back(n);
    }
    return ans;
}
int gcd(int a, int b)
{
    while (b)
    {
        int c = a % b;
        a = b;
        b = c;
    }
    return a;
}
int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    int q;
    cin >> q;
    while (q--)
    {
        int n, m;
        cin >> n >> m;
        vector<int> a(n + 1);
        for (int i = 1; i <= n; ++i)
        {
            cin >> a[i];
        }
        bool ok = true;
        for (int i = 2; i <= n; ++i)
        {
            if (a[i - 1] % a[i] != 0)
            {
                ok = false;
                break;
            }
        }
        if (!ok)
        {
            cout << 0 << '\n';
            continue;
        }
        vector<int> factori = get_primes(a[1]);
        map<pair<int, int>, int> calculat;
        for (int i = 2; i <= n; ++i)
        {
            calculat[{a[i - 1], a[i]}] = 0;
        }
        for (auto i : calculat)
        {
            int left = i.first.first / i.first.second;
            int till = m / i.first.second;
            vector<int> left_primes;
            for (auto i : factori)
            {
                if (left % i == 0)
                {
                    left_primes.push_back(i);
                }
            }
            int sz = (int)left_primes.size();
            int ans = 0;
            for (int mask = 0; mask < (1 << sz); ++mask)
            {
                int prod = 1;
                int cnt = 0;
                for (int j = 0; j < sz; ++j)
                {
                    if (mask & (1 << j))
                    {
                        prod *= left_primes[j];
                        cnt++;
                    }
                }
                if (cnt % 2 == 0)
                {
                    ans += till / prod;
                }
                else
                {
                    ans -= till / prod;
                }
            }
            calculat[i.first] = ans;
        }
        Mint ans = 1;
        for (int i = 2; i <= n; ++i)
        {
            ans = ans * calculat[{a[i - 1], a[i]}];
        }
        cout << ans.val << '\n';
    }
}
