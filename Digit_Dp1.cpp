//calculate the sum of the digits of numbers 1 through n.
#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define mp make_pair
#define pb push_back
int dp[12][102][2];
vector<int> num;
int call(int pos,int cnt,int f){
	if(pos==num.size()){
		return cnt;
	}
	if(dp[pos][cnt][f]!=-1)return dp[pos][cnt][f];
	int lmt;
	if(f==0){
		lmt=num[pos];
	}
	else lmt=9;
	int res=0;
	for(int i=0;i<=lmt;i++){
		int nf=f;
		if(f==0&&i<lmt)nf=1;
		res=res+call(pos+1,cnt+i,nf);
	}
	return dp[pos][cnt][f]=res;
}
int solve(int b){
	memset(dp,-1,sizeof(dp));
	num.clear();
	while(b>0){
		num.pb(b%10);
		b/=10;
	}
	reverse(num.begin(),num.end());
	int res=call(0,0,0);
	return res;
}
main()
{
	int a,b;
	cin>>a>>b;
	while(a!=-1&&b!=-1){
	int ans=solve(b)-solve(a-1);
	cout<<ans<<endl;
	cin>>a>>b;
	}
}
