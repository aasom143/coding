https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1620

#include <bits/stdc++.h>
using namespace std; 
#define pb push_back
#define mp make_pair
const int MAXS = 1000005; 
const int MAXC = 30;
int out[MAXS];
int f[MAXS];
map<int,int> g[MAXS];
int state=1;
void add_str(int pos,string s) 
{
	int curs=0;
	for(int i=0;i<s.length();i++){
		int ch=s[i];
		if(g[curs].find(ch)==g[curs].end()) g[curs][ch]=state++;
		curs=g[curs][ch];
	}
	out[pos]=curs;
}
void suffix_link(){
	memset(f,-1,sizeof(f));
	queue<int> q;
	for(auto it:g[0]){
		f[it.second]=0;
		q.push(it.second);
	}
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
			int i=it.first;
			int slink=f[st];
			while(g[slink].find(i)==g[slink].end()){
				slink=f[slink];
			}
			slink=g[slink][i];
			f[g[st][i]]=slink;
			q.push(g[st][i]);
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
int dp[MAXS];
void fun(int state){
	if(state==0)return ;
	if(dp[state]!=-1)return ;
	fun(f[state]);
	dp[state]=1;
	ans[state]=1;
	return ;
}
int main() 
{ 
	int t;
	cin>>t;
	while(t--){
		string text;
		cin>>text;
		int k;
		cin>>k;
		string arr[k+5];
		for(int i=0;i<k;i++)cin>>arr[i];
		for(int i=0;i<k;i++) 
			add_str(i,arr[i]);
		suffix_link();
		searchWords(text); 
		memset(dp,-1,sizeof(dp));
		for(int i=0;i<state;i++){
			if(ans[i]==1&&dp[i]==-1){
				fun(i);
			}
		}
		for(int i=0;i<k;i++){
			if(ans[out[i]]==1)cout<<"y"<<endl;
			else cout<<"n"<<endl;
		}
		for(int i=0;i<=state;i++)g[i].clear();
	}
	
	return 0; 
} 
