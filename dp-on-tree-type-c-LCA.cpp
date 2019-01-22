#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define int long long int
#define F first
#define S second
#define mod 1000000007
#define Max 200005
const int LG = 20;
void fast(){
   ios_base::sync_with_stdio(false);
   cin.tie(0); cout.tie(0);
}
vector<int> g[Max];
//LCA begins
//1 based index
int a[Max], lvl[Max], P[Max][LG];
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

//Get the ancestor of node "u"
//which is "dis" distance above.
int getAncestor(int u, int dis){
    dis = lvl[u] - dis;
    int i, lg = 0;
    for(; (1<<lg) <= lvl[u]; lg++); lg--;

    for(i=lg; i>=0; i--){
        if (lvl[u] - (1<<i) >= dis)
            u = P[u][i];
    }

    return u;
}

//returns the distance between
//two nodes "u" and "v".
int dis(int u, int v){
    if (lvl[u] < lvl[v]) swap(u, v);
    int w = lca(u, v);
    return lvl[u] + lvl[v] - 2*lvl[w];
}

main()
{
	int i, n, q, m, j;
	int u, v;
	cin >> n;
   for(i=0;i<n-1;i++){
      cin>>u>>v;
      g[u].pb(v);
      g[v].pb(u);
	}
   for(i=0;i<LG;i++)
      for(j=0;j<n+1;j++)
         P[j][i]=-1;
	lvl[0] = -1;

	dfs(1, 0);
	for(i=1; i<LG; i++){
      for(j=1;j<n+1;j++){
         if (P[j][i-1] != -1)
          P[j][i] = P[P[j][i-1]][i-1];
      }
	}
   //cout<<lca(5,2)<<" "<<lca(5,7)<<endl;
   //cout<<dis(5,2)<<" "<<lca(5,7)<<endl;
	return 0;
}
/*
8
1 2
1 3
1 4
3 5
3 7
4 6
6 8
*/
