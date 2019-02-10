/*
https://www.hackerearth.com/practice/algorithms/graphs/articulation-points-and-bridges/practice-problems/algorithm/p2-2-b370c810/
*/
#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
 
const int N=2e5+5;
const int M=2e5+5;
 
int n, m, node=1, maxdist;
int tim=0, grp=1;
int u[N], v[N], comp[N], dist[N], rev[N];
bool vis[N], vis2[N], isBridge[M];
int tin[N], tout[N], minAncestor[N];
queue<int> Q[N];
vector<pair<int, int> > g[N];
vector<int> tree[N], vertices[N]; //Tree stores Bridge Tree, vertices stores the nodes in each component 
 
void dfs(int k, int par)
{
	vis[k]=1;
	tin[k]=++tim;
	minAncestor[k]=tin[k];
	for(auto it:g[k])
	{
		if(it.first==par)
			continue;
		if(vis[it.first])
		{	
			minAncestor[k]=min(minAncestor[k], tin[it.first]);
			continue;
		}
		dfs(it.first, k);
		minAncestor[k]=min(minAncestor[k], minAncestor[it.first]);
		if(minAncestor[it.first]>tin[k])
			isBridge[it.second]=1;
	}
	tout[k]=tim;
}
 
void dfs2(int k)
{
	int comp=grp;
	Q[comp].push(k);
	vis2[k]=1;
	while(!Q[comp].empty())
	{
		int u=Q[comp].front();
		Q[comp].pop();
		vertices[comp].push_back(u);
		rev[u]=comp;
		for(auto it:g[u])
		{
			int v=it.first;
			int edgeidx=it.second;
			if(vis2[v])
				continue;
			if(isBridge[edgeidx])
			{
				grp++;
				tree[comp].push_back(grp);
				tree[grp].push_back(comp);
				dfs2(v);
			}
			else
			{
				Q[comp].push(v);
				vis2[v]=1;
			}
		}
	}
}
 
void dfs3(int k, int par, int lvl)
{
	for(auto &it:vertices[k])
		dist[it]=lvl;
	for(auto it:tree[k])
	{
		if(it==par)
			continue;
		dfs3(it, k, lvl+1);
	}
}	
 
int32_t main()
{
	IOS;
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>u[i]>>v[i];
		g[u[i]].push_back({v[i], i});
		g[v[i]].push_back({u[i], i});
	}
	dfs(1, 0);
	dfs2(1);
	dfs3(rev[n], rev[n], 0);
	int q;
	cin>>q;
	while(q--)
	{
		int u;
		cin>>u;
		if(dist[u])
			cout<<dist[u]<<endl;
		else
			cout<<"impossible"<<endl;
	}
	return 0;
}
