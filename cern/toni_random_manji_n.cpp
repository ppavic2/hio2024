#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

const int N = 1e5 + 2;
const int K = 25;
const int OFF = 1 << 18;

int n, q, a[N];
int ql[N], qr[N], freq[N], cnt_uk[N][K];
int maks[N], cnt_dif[N], cnt_2[N];

int tour[OFF][2], lst[N], sec[N];

vector<int> vq, tour2[OFF];
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

void merge(vector<int>& v, vector<int> L, vector<int>& R) {
	int pl = 0, pr = 0;
	while (pl < (int)L.size() && pr < (int)R.size() && (int)v.size() < K) {
		if (L[pl] < R[pr]) v.push_back(L[pl++]);
		else if (L[pl] > R[pr]) v.push_back(R[pr++]);
		else {
			v.push_back({L[pl++]});
			++pr;
		}
	}
	while (pl < (int)L.size() && (int)v.size() < K) v.push_back(L[pl++]);
	while (pr < (int)R.size() && (int)v.size() < K) v.push_back(R[pr++]);
}

void con(int x, int l, int r) {
	if (l == r) {
		tour2[x] = {a[l]};
		return ;
	}
	int mid = (l + r) >> 1;
	con(x * 2 + 1, l, mid);
	con(x * 2 + 2, mid + 1, r);
	merge(tour2[x], tour2[x * 2 + 1], tour2[x * 2 + 2]);
}
void calc(int x, int l, int r, int ql, int qr) {
	if (ql > r || l > qr) return ;
	if (ql <= l && r <= qr) {
		merge(vq, vq, tour2[x]);
		return ;
	}
	int mid = (l + r) >> 1;
	calc(x * 2 + 1, l, mid, ql, qr);
	calc(x * 2 + 2, mid + 1, r, ql, qr);
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
		calc(0, 0, n - 1, ql[i], qr[i]);
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
		for (int j = 0; j < K; ++j) maks[i] = max(maks[i], cnt_uk[i][j]);
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
