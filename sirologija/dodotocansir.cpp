#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using vi=vector<int>;
using vl=vector<ll>;
#define pb push_back
#define all(a) begin(a),end(a)

const int N=5010,MOD=1e9+7;
const char en='\n';
const ll LLINF=1ll<<60;

int n,m,dp[N][N];
bool bio[N],bio3[N],bio4[N];
string h[N];
vi ch[N],rch[N],ord,ccomp;

void dfs1(int i)
{
	bio[i]=1;
	for (auto x: ch[i]) if (!bio[x]) dfs1(x);
	ord.pb(i);
}

void dfs2(int i)
{
	bio[i]=1;
	ccomp.pb(i);
	for (auto x: rch[i]) if (!bio[x]) dfs2(x);
}

void dfs3(int i)
{
	bio3[i]=1;
	for (auto x: ch[i]) if (!bio3[x]) dfs3(x);
}

void dfs4(int i)
{
	bio4[i]=1;
	for (auto x: rch[i]) if (!bio4[x]) dfs4(x);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for (int i=0;i<n;++i) cin>>h[i];
	vector<pii> v;
	for (int i=0;i<n;++i) for (int j=0;j<m;++j) if (h[i][j]=='#') v.pb({i,j});
	int vs=v.size();
	for (int i=0;i<vs;++i) for (int j=0;j<vs;++j) if (i!=j)
	{
		if (v[i].x<=v[j].x+1 && v[i].y+1>=v[j].y) ch[i].pb(j),rch[j].pb(i);
	}
	for (int i=0;i<vs;++i) if ((v[i].y==0 || v[i].x==n-1) && !bio3[i]) dfs3(i);
	for (int i=0;i<vs;++i) if ((v[i].x==0 || v[i].y==m-1) && !bio4[i]) dfs4(i);
	for (int i=0;i<vs;++i) if (bio3[i] && bio4[i])
	{
		cout<<0<<en;
		exit(0);
	}
	for (int i=0;i<vs;++i) if (bio3[i] || bio4[i]) bio[i]=1;
	for (int i=0;i<vs;++i) if (!bio[i]) dfs1(i);
	memset(bio,0,sizeof(bio));
	reverse(all(ord));
	int cn=1;
	for (auto x: ord) if (!bio[x])
	{
		++cn;
		ccomp.clear();
		dfs2(x);
	}
	cout<<cn<<en;
}
