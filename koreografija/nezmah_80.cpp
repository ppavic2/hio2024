#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;
typedef vector <int> vi;

const int MAXN = 1050;

int n, q_cnt;
int p[MAXN];

bool pitaj (int lo, int hi) {
    q_cnt++;
    cout << "? " << lo << " " << hi << endl;
    int res;
    cin >> res;
    return res;
}

bool cmp (int i, int j) {
    if (j - i == 1) return pitaj(i, j);
    return (pitaj(i, j) + pitaj(i + 1, j) + pitaj(i, j - 1) + pitaj(i + 1, j - 1)) % 2;
}

void solve (vi &v) {
    if (v.size() <= 1) return;
    vi lef, rig;
    for (int i = 0; i < (int)v.size(); i++) {
        if (2 * i < (int)v.size()) lef.push_back(v[i]); else rig.push_back(v[i]);
    }
    solve(lef);
    solve(rig);
    v.clear();
    int i = 0, j = 0;
    while (i < (int)lef.size() && j < (int)rig.size()) {
        if (!cmp(lef[i], rig[j])) {
            v.push_back(lef[i]);
            i++;
        } else {
            v.push_back(rig[j]);
            j++;
        }
    }
    while (i < (int)lef.size()) {
        v.push_back(lef[i]);
        i++;
    }
    while (j < (int)rig.size()) {
        v.push_back(rig[j]);
        j++;
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    n = 1000;
    vi v(n);
    for (int i = 0; i < n; i++) v[i] = i + 1;
    solve(v);
    for (int i = 0; i < n; i++) {
        p[v[i]] = i + 1;
    }
    while (q_cnt <= 7000000/129) {
        int res = pitaj(1, 2);
    }
    cout << "! ";
    for (int i = 1; i <= n; i++) {
        cout << p[i] << " ";
    }
    cout << endl;
    return 0;
}
