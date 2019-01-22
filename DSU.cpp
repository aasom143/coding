#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define int long long int
#define F first
#define S second
#define mod 1000000007
#define Max 200005
void fast(){
   ios_base::sync_with_stdio(false);
   cin.tie(0); cout.tie(0);
}
void ini(){
   for(int i=0;i<=Max;i++)
      arr[i]=i;
}
int root(int i){
   if(arr[i]==i)return i;
   return arr[i]=find(a[i]);
}
void union1(int x,int y,int val)
{
   int xx=root(x);
   int yy=root(y);
   if(xx!=yy){
      ans+=val;
      arr[xx]=yy;
   }
   else {
      // have cycle
   }
}
main() {
   fast();

}
