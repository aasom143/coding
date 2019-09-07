#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define int long long int
#define N 200005
//If a vertex u is having a child v such that the earliest discovered vertex that can be reached from the vertices in the subtree rooted at v has a discovery time greater than or equal to u, then  does not have a back edge, and thus  will be an articulation point.
 
 
//It is an array of N elements which stores, for every vertex v, the discovery time of the earliest discovered vertex to which v or any of the vertices in the subtree rooted at v is having a back edge. It is initialized by INFINITY.

vector<int> g[N];
int timer,c,root;
set<int> ap;
vector<pair<int,int> >bridge;
int vis[N];
int low[N];
void dfs(int u, int p){
	vis[u] = low[u] = ++timer;
	for(auto v: g[u]){
		if(v == p) continue;
		if(vis[v]){
			low[u] = min(low[u], vis[v]);
		}
		else{
			dfs(v,u);
			low[u] = min(low[u], low[v]);
			if(vis[u] <= low[v] && u != root){
				ap.insert(u);
			}
			if(vis[u] <low[v]){
				bridge.push_back({u,v});
			}
			if(u == root)
				c++;
		}
	}
}
 
main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    memset(vis,0,sizeof(vis));
	memset(low,0,sizeof(low));
    timer=0,c=0;
    for(int i=0;i<m;i++)
    {
    	int u,v;
    	cin>>u>>v;
    	g[u].pb(v);
    	g[v].pb(u);
    }
	root=0;
    dfs(root,-1);
    int articulationPoint=ap.size();
    if(c>1)
    	articulationPoint++;
    cout<<articulationPoint<<endl;
    if(c>1)
    	cout<<"0 ";
    for(auto a: ap)
    	cout<<a<<" ";
    cout<<endl;
    cout<<bridge.size()<<endl;
    sort(bridge.begin(),bridge.end());
    for(auto a: bridge)
    {
    	cout<<a.first<<" "<<a.second<<endl;
    }
 
 
return 0;
}
