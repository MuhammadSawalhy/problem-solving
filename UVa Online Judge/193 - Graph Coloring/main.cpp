#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long
#define ll long long
#define vi vector<int>
#define vb vector<bool>
#define pii pair<int, int>

vector<unordered_set<int>> adjlist;
vector<int> connected;
int n, k;
vi ans;
vi a;

// db && backtracking
void doit(int i) {
  if (i == n) {
    if (a.size() > ans.size())
      ans = a;
    return;
  }

  doit(i + 1);

  if (!connected[i]) {
    // make black
    for (int n : adjlist[i])
      connected[n]++;
    a.push_back(i);
    // recurse
    doit(i + 1);
    // make white
    for (int n : adjlist[i])
      connected[n]--;
    a.pop_back();
  }
}

void solve() {
  cin >> n >> k;
  connected = vi(n);
  adjlist = vector<unordered_set<int>>(n);

  for (int i = 0; i < k; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    adjlist[a].insert(b);
    adjlist[b].insert(a);
  }

  doit(0);
  cout << ans.size() << endl;
  bool f = false;
  for (int n : ans)
    cout << (f ? " " : "") << n + 1, f=1;
  cout << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--)
    solve();
  return 0;
}
