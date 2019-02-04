// Find the number from the range [a, b] which has the maximum product of the digits.
// two positive integers a and b (1 ≤ a ≤ b ≤ 1018)
#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define mp make_pair
#define pb push_back
int dp[20][2][2][2][2];
vector<int> num,num1;
int call(int pos,int fl,int fr,int pp,int pow1){
	if(pos==num.size()){
		dp[pos][fl][fr][pp][1]=0;
		return 1;
	}
	if(dp[pos][fl][fr][pp][0]!=-1)return dp[pos][fl][fr][pp][0];
	int min1=0,max1=9,res=0,res2=0;
	if(fl==0)min1=num1[pos];
	if(fr==0)max1=num[pos];
	for(int i=min1;i<=max1;i++){
		int nfl=fl,nfr=fr;
		if(i>num1[pos])nfl=1;
		if(i<num[pos])nfr=1;
		int npp=pp;
		if(pp==0&&i==0)npp=0;
		else npp=1;
		if(npp==0){
			int res1=call(pos+1,nfl,nfr,npp,pow1/10);
			if(res1>=res){
				res=res1;
				res2=dp[pos+1][nfl][nfr][npp][1];
			}
		}
		else {
			int res1=i*call(pos+1,nfl,nfr,npp,pow1/10);
			if(res1>=res){
				res=res1;
				res2=pow1*i+dp[pos+1][nfl][nfr][npp][1];
			}
		}
	}
	dp[pos][fl][fr][pp][1]=res2;
	return dp[pos][fl][fr][pp][0]=res;
}
int solve(int b,int a){
	memset(dp,-1,sizeof(dp));
	num.clear();
	num1.clear();
	while(b>0){
		num.pb(b%10);
		num1.pb(a%10);
		a/=10;
		b/=10;
	}
	reverse(num.begin(),num.end());
	reverse(num1.begin(),num1.end());
	int res=call(0,0,0,0,pow(10,num.size()-1));
	return res;
}
main()
{
	int a,b;
	cin>>a>>b;
	solve(b,a);
	cout<<dp[0][0][0][0][1]<<endl;
}
