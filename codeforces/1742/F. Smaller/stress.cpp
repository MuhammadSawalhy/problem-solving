#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <ctime>
#include <bitset>

#pragma region Defines

#define re return
#define vec vector
#define pb(x) push_back(x)
#define vsort(x) sort(x.begin(), x.end())
#define all(x) x.begin(), x.end()
#define last(x) x.size() - 1

#define to_up(x) transform(x.begin(), x.end(), x.begin(), ::toupper)
#define to_low(x) transform(x.begin(), x.end(), x.begin(), ::tolower)

#define sqrt my_sqrt

typedef long long ll;
typedef long double ld;

using namespace std;

#pragma endregion

#pragma region Pastes

// File IO
//freopen ("input.txt", "r", stdin);
//freopen ("output.txt", "w", stdout);
// 
// Double printf
//printf("%.3f", ans);
// Uint printf
//printf("%u", ans);

#pragma endregion

#pragma region Functions

ld sqrt(ld x) {
    ld l = 0.0, r = 1e9 + 7.0;
    for (int i = 0; i < 100; ++i) {
        ld c = (l + r) / 2.0;
        if (c * c >= x) r = c;
        else if (c * c < x) l = c;
    }
    re r;
}

ll gcd(ll a, ll b) {
    while (a && b) {
        if (a > b) a %= b;
        else b %= a;
    }
    return a + b;
}

ll lcd(ll a, ll b) {
    return (a * b) / gcd(a, b);
}

double distance(double x1, double y1, double x2, double y2) {
    double ans = sqrt(pow(abs(x1 - x2), 2) + pow(abs(y1 - y2), 2));
    return ans;
}

#pragma endregion



/*//////////////////////////////////////////
//███████████████████▀▀███████████████████//
//█████████████████▀░▄▄░▀█████████████████//
//████████████████▀░████░▀████████████████//
//████████████████░██████░████████████████//
//███████████████░░██████░░██████▀████████//
//███████████████░████████░██▀░█░░████████//
//███████████████░████████░█▀░░░░▄░▀▀▀▀▀██//
//██████████████░░████████░░░░░░░░░░░░░▄██//
//██████████████░░███████▀░░░░░░░░░░░░▄███//
//██████▀▀██████░░█▀▀▀░░░░░░░░░░░░▄███████//
//██████▄░░░░░░█░░█░░░░░░░░░░░░░░░▀▀▀▀████//
//████████▄▄░░░██░█░░░░░░░░░░░░░░░▄▄▄░░███//
//████████▀░░░░██░█▄░░░░░░░░▄▄▄▄▄░░░█▄▄███//
//██████▀░░░░░░▄█░░█▄▄▄▄▄░░███████░░██████//
//███▀░░░░░░░▄████░██████░████████████████//
//██░░▄▄▀░░▄██████▄░████░▄████████████████//
//█████▄░▄█████████▄░▀▀░▄█████████████████//
//███████████████████░░███████████████████//
//██████████████▀▀▀▀▀░░▀▀▀▀▀██████████████//
//██████████████▄▄▄▄▄▄▄▄▄▄▄▄██████████████//
*///////////////////////////////////////////



/*////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


  .-')                                                                .-') _                                                .-') _
 ( OO ).                                                             (  OO) )                                              ( OO ) )
(_)---\_)       .-'),-----.        ,--.            ,--. ,--.         /     '._         ,-.-')        .-'),-----.       ,--./ ,--,'
/    _ |       ( OO'  .-.  '       |  |.-')        |  | |  |         |'--...__)        |  |OO)      ( OO'  .-.  '      |   \ |  |\  :` `.       /   |  | |  |       |  | OO )       |  | | .-')       '--.  .--'        |  |  \      /   |  | |  |      |    \|  | )
 '..`''.)      \_) |  |\|  |       |  |`-' |       |  |_|( OO )         |  |           |  |(_/      \_) |  |\|  |      |  .     |/
.-._)   \        \ |  | |  |      (|  '---.'       |  | | `-' /         |  |          ,|  |_.'        \ |  | |  |      |  |\    |
\       /         `'  '-'  '       |      |       ('  '-'(_.-'          |  |         (_|  |            `'  '-'  '      |  | \   |
 `-----'            `-----'        `------'         `-----'             `--'           `--'              `-----'       `--'  `--'


*/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



void solve() {

    int n;
    cin >> n;

    vec<int> s(256, 0); vec<int> t(256, 0);
    ++s[(int)'a']; ++t[(int)'a'];
    int ss = 1, st = 1;
    for (int i = 0; i < n; ++i) {
        int ty, k;
        string x;
        cin >> ty >> k >> x;
        if (ty == 1) {
            for (char c : x) {
                s[c] += k; ss += k;
            }
        }
        else {
            for (char c : x) {
                t[c] += k; st += k;
            }
        }
        bool less = 0; char mi = 'z',  ma = 'a';
        for (int i = 'a'; i <= 'z'; ++i) 
            if (s[i]) {
                mi = i;
                break;
            }
        for (int i = 'z'; i >= 'a'; --i)
            if (t[i]) {
                ma = i;
                break;
            }
        if (mi < ma) less = 1;
        else {
            if (ss == st) {
                for (int i = 'a'; i <= 'z'; ++i) {
                    if (s[i] != t[i]) {
                        less = s[i] > t[i];
                        break;
                    }
                }
            }
            else {
                
                int mas;
                for (int i = 'z'; i >= 'a'; --i)
                    if (s[i]) {
                        mas = i;
                        break;
                    }
                if (mas == ma) {
                    less = ss < st;
                }
                else {
                    less = 0;
                }
            }
        }
        
        if (less) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }

    cout << '\n';
}

int main() {

    std::ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);



    int multitest = 1;
    cin >> multitest;
    while (multitest--) {
        solve();
        //compare();
    }


    return 0;
}