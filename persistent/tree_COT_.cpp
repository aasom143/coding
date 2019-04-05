#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define mod 1000000007
#define int long long int
#define debug(x) cerr<<#x<<" :: "<<x<<"\n";
#define debug2(x,y) cerr<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<"\n";
#define debug3(x,y,z) cerr<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<"\t"<<#z<<" :: "<<z<<"\n";
#define debug4(x,y,z,a) cerr<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<"\t"<<#z<<" :: "<<z<<"\t"<<#a<<" :: "<<a<<"\n";
#define debugarr(a,st,en) {cerr<<"\n"<<#a<<" :: ";for(int i=st;i<=en;++i)cerr<<a[i]<<" ";cerr<<"\n";}
void fast(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
#define Max 100001
struct Node {
    int cnt,l,r;
}tree[4*21*Max];
int root[Max]={0};
int n,q,x=0;
int build(int start,int end){
    x++;
    int node=x;
    if(start==end){
        return node;
    }
    int mid=(start+end)/2;
    tree[node].cnt=0;
    tree[node].l=build(start,mid);
    tree[node].r=build(mid+1,end);
    return node;
}
int update(int start,int end,int par,int val){
    x++;
    int node=x;
    if(start==end){
        tree[node].cnt=tree[par].cnt+1;
        return node;
    }
    tree[node].l=tree[par].l;
    tree[node].r=tree[par].r;
    int mid=(start+end)/2;
    if(val<=mid) tree[node].l=update(start,mid,tree[par].l,val);
    else tree[node].r=update(mid+1,end,tree[par].r,val);
    tree[node].cnt=tree[tree[node].l].cnt+tree[tree[node].r].cnt;
    return node;
}
int query(int start,int end,int nodeu,int nodev,int lca,int lca_par,int k){
    if(start==end)return start;
    int mid=(start+end)/2;

    int count=tree[tree[nodeu].l].cnt+tree[tree[nodev].l].cnt-tree[tree[lca].l].cnt-tree[tree[lca_par].l].cnt;
    if(count>=k){
        return query(start,mid,tree[nodeu].l,tree[nodev].l,tree[lca].l,tree[lca_par].l,k);
    }
    else{
        return query(mid+1,end,tree[nodeu].r,tree[nodev].r,tree[lca].r,tree[lca_par].r,k-count);
    }

}
const int LG = 20;
vector<int> g[Max];
map<int,int> M;
int a[Max], lvl[Max], P[Max][LG];
void dfs1(int u,int p){
    root[u]=update(1,n,root[p],M[a[u]]);
    for(auto v:g[u]){
        if(v!=p){
            dfs1(v,u);
        }
    }
}
void dfs(int u, int par){
    lvl[u] = 1+lvl[par];
    P[u][0] = par;
    for(int i=0;i<g[u].size();i++){
        int v=g[u][i];
        if (v == par) continue;
        dfs(v, u);
    }
}
int lca(int u, int v){
    int i, lg;
    if (lvl[u] < lvl[v]) swap(u, v);

    for(lg = 0; (1<<lg) <= lvl[u]; lg++);
    lg--;

    for(i=lg; i>=0; i--){
        if (lvl[u] - (1<<i) >= lvl[v])
            u = P[u][i];
    }

    if (u == v)
        return u;

    for(i=lg; i>=0; i--){
        if (P[u][i] != -1 and P[u][i] != P[v][i])
            u = P[u][i], v = P[v][i];
    }

    return P[u][0];
}
main()
{
    fast();
    scanf("%lld%lld",&n,&q);
    vector<int> vv;
    for(int i=1;i<=n;i++){
        // cin>>a[i];
        scanf("%lld",&a[i]);
        vv.pb(a[i]);
    }
    sort(vv.begin(),vv.end());
    for(int i=0;i<vv.size();i++){
        M[vv[i]]=i+1;
    }
    for(int i=1;i<=n-1;i++){
        int u,v;
        // cin>>u>>v;
        scanf("%lld%lld",&u,&v);
        g[u].pb(v);
        g[v].pb(u);

    }
    for(int i=0;i<LG;i++)
      for(int j=0;j<n+1;j++)
         P[j][i]=-1;
    lvl[0] = -1;
    dfs(1, 0);
    dfs1(1,0);
    for(int i=1; i<LG; i++){
      for(int j=1;j<n+1;j++){
         if (P[j][i-1] != -1)
          P[j][i] = P[P[j][i-1]][i-1];
      }
    }
    while(q--){
        int u,v,k;
        // cin>>u>>v>>k;
        scanf("%lld%lld%lld",&u,&v,&k);
        int lca1=lca(u,v);
        int ans=vv[query(1,n,root[u],root[v],root[lca1],root[P[lca1][0]],k)-1];
        printf("%lld\n",ans);
    }
}

