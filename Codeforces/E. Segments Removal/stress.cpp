#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<pair<int, int>> ps;
    for(int i=0; i<N; i++){
        int a;
        cin >> a;
        if(ps.size() && ps.back().first == a){
            ps.back().second++;
        }else{
            ps.emplace_back(a, 1);
        }
    }
    int sz = ps.size();
    map<int, pair<int, int>> mp;
    // sz, -idx
    priority_queue<pair<int, int>> que;
    for(int i=0; i<sz; i++){
        mp[i] = ps[i];
        que.push({ps[i].second, -i});
    }
    int ans = 0;
    while(que.size()){
        auto p = que.top(); que.pop();
        int sz = p.first, idx = -p.second;
        if(!mp.count(idx) || mp[idx].second != sz) continue;
        ans++;
        auto it = mp.lower_bound(idx);
        it = mp.erase(it);
        if(it != mp.end() && it != mp.begin() && it->second.first == prev(it)->second.first){
            prev(it)->second.second += it->second.second;
            que.push({prev(it)->second.second, -prev(it)->first});
            mp.erase(it);
        }
    }
    cout << ans << endl;
    return 0;
}

