#include<bits/stdc++.h>
using namespace std;

const int pot = 512 * 1024;
long long tr[2*pot];

vector<int> properties[pot];
int need[pot];
int ans[pot];
int from[pot], to[pot], val[pot];

void tree_add(int low, int high, int v) {
	assert(low <= high);
	low += pot;
	high += pot;
	tr[low] += v;
	if(low != high) tr[high] += v;
	while(low + 1 < high) {
		if(low % 2 == 0) tr[low+1] += v;
		if(high % 2 == 1) tr[high-1] += v;
		low /= 2;
		high /= 2;
	}
}
void tree_add(int i_q, int multiplier) {
	int v = val[i_q] * multiplier;
	if(from[i_q] <= to[i_q])
		tree_add(from[i_q], to[i_q], v);
	else {
		tree_add(from[i_q], pot - 1, v);
		tree_add(0, to[i_q], v);
	}
}
long long tree_get(int where) {
	long long s = 0;
	for(int x = pot + where; x >= 1; x /= 2)
		s += tr[x];
	return s;
}

void rec(int low, int high, vector<int> & owners, int & act_tree) {
	if(owners.empty()) return;
	int mid = (low + high) / 2;
	while(act_tree < mid)
		tree_add(++act_tree, 1);
	while(act_tree > mid)
		tree_add(act_tree--, -1);
	
	vector<int> left_owners;
	vector<int> right_owners;
	for(int who : owners) {
		long long his_value = 0;
		for(int where : properties[who]) {
			his_value += tree_get(where);
			if(his_value >= need[who]) break;
		}
		if(his_value >= need[who]) {
			left_owners.push_back(who);
			ans[who] = high;
		}
		else
			right_owners.push_back(who);
	}
	owners.clear(); // thanks to this line the memory is O(n), not O(n log(n))
	if(low < high) {
		rec(low, mid, left_owners, act_tree);
		rec(mid + 1, high, right_owners, act_tree);
	}
}

int main() {
	int n, len;
	scanf("%d%d", &n, &len);
	for(int where = 1; where <= len; ++where) {
		int who;
		scanf("%d", &who);
		properties[who].push_back(where);
	}
	for(int who = 1; who <= n; ++who)
		scanf("%d", &need[who]);
	int q;
	scanf("%d", &q);
	for(int day = 1; day <= q; ++day)
		scanf("%d%d%d", &from[day], &to[day], &val[day]);
	
	vector<int> owners;
	for(int who = 1; who <= n; ++who)
		owners.push_back(who);
	
	int act_tree = 0;
	rec(1, q, owners, act_tree);
	
	for(int who = 1; who <= n; ++who) {
		if(ans[who]) printf("%d\n", ans[who]);
		else puts("NIE");
	}
	return 0;
}
