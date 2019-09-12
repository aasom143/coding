// https://codeforces.com/gym/101174/attachments

#include <bits/stdc++.h>
using namespace std; 
#define pb push_back
#define mp make_pair
#define int long long int
#define mod 1000003
const int MAXS = 1005; 
int out[MAXS];
int f[MAXS];
map<int,int> g[MAXS];
int state=1;
void add_str(int pos,string s) 
{
	int curs=0;
	for(auto ch: s){
		if(g[curs].find(ch)==g[curs].end()) 
			g[curs][ch] = state++;
		curs = g[curs][ch];
	}
	out[curs]=1;
}
void suffix_link(){
	memset(f,-1,sizeof(f));
	queue<int> q;
	for(int i=0;i<256;i++){
		if(g[0].find(i)!=g[0].end()){
			f[g[0][i]]=0;
			q.push(g[0][i]);
		}
		else g[0][i]=0;
	}
	while(q.size()){
		int st=q.front();
		q.pop();
		for(auto it:g[st]){
			int u=it.second;
			int ch=it.first;
			int slink=f[st];
			while(g[slink].find(ch)==g[slink].end()){
				slink=f[slink];
			}
			f[u]=g[slink][ch];
			out[u]|=out[f[u]];
			q.push(u);
		}
	}
}
int findNextState(int curs, char nextInput) 
{ 
	int st = curs; 
	int ch = nextInput; 
	while (g[st].find(ch)==g[st].end()) 
		st = f[st];
	return g[st][ch]; 
} 
int ans[MAXS]={0};
void searchWords(string text) 
{
	int curs = 0;
	for (int i = 0; i < text.length(); ++i) 
	{ 
		// cout<<g[curs][text[i]-'a']<<"endl";
		curs = findNextState(curs, text[i]); 
		// cout<<curs<<endl;
		ans[curs]=1;
	} 
} 
int dp[22][1005][2][2][2];
int n,m,k;
string str;
string s1="abcdefghijklmnopqrstuvwxyz";
string s2="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
string s3="0123456789";	
 
int fun(int pos,int state,int fa,int fA,int f0){
	if(out[state]==1)return 0;
	if(pos==0){
		if(fa==1&&fA==1&&f0==1)return 1;
		return 0;
	}
	int res=dp[pos][state][fa][fA][f0];
	if(res!=-1)return res;
	res=0;
	for(int i=0;i<s1.length();i++){
		res+=fun(pos-1,findNextState(state,s1[i]),1,fA,f0);
		res%=mod;
	}
	for(int i=0;i<s2.length();i++){
		res+=fun(pos-1,findNextState(state,s1[i]),fa,1,f0);
		res%=mod;
	}
	for(int i=0;i<10;i++){
		if(i==0){
			res+=fun(pos-1,findNextState(state,'o'),fa,fA,1);
		}
		else if(i==1){
			res+=fun(pos-1,findNextState(state,'i'),fa,fA,1);
		}
		else if(i==3){
			res+=fun(pos-1,findNextState(state,'e'),fa,fA,1);
		}
		else if(i==5){
			res+=fun(pos-1,findNextState(state,'s'),fa,fA,1);
		}
		else if(i==7){
			res+=fun(pos-1,findNextState(state,'t'),fa,fA,1);
		}
		else res+=fun(pos-1,0,fa,fA,1);  
		res%=mod;
	}
	res%=mod;
	dp[pos][state][fa][fA][f0]=res;
	return res;
}
 main() 
{ 
	int t;
	// cin>>t;
	t=1;
	while(t--){
		int aa,bb;
		cin>>aa>>bb>>k;
		string arr[k+5];
		for(int i=0;i<k;i++)cin>>arr[i];
		for(int i=0;i<k;i++) 
			add_str(i,arr[i]);
		suffix_link();
		// searchWords(text); 
		int aaa=0;
		memset(dp,-1,sizeof(dp));
		for(int i=aa;i<=bb;i++){
			m=i;
			aaa+=fun(i,0,0,0,0);
			aaa%=mod;
			// cout<<fun(0,0,0,0,0)<<endl;
		}
		cout<<aaa<<endl;
		// for(int i=0;i<=state;i++)g[i].clear();
	}
	
	return 0; 
} 
