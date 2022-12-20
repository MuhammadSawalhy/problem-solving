// Date: 25-11-2022
#include <bits/stdc++.h>

using namespace std;

#define debug(...)
#define ll long long
#define all(v) v.begin(), v.end()
#ifdef LOCAL
#include "debug.hpp"
#endif

struct Team {
  string name;
  int goals = 0, misses = 0, points = 0;

  bool operator<(const Team &t) {
    if (points == t.points) {
      if (goals - misses < t.goals - t.misses) {
        return true;
      }
      if (goals - misses > t.goals - t.misses) {
        return false;
      }
      if (goals < t.goals)
        return true;
      if (goals > t.goals)
        return false;
      return name > t.name;
    }

    return points < t.points;
  }

  friend ostream &operator<<(ostream &os, const Team &t) {
    return os << t.name << " -> (points: " << t.points << ", goals: " << t.goals << ", misses: " << t.misses << ")" << endl;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);

  // we have
  // 1. points criteria
  // 2. teams order criteria
  // 3. answer choosing (last match) criteria

  // we have 2 teams with 3 games and 2 teams with 2 games
  // we can identify which teams will play the last game

  // brute force all possible senarios
  //
  // consider team with this goals
  //  9 0
  //  9 0
  //  9 0
  //  one of the above must be with Berland
  //
  // scores: 1 -> 30
  // misses: 0 -> scores - 1
  //
  //
  // each time sort and check, if I can win, just consider this case then at the end choose the best


  map<string, Team> teams;
  map<string, int> fr;

  for (int i = 0; i < 5; i++) {
    string a, b, r;
    cin >> a >> b >> r;
    fr[a]++;
    fr[b]++;
    if (!teams.count(a)) { teams[a].name = a; }
    if (!teams.count(b)) { teams[b].name = b; }
    int A = stoi(r.substr(0, 1)), B = stoi(r.substr(2, 1));
    if (A > B) {
      teams[a].points += 3;
    } else if (B > A) {
      teams[b].points += 3;
    } else {
      teams[a].points++;
      teams[b].points++;
    }
    teams[a].goals += A;
    teams[a].misses += B;
    teams[b].goals += B;
    teams[b].misses += A;
  }


  string op;
  for (auto p: teams) {
    if (fr[p.second.name] == 2 && p.second.name != "BERLAND") {
      op = p.second.name;
      break;
    }
  }

  auto valid = [&](int g, int m) {
    vector<Team> ts;
    for (auto [name, t]: teams) {
      if (name == "BERLAND") {
        t.points += 3;
        t.goals += g;
        t.misses += m;
      }

      if (name == op) {
        t.goals += m;
        t.misses += g;
      }

      ts.push_back(t);
    }

    sort(all(ts));
    return (ts[3].name == "BERLAND" || ts[2].name == "BERLAND");
  };

  vector<pair<int, int>> ans;
  for (int goals = 1; goals <= 30; goals++) {
    for (int misses = 0; misses < goals; misses++) {
      if (valid(goals, misses))
        ans.push_back({goals, misses});
    }
  }

  if (ans.empty()) {
    cout << "IMPOSSIBLE" << endl;
    return 0;
  }

  sort(all(ans), [](auto l, auto r) {
    if (l.first - l.second == r.first - r.second) {
      return l.second > r.second;
    }
    return l.first - l.second > r.first - r.second;
  });

  cout << ans.back().first << ":" << ans.back().second << endl;

  return 0;
}
