#include <bits/stdc++.h>

using namespace std;

// clang-format off
#ifndef ONLINE_JUDGE
#include "/home/ms/myp/problem-solving/debug.hpp"
#else
#define debug(...)
#define debug_arr(...)
#define debug_bits(...)
#endif

typedef long long ll;
typedef unsigned long ul;
typedef unsigned long long ull;

#define int ll
#define f(i, b) for (ll i = 0; i < b; i++)
#define ff(i, a, b) for (ll i = a; i < b; i++)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define sz(x) (ll)(x).size()
#define sum(v) accumulate(all(v), 0)
#define pop_cnt(x) (__builtin_popcountll(x))
#define LSB(x) (__builtin_ffsll(x) - 1)
#define MSB(x) (64 - __builtin_clzll(x) - 1)

typedef vector<int> vi;
typedef vector<bool> vb;

template <class T> inline void clear(T *arr, int val, int n) { while(n--) arr[n] = val; }
// clang-format on

int v, e;
vi tasks;
vector<bool> vis;
vector<bool> revvis;
vector<vi> adj;
vector<vi> revadj;

int calc_dependencies(int i, vector<bool> &vis) {
  vis[i] = true;
  int deps = 0;

  for (auto d : adj[i]) {
    if (!vis[d]) {
      deps += calc_dependencies(d, vis);
      deps += tasks[d];
    }
  }

  return deps;
}

int calc_dependants(int i, vector<bool> &vis) {
  vis[i] = true;
  int deps = 0;

  for (auto d : revadj[i]) {
    if (!vis[d]) {
      deps += calc_dependants(d, vis);
      deps += tasks[d];
    }
  }

  return deps;
}

bool solve(int counter) {
  cin >> v >> e;
  if (v == 0)
    return false;

  std::cout << "Case #" << counter << ":" << std::endl;

  tasks.resize(v);
  int s = 0;
  for (auto &i : tasks) {
    cin >> i;
    s += i;
  }

  adj.clear();
  adj.resize(v);
  revadj.clear();
  revadj.resize(v);

  while (e--) {
    int x, y;
    cin >> x >> y;
    x--;
    y--;
    adj[y].push_back(x);
    revadj[x].push_back(y);
  }

  int q;
  cin >> q;
  vector<bool> vis(v);
  while (q--) {
    int qq;
    cin >> qq;
    qq--;
    vis.clear();
    vis.resize(v);
    int depant = calc_dependants(qq, vis);
    vis.clear();
    vis.resize(v);
    int depcies = calc_dependencies(qq, vis);
    int ans = s - tasks[qq] - depant - depcies;
    std::cout << ans << std::endl;
  }

  cout << endl;

  return true;
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int counter = 0;
  while (counter++, solve(counter))
    ;
  return 0;
}
