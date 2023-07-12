#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long
#define ll long long
#define vi vector<int>
#define vb vector<bool>
#define pii pair<int, int>

const int N = 3e3 + 1;

int n;
int v[5];
pii points[N];

int quarter(int i) {
  int x = points[i].first;
  int y = points[i].second;
  if (x >= 1 && y >= 1)
    return 1;
  if (x <= -1 && y >= 1)
    return 2;
  if (x <= -1 && y <= -1)
    return 3;
  if (x >= 1 && y <= -1)
    return 4;
  return 0;
}

double calc_dist(int i, int k) {
  ll dx = points[i].first - points[k].first;
  ll dy = points[i].second - points[k].second;
  double d = sqrt(dx * dx + dy * dy);

  int vol;
  int q1 = quarter(i), q2 = quarter(k);
  if (q1 != q2)
    vol = v[0];
  else
    vol = v[q1];

  return d / vol;
}

double dijkstra(int s, int e) {
  double dist[n + 1];
  int prev[n + 1];
  fill(dist, dist + n + 1, 1e20);

  typedef pair<double, int> item;
  priority_queue<item, deque<item>, greater<item>> qu;
  qu.push({0, s});

  while (!qu.empty()) {
    auto [d, p] = qu.top();
    qu.pop();

    // skip if there exist a shorter path to here
    if (dist[p] < d)
      continue;

    for (int i = 1; i <= n; i++) {
      if (i == p)
        continue;
      double dpp = calc_dist(p, i);
      // if there exist a shorter path to "i" passing through "p"
      if (dist[i] > dpp + d) {
        prev[i] = p;
        dist[i] = dpp + d;
        qu.push({dist[i], i});
      }
    }
  }

  // for (int i = e; i != s; i = prev[i]) cerr << i << " <- ";
  // cerr << s << endl;

  return dist[e];
}

void solve() {
  cin >> n;
  for (int i = 1; i <= 5; i++)
    cin >> v[i % 5];

  int s, e;
  cin >> s >> e;

  for (int i = 1; i <= n; i++) {
    cin >> points[i].first;
    cin >> points[i].second;
  }

  cout << fixed << setprecision(10) << dijkstra(s, e) << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}
