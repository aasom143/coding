/*
how many numbers x exist, such that number x occurs exactly x times among numbers in range [l,r].
*/
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
struct node {
	int L, R, i;
}q[N];
int BLOCK;
bool cmp(node x, node y) {
	if(x.L/BLOCK != y.L/BLOCK) {
	// different blocks, so sort by block.
	return x.L/BLOCK<y.L/BLOCK;
	}
	// same block, so sort by R value
	return x.R < y.R;
}
int a[100005],answer=0,ans[100005];
unordered_map<int,int> ans1;

void add(int p){
	if(ans1[a[p]]==a[p])answer--;
	ans1[a[p]]++;
	if(ans1[a[p]]==a[p])answer++;
}
void remove(int p){
	if(ans1[a[p]]==a[p])answer--;
	ans1[a[p]]--;
	if(ans1[a[p]]==a[p])answer++;
}
main()
{
	//fast();
	int n,m;
	cin>>n>>m;
	for(int i=0; i<n; i++){
		cin>>a[i];
	}
	for(int i=0; i<m; i++) {
		cin>>q[i].L>>q[i].R;
		q[i].L--; q[i].R--;
		q[i].i = i;
	}
	BLOCK=sqrt(n);
	sort(q, q + m, cmp);
	int currentL = 0, currentR = -1;
	for(int i=0; i<m; i++) {
		int L = q[i].L, R = q[i].R;
		while(currentR < R) {
			add(currentR+1);
			currentR++;}
		while(currentR > R) {
			remove(currentR);
			currentR--;
		}
		while(currentL < L) {
			remove(currentL);
			currentL++;
		}
		while(currentL > L) {
			add(currentL-1);
			currentL--;
		}
		ans[q[i].i] = answer;
	}
	for(int i=0; i<m; i++)
		cout<<ans[i]<<endl;	
}
