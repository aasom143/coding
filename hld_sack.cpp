// https://www.codechef.com/PILT2019/problems/IUPC123/
#include<bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
// Common file
#include <ext/pb_ds/tree_policy.hpp>
#include <functional> // for less
#include <iostream>
using namespace __gnu_pbds;
#define pb push_back
#define mp make_pair
#define mod 1000000007
#define int long long int
void fast(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
#define maxn 100005
vector<int> g[100005];
typedef tree<pair<int,int> , null_type, less<pair<int,int> >,rb_tree_tag,
tree_order_statistics_node_update> new_data_set;
new_data_set cnt;
int sz[maxn],a[maxn],n,m;
void getsz(int v, int p){
    sz[v] = 1;  // every vertex has itself in its subtree
    for(auto u : g[v])
        if(u != p){
            getsz(u, v);
            sz[v] += sz[u]; // add size of child u to its parent(v)
        }
}
bool big[maxn];
int ans[100005];
void add(int v, int p, int x){
	if(x==1){
		cnt.insert(mp(a[v],v));
	}
	else cnt.erase(cnt.find(mp(a[v],v)));
    // cnt[ col[v] ] += x;
    for(auto u: g[v])
        if(u != p && !big[u])
            add(u, v, x);
}
void dfs(int v, int p, bool keep){
    int mx = -1, bigChild = -1;
    for(auto u : g[v])
       if(u != p && sz[u] > mx)
          mx = sz[u], bigChild = u;
    for(auto u : g[v])
        if(u != p && u != bigChild)
            dfs(u, v, 0);  // run a dfs on small childs and clear them from cnt
    if(bigChild != -1)
        dfs(bigChild, v, 1), big[bigChild] = 1;  // bigChild marked as big and not cleared from cnt
    add(v, p, 1);
    //now cnt[c] is the number of vertices in subtree of vertex v that has color c. You can answer the queries easily.
    if(cnt.size()<m){
    	ans[v]=0;
    }
    else {
    	ans[v]=(cnt.find_by_order(m-1))->first;
    }
    //cout<<ans[v]<<" "<<v<<endl;
    //cout<<cnt.size()<<endl;
    if(bigChild != -1)
        big[bigChild] = 0;
    if(keep == 0)
        add(v, p, -1);
}
main()
{
	// int n,m;
	cin>>n>>m;
	for(int i=1;i<=n-1;i++){
		int u,v;
		cin>>u>>v;
		g[u].pb(v);
		g[v].pb(u);
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	getsz(1,0);
	dfs(1,0,0);
	int sum=0;
	for(int i=1;i<=n;i++){
		sum+=ans[i];
	}
	cout<<sum<<endl;
}


