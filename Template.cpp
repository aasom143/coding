#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define mod 1000000007
#define int long long int
#define ff first
#define ss second
int power(int n,int q){
    int ans=1;
    n%=mod;
    while(q>0){
        if(q&1)
        ans=(ans*n)%mod;
        n=(n*n)%mod;
        q>>=1;
    }
    return ans%mod;
}
void fast(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
// Geetha Govindam
//cin >> ws;
//string st;
//getline(cin,st); 
//scanf(" %[^\n]s,s);
main()
{
	int t=10;
	fast();t=1;
	cin>>t;
	while(t--){

	}
}
