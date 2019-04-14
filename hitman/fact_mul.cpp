ll mul(ll a,ll b,ll mod){
    if(a==0 || b==0) return 0;
    if(a==1 || b==1) return (a*b)%mod;
    ll m=mul(a,b/2,mod);
    m=(m+m)%mod;
    if(b&1LL) return (m+a)%mod;
    return m;
}
ll expo(ll base,ll exponent,ll mod){
    ll ans=1;
    while(exponent!=0){
        if(exponent&1LL) ans=mul(ans,base,mod);
        base=mul(base,base,mod);
        exponent>>=1LL;
    }
    return ans%mod;
}
bool prime(unsigned ll p){
    if(p==2) return true;
    if(p==1 || p%2==0) return false;
    unsigned ll s=p-1;
    while(s%2==0) s/=2;
    rep(i,0,15){
        unsigned ll a=rand()%(p-1)+1,tmp=s;
        unsigned ll mod=expo(a,tmp,p);
        while(tmp!=p-1 && mod!=1 && mod!=p-1){
            mod=mul(mod,mod,p);
            tmp*=2;
        }
        if(mod!=p-1 && tmp%2==0) return false;
    }
    return true;
}
int divisors(int n){
    int ans=1;
    for(int i=2;i*i*i<=n;i++){
        if(n%i==0){
            int cnt=1;
            while(n%i==0) n/=i,cnt++;
            ans*=cnt;
        }
    }
    int d=sqrt(n);
    while(d*d<n) d++;
    if(prime(n)) ans*=2;
    else if(d*d==n and prime(d)) ans*=3;
    else if(n!=1) ans*=4;
    return ans;
}
