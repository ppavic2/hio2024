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

const int N=500010,MOD=1e9+7,M=1<<19;
const char en='\n';
const ll LLINF=1ll<<60;

int n,q,ql[N],qr[N],h[N],pros[N],cn1[N],cn2[N],seg1[M*2+10],seg2[M*2+10];
vi im[N];
pii seg[M*2+10];
vector<pair<pii,int>> imq[N];

pii mer(pii a,pii b)
{
	if (a.x!=b.x)
	{
		if (a.y>b.y) return {a.x,a.y-b.y};
		else return {b.x,b.y-a.y};
	}
	return {a.x,a.y+b.y};
}

pii ge(int l,int r,int lo=0,int hi=M,int i=1)
{
	if (lo>=l && hi<=r) return seg[i];
	if (lo>=r || hi<=l) return {0,0};
	int mid=(lo+hi)/2;
	return mer(ge(l,r,lo,mid,i*2),ge(l,r,mid,hi,i*2+1));
}

void upd1(int i,int x)
{
	for (i+=M;i;i/=2) seg1[i]+=x;
}

void upd2(int i,int x)
{
	for (i+=M;i;i/=2) seg2[i]+=x;
}

int ge1(int l,int r,int lo=0,int hi=M,int i=1)
{
	if (lo>=l && hi<=r) return seg1[i];
	if (lo>=r || hi<=l) return 0;
	int mid=(lo+hi)/2;
	return ge1(l,r,lo,mid,i*2)+ge1(l,r,mid,hi,i*2+1);
}

int ge2(int l,int r,int lo=0,int hi=M,int i=1)
{
	if (lo>=l && hi<=r) return seg2[i];
	if (lo>=r || hi<=l) return 0;
	int mid=(lo+hi)/2;
	return ge2(l,r,lo,mid,i*2)+ge2(l,r,mid,hi,i*2+1);
}

int getCn(int l,int r,int x)
{
	return upper_bound(all(im[x]),r)-lower_bound(all(im[x]),l);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>q;
	for (int i=1;i<=n;++i)
	{
		cin>>h[i];
		if (im[h[i]].empty()) pros[i]=0;
		else pros[i]=im[h[i]].back();
		im[h[i]].pb(i);
	}
	for (int i=0;i<q;++i)
	{
		cin>>ql[i]>>qr[i];
		imq[ql[i]-1].pb({{ql[i],i},-1});
		imq[qr[i]].pb({{ql[i],i},1});
	}
	for (int i=1;i<=n;++i)
	{
		upd1(pros[i],1);
		upd2(pros[pros[i]],1);
		for (auto x: imq[i])
		{
			cn1[x.x.y]+=x.y*ge1(0,x.x.x);
			cn2[x.x.y]+=x.y*ge2(0,x.x.x);
		}
	}
	for (int i=1;i<=n;++i) seg[i+M]={h[i],1};
	for (int i=M-1;i;--i) seg[i]=mer(seg[i*2],seg[i*2+1]);
	for (int i=0;i<q;++i)
	{
		int maj=ge(ql[i],qr[i]+1).x;
		int len=qr[i]-ql[i]+1;
		int majCn=getCn(ql[i],qr[i],maj);
		if (majCn*2>len)
		{
			cout<<1<<en;
			continue;
		}
		if (len%2==1)
		{
			cout<<cn1[i]<<en;
			continue;
		}
		int majCan1=h[ql[i]],majCan2=ge(ql[i]+1,qr[i]+1).x;
		int can1Cn=getCn(ql[i],qr[i],majCan1),can2Cn=getCn(ql[i],qr[i],majCan2);
		if (can1Cn*2==len || can2Cn*2==len)
		{
			if (can1Cn*2==len && can2Cn*2==len && majCan1!=majCan2) cout<<0<<en;
			else cout<<1<<en;
		}
		else cout<<cn2[i]-cn1[i]<<en;
	}
}
