#include <bits/stdc++.h>

#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define ull unsigned long long
using namespace std;
const ll N = 1e5 + 5;
const ll mod = 1e9 + 7;

/*
      استعن بالله ولا تعجز
*/

vector<int> vv;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        vector<int> v(n);


        // this observation is thanks to brute force
        // لو وقع وحيات أمي لأكسر اللاب

        int curr = n - 2;

        v[n - 1] = n;
        v[n - 2] = n - 1;
        for (int i = n - 3; i >= 0; i -= 2) {
            if (i < 1)
                break;
            v[i] = curr - 1;
            v[i - 1] = curr;
            curr -= 2;
        }

        v[0] += curr;

        for (auto it: v)
            cout << it << " ";
        cout << endl;


        continue;


        /*
      for(int i=0;i<n-4;i++)
          v.push_back(i+1);
      v.push_back(n-2);
      v.push_back(n-3);
      v.push_back(n-1);
      v.push_back(n);

      */

        ll res = 0;
        for (int i = 0; i < n; i++) {
            if (res < v[i])
                res += v[i];
            else res = 0;
        }
        cout << res << endl;

        /*      sort(v.begin(), v.end(), greater<int>());
              for(auto it : v)
                  cout << it << " ";
              cout << endl;    */


        sort(v.begin(), v.end());
        ll mx_res = -100;
        while (next_permutation(v.begin(), v.end())) {
            ll res = 0;
            for (int i = 0; i < n; i++) {
                if (res < v[i])
                    res += v[i];
                else res = 0;
            }
            //   cout << " res = " << res << "  ";
            //  for(int i=0;i<n;i++)
            //      cout << v[i] << "  ";
            //  cout << endl;
            if (mx_res < res)
                vv = v;
            //    for(auto it : vv)
            //       cout << it << " ";
            //   cout << endl;
            mx_res = max(mx_res, res);

        }
        cout << endl;
        for (auto it: vv)
            cout << it << " ";
        cout << endl;
        cout << mx_res << " max res" << endl;


    }
}
