#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define mod 1000000007
#define int long long int
#define N 100005
void fast(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
int tree[4*N];
int a[N];

void build(int node, int start, int end)
{
    if(start == end){
        tree[node] = a[start];
    }
    else{
        int mid = (start + end) / 2;
        build(2*node, start, mid);
        build(2*node+1, mid+1, end);
        tree[node] = tree[2*node] + tree[2*node+1];
    }
}

void update(int node, int start, int end, int idx, int val)
{
    if(start == end){
        a[idx] += val;
        tree[node] += val;
    }
    else{
        int mid = (start + end) / 2;
        if(start <= idx and idx <= mid){
            update(2*node, start, mid, idx, val);
        }
        else{
            update(2*node+1, mid+1, end, idx, val);
        }
        tree[node] = tree[2*node] + tree[2*node+1];
    }
}

int query(int node, int start, int end, int l, int r)
{
    if(r < start or end < l){
        return 0;
    }
    if(l <= start and end <= r){
        return tree[node];
    }
    int mid = (start + end) / 2;
    int p1 = query(2*node, start, mid, l, r);
    int p2 = query(2*node+1, mid+1, end, l, r);
    return (p1 + p2);
}

main()
{
    fast();
}

// 29 september 2019 div2 A
