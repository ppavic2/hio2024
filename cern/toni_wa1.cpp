#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

const int N = 5e5 + 2;
const int OFF = 1 << 20;

int n, q, a[N];
int ql[N], qr[N], freq[N], cnt_uk[N][3];
int maks[N], cnt_dif[N], cnt_2[N];

int tour[OFF][2], lst[N], sec[N];

struct Node {
	int val = 0, freq = 0;
} tour2[OFF];

vector<int> vq;
vector<pair<int, pii> > query[N];

void upd(int x, int l, int r, int i, int val, bool b) {
	if (l > i || r < i) return ;
	tour[x][b] += val;
	if (l != r) {
		int mid = (l + r) >> 1;
		upd(x * 2 + 1, l, mid, i, val, b);
		upd(x * 2 + 2, mid + 1, r, i, val, b);
	}
}
int f(int x, int l, int r, int ql, int qr, bool b) {
	if (ql > r || l > qr) return 0;
	if (ql <= l && r <= qr) return tour[x][b];
	int mid = (l + r) >> 1;
	return f(x * 2 + 1, l, mid, ql, qr, b) + f(x * 2 + 2, mid + 1, r, ql, qr, b);
}
Node merge(Node A, Node B) {
	if (A.val == B.val) return (Node){A.val, A.freq + B.freq};
	if (A.freq > B.freq) swap(A, B);
	if (A.freq < B.freq) return (Node){B.val, B.freq - A.freq};
	return (Node){0, 0};
}

void con(int x, int l, int r) {
	if (l == r) {
		tour2[x] = {a[l], 1};
		return ;
	}
	int mid = (l + r) >> 1;
	con(x * 2 + 1, l, mid);
	con(x * 2 + 2, mid + 1, r);
	tour2[x] = merge(tour2[x * 2 + 1], tour2[x * 2 + 2]);
	return ;
}

void calc(int x, int l, int r, int ql, int qr, Node& st) {
	if (ql > r || l > qr) return ;
	if (ql <= l && r <= qr) {
		st = merge(st, tour2[x]);
		return ;
	}
	int mid = (l + r) >> 1;
	calc(x * 2 + 1, l, mid, ql, qr, st);
	calc(x * 2 + 2, mid + 1, r, ql, qr, st);
	return ;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n >> q;
	for (int i = 0; i < n; ++i) cin >> a[i];
	
	con(0, 0, n - 1);
	
	for (int i = 0; i < q; ++i) {
		cin >> ql[i] >> qr[i], --ql[i], --qr[i];
		
		vq.clear();
		Node st = {0, 0};
		calc(0, 0, n - 1, ql[i], qr[i], st);
		vq.push_back(st.val);
		if (ql[i] != qr[i]) {
			st = {0, 0};
			calc(0, 0, n - 1, ql[i] + 1, qr[i], st);
			vq.push_back(st.val);
			st = {0, 0};
			calc(0, 0, n - 1, ql[i], qr[i] - 1, st);
			vq.push_back(st.val);
		}
		for (int j = 0; j < (int)vq.size(); ++j) {
			if (ql[i]) query[ql[i] - 1].push_back({-vq[j], {i, j}});
			query[qr[i]].push_back({vq[j], {i, j}});
		}
	}
	for (int i = 0; i < n; ++i) {
		++freq[a[i]];
		for (auto x : query[i]) {
			if (x.first < 0) cnt_uk[x.second.first][x.second.second] -= freq[-x.first];
			else cnt_uk[x.second.first][x.second.second] += freq[x.first];
		}
		query[i].clear();
	}
	for (int i = 0; i < q; ++i) {
		for (int j = 0; j < 3; ++j) maks[i] = max(maks[i], cnt_uk[i][j]);
		query[qr[i]].push_back({ql[i], {i, 0}});
	}

	memset(lst, -1, sizeof lst);
	memset(sec, -1, sizeof sec);
	
	for (int i = 0; i < n; ++i) {
		if (sec[a[i]] != -1) upd(0, 0, n - 1, sec[a[i]], -1, 1);
		if (lst[a[i]] != -1) upd(0, 0, n - 1, lst[a[i]], -1, 0);

		sec[a[i]] = lst[a[i]];
		lst[a[i]] = i;

		if (sec[a[i]] != -1) upd(0, 0, n - 1, sec[a[i]], 1, 1);
		upd(0, 0, n - 1, lst[a[i]], 1, 0);
		
		for (auto x : query[i]) {
			cnt_dif[x.second.first] = f(0, 0, n - 1, x.first, i, 0);
			cnt_2[x.second.first] = f(0, 0, n - 1, x.first, i, 1);
		}
	}
	
	for (int i = 0; i < q; ++i) {
		int len = qr[i] - ql[i] + 1;
		if (maks[i] * 2 > len) cout << "1\n";
		else if (maks[i] * 2 == len && cnt_dif[i] == 2) cout << "0\n";
		else if (maks[i] * 2 == len) cout << "1\n";
		else if (len & 1) cout << cnt_dif[i] << "\n";
		else cout << cnt_2[i] << "\n";
	}
	
	return 0;
}