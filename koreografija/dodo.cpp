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

const int N=5010,MOD=1e9+7,M=1<<13;
const char en='\n';
const ll LLINF=1ll<<60;
const bool DEB=0;

int n,cq,comp,cinv[N][N],seg[M*2+10],stp[N],odg[N];

void upd(int i,int x)
{
	for (i+=M;i;i/=2) seg[i]+=x;
}

int ge(int l,int r,int lo=0,int hi=M,int i=1)
{
	if (lo>=l && hi<=r) return seg[i];
	if (lo>=r || hi<=l) return 0;
	int mid=(lo+hi)/2;
	return ge(l,r,lo,mid,i*2)+ge(l,r,mid,hi,i*2+1);
}

void calcInv()
{
	for (int i=0;i<n;++i)
	{
		memset(seg,0,sizeof(seg));
		int pa=0;
		for (int j=i;j<n;++j)
		{
			pa+=ge(stp[j],M);
			cinv[i][j]=pa%2;
			upd(stp[j],1);
		}
	}
}

int qu(int l,int r)
{
	++cq;
	//cout<<l<<' '<<r<<endl;
	assert(l>=0 && r<n && l<=r);
	if (DEB)
	{
		return cinv[l][r];
	}
	else
	{
		cout<<"? "<<l+1<<' '<<r+1<<endl;
		int x;
		cin>>x;
		return x;
	}
}

bool cmp(int l,int r)
{
	if (l==r) return 0;
	if (l>r) return !cmp(r,l);
	if (l+1==r) return !qu(l,r);
	return !(qu(l,r)^qu(l+1,r)^qu(l,r-1)^qu(l+1,r-1));
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	n=1000;
	if (DEB)
	{
		for (int i=0;i<n;++i) stp[i]=i;
		random_shuffle(stp,stp+n);
		calcInv();
	}
	vi an;
	for (int i=0;i<n;++i) an.pb(i);
	stable_sort(all(an),cmp);
	for (int i=0;i<n;++i) odg[an[i]]=i+1;
	cout<<"!";
	for (int i=0;i<n;++i) cout<<' '<<odg[i];
	cout<<endl;
	if (DEB)
	{
		for (int i=0;i<n;++i) cout<<stp[i]+1<<' ';
		cout<<endl;
		for (int i=0;i<n;++i) if (stp[i]+1!=odg[i]) cout<<i<<" wrong"<<endl;
		cout<<cq<<" queries"<<endl;
	}
}
