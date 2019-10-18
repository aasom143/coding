#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define int long long int
#define mod 1000000007
void fast(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
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
int lsum(int a,int b){
	int sum=((a%mod)+(b%mod))%mod;return sum;
}
int lsub(int a,int b){
	int sum=((a%mod)-(b%mod)+mod)%mod;return sum;
}
int lmul(int a,int b){
	int sum=((a%mod)*(b%mod))%mod;
	sum=(sum+mod)%mod;return sum;
}
int ldiv(int a,int b){
	int sum=((a%mod)*(power(b,mod-2)%mod))%mod;
	sum=(sum+mod)%mod;return sum;
}
main()
{
	fast();
}
