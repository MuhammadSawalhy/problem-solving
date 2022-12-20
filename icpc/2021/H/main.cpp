// Date: 10-11-2022
#include <bits/stdc++.h>

using namespace std;

#define debug(...)
#define ll long long
#define all(v) v.begin(), v.end()
#ifdef SAWALHY
#include "debug.hpp"
#endif

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);

  int n;
  cin >> n;

  // it should have value, and cost
  //
  // if we can afford the cost (needed ")") then add it to the priority queue
  // get from the priorityq queue the best one according to value (surely we can afford it and all is well)

  vector<array<int, 3>> parts;   // cost, value, index
  vector<array<int, 2>> closings;// cost, index
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;

    int cost = 0;
    int value = 0;
    for (int j = 0; j < (int) s.size(); j++) {
      if (s[j] == '(') {
        value++;
        continue;
      }

      if (value) {
        value--;
        continue;
      }

      cost++;
    }

    if (value == 0) {
      closings.push_back({cost, i});
    } else {
      parts.push_back({cost, value, i});
    }
  }

  stable_sort(parts.begin(), parts.end(), [](auto l, auto r) {
    return l[0] > r[0];// less cost at the end (last should be zero)
  });

  debug(parts);

  if (closings.empty() || parts.size() && parts.back()[0] != 0) {
    cout << "impossible" << endl;
    return 0;
  }

  auto comp = [](auto l, auto r) -> bool {
    int lvalue = l[1] - l[0];
    int rvalue = r[1] - r[0];
    if (lvalue == rvalue) {
      return l[0] < r[0]; // if same net value, give priority for the higher in cost
    }
    return lvalue < rvalue; // low priority for less net value provided
  };

  priority_queue<array<int, 3>, vector<array<int, 3>>, decltype(comp)> qu(comp);
  int budget = 0;
  vector<int> ans;

  bool ok = true;
  while (ok) {
    ok = false;
    while (parts.size() && parts.back()[0] <= budget) {
      // can affortd
      qu.push(parts.back());
      parts.pop_back();
      ok = true;
    }

    if (qu.size()) {
      auto [cost, value, index] = qu.top();
      debug(qu.top());
      budget -= cost;
      if (budget < 0) {
        cout << "impossible" << endl;
        return 0;
      }
      budget += value;
      ans.push_back(index);
      qu.pop();
      ok = true;
    }
  }

  for (auto [cost, index] : closings) {
    budget -= cost;
    ans.push_back(index);
  }

  if (!parts.empty() || budget) {
    cout << "impossible" << endl;
    return 0;
  }

  for (auto i: ans) {
    cout << i + 1 << endl;
  }

  return 0;
}
