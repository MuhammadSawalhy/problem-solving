#include <bits/stdc++.h>

using namespace std;

int in() { int x; scanf("%d", &x); return x; }

const int L = 31;
int N, M;
int A[1000000], B[1000000];
int cnt[31];

bool check(int m) {
	memset(cnt, 0, sizeof cnt);
	for (int i = 0; i < m; ++i) ++cnt[B[i]];

	for (int i = N; i--; ) {
		int a = A[i];
		for (int l = L; l--; ) {
			// try to put the arrays in this cluster
			int tmp = min(cnt[l], a >> l);
			cnt[l] -= tmp;
			a -= tmp << l;
		}
	}

	for (int l = 0; l < L; ++l) {
		if (cnt[l]) return 0;
	}

	return 1;
}

int main() {
	int i, j;
	
	for (; ~scanf("%d%d", &N, &M); ) {
		for (i = 0; i < N; ++i) A[i] = in();
		for (j = 0; j < M; ++j) B[j] = in();

		sort(A, A + N);
		sort(B, B + M);

		int lo = 0, ho = M;
		for (; lo < ho; ) {
			int mo = (lo + ho + 1) >> 1;
			if (check(mo)) lo = mo;
			else ho = mo - 1;
		}

		printf("%d\n", lo);
	}
	
	return 0;
}
 
