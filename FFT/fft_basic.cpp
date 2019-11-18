// https://codeforces.com/contest/1096/problem/G
#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define mod 1000000007
#define int long long int
void fast(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
 
int N,K;
int ok[10];
 
int mo=998244353;
int modpow(int a, int n = mo-2) {
	int r=1;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}
vector<int> fft(vector<int> v, bool rev=false) {
	int n=v.size(),i,j,m;
	
	for(i=0,j=1;j<n-1;j++) {
		for(int k=n>>1;k>(i^=k);k>>=1);
		if(i>j) swap(v[i],v[j]);
	}
	for(int m=2; m<=n; m*=2) {
		int wn=modpow(5,(mo-1)/m);
		if(rev) wn=modpow(wn);
		for(i=0;i<n;i+=m) {
			int w=1;
			for(int j1=i,j2=i+m/2;j2<i+m;j1++,j2++) {
				int t1=v[j1],t2=w*v[j2]%mo;
				v[j1]=t1+t2;
				v[j2]=t1+mo-t2;
				while(v[j1]>=mo) v[j1]-=mo;
				while(v[j2]>=mo) v[j2]-=mo;
				w=w*wn%mo;
			}
		}
	}
	if(rev) {
		int rv = modpow(n);
		for(int i=0;i<n;i++) v[i]=v[i]*rv%mo;
	}
	return v;
}
 
vector<int> MultPoly(vector<int> P,vector<int> Q,bool resize=false) {
	if(resize) {
		int maxind=0,pi=0,qi=0,i;
		int s=2;
		for(int i=0;i<P.size();i++) if(P[i]) pi=i;
		for(int i=0;i<Q.size();i++) if(Q[i]) qi=i;
		maxind=pi+qi+1;
		while(s*2<maxind) s*=2;
		P.resize(s*2);Q.resize(s*2);
	}
	P=fft(P), Q=fft(Q);
	for(int i=0;i<P.size();i++) P[i]=P[i]*Q[i]%mo;
	return fft(P,true);
}
 
 
 
main() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	vector<int> V(10);
	for(int i=0;i<K;i++) {
		cin>>x;
		V[x]=1;
	}
	
	x=N/2;
	vector<int> R(1,1);
	while(x) {
		if(x%2) R=MultPoly(R,V,true);
		x/=2;
		if(x) V=MultPoly(V,V,true);
	}
	
	int ret=0;
	for(int i=0;i<R.size();i++) ret+=R[i]*R[i]%mo;
	cout<<ret%mo<<endl;
}
