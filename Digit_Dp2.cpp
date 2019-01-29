/*
Let's call some positive integer classy if its decimal representation contains 
no more than 3 non-zero digits. For example, numbers 4, 200000, 10203 are 
classy and numbers 4231, 102306, 7277420000 are not.
You are given a segment [L;R]. Count the number of classy integers x such that  L≤x≤R ;1<=L<=R<=1e18
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define mp make_pair
#define pb push_back
int dp[20][10][2];
vector<int> num;
int call(int pos,int cnt,int f){
	if(cnt>3)return 0;
	if(pos==num.size()){
		if(cnt<=3)return 1;
		return 0;
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
		if(i==0)
		res=res+call(pos+1,cnt,nf);
		else res=res+call(pos+1,cnt+1,nf);
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
	int t;
	cin>>t;
	while(t--){
		int a,b;
		cin>>a>>b;
		int ans=solve(b)-solve(a-1);
		cout<<ans<<endl;
	}
}
