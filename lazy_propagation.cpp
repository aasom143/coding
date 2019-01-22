#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define nodes 400005
int a[nodes]={0};
int tree[4*nodes]={0};
int lazy[4*nodes] = {0};
vector<pair<int,int> > v[100005];
vector<int> g[100005];
int ans[100005]={0};
void build(int node,int l,int r)
{
   if(l==r){
      tree[node]=a[l];
      lazy[node]=0;
      return ;
   }
   int mid=(l+r)/2;
   build(2*node,l,mid);
   build(2*node+1,mid+1,r);
   tree[node]=min(tree[2*node],tree[2*node+1]);
}
void add(int node,int start,int end)
{
   tree[node]+=lazy[node];
   if(start!=end){
      lazy[2*node]+=lazy[node];
      lazy[2*node+1]+=lazy[node];
   }
   lazy[node]=0;
}
int n;
void update(int node,int start,int end,int l,int r,int x)
{
   if(lazy[node]!=0){
      add(node,start,end);
   }
   if(l>end||r<start)return ;
   if(start>=l&&end<=r){
      lazy[node]+=x;
      if(lazy[node]!=0){
         add(node,start,end);
      }
   }
   else {
      int mid=(start+end)/2;
      update(2*node,start,mid,l,r,x);
      update(2*node+1,mid+1,end,l,r,x);
      tree[node]=min(tree[2*node],tree[2*node+1]);
   }
}
int query(int node,int start,int end,int l,int r)
{
   if(lazy[node]!=0){
      add(node,start,end);
   }
   if(l>end||r<start)return 1e9;
   if(start>=l&&end<=r){
      return tree[node];}
   else {
      int mid=(start+end)/2;
      int p1=query(2*node,start,mid,l,r);
      int p2=query(2*node+1,mid+1,end,l,r);
      return min(p1,p2);}
}
int main()
{
//	int n;
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	build(1,1,n);
	// continue;
}
//1: build(1,1,n);
//2: query(1,1,n,l,r);
//3: update(1,1,n,x,y,z);
