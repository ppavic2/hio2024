#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

const int N = 5e5 + 2;

int n, q, a[N], pre[N][10];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n >> q;
	for (int i = 0; i < n; ++i) {
		cin >> a[i], --a[i];
		++pre[i][a[i]];
		if (i) for (int j = 0; j < 10; ++j) pre[i][j] += pre[i - 1][j];
	}
	
	while (q--) {
		int l, r;
		cin >> l >> r, --l, --r;
		int len = r - l + 1;
		int maks = 0, dif = 0, dif2 = 0;
		
		for (int i = 0; i < 10; ++i) {
			int cnt = pre[r][i];
			if (l) cnt -= pre[l - 1][i];
			if (cnt) ++dif;
			if (cnt > 1) ++dif2;
			maks = max(maks, cnt);
		}
		
		if (maks * 2 > len) cout << "1\n";
		else if (maks * 2 == len && dif == 2) cout << "0\n";
		else if (maks * 2 == len) cout << "1\n";
		else if (len & 1) cout << dif << "\n";
		else cout << dif2 << "\n";
	}
	
	return 0;
}
