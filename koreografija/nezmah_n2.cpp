#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;
typedef vector <int> vi;

const int MAXN = 1050;

int n;
int p[MAXN], ans[MAXN][MAXN];

bool pitaj (int lo, int hi) {
    cout << "? " << lo << " " << hi << endl;
    int res;
    cin >> res;
    return res;
}

bool cmp (int i, int j) {
    if (j - i == 1) return ans[i][j];
    return (ans[i][j] + ans[i + 1][j] + ans[i][j - 1] + ans[i + 1][j - 1]) % 2;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    n = 1000;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            ans[i][j] = pitaj(i, j);
        }
    }
    p[1] = 1;
    for (int j = 2; j <= n; j++) {
        int cnt = 0;
        for (int i = 1; i < j; i++) {
            if (cmp(i, j)) {
                p[i]++;
            } else {
                cnt++;
            }
        }
        p[j] = cnt + 1;
    }
    cout << "! ";
    for (int i = 1; i <= n; i++) {
        cout << p[i] << " ";
    }
    cout << endl;
    return 0;
}
