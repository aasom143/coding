#include<bits/stdc++.h>
using namespace std;
string div(string number) 
{ 
    int divisor=2;
    string ans; 
    int idx = 0; 
    int temp = number[idx] - '0'; 
    while (temp < divisor) 
    temp = temp * 10 + (number[++idx] - '0'); 
    while (number.size() > idx) 
    { 
        ans += (temp / divisor) + '0'; 
        temp = (temp % divisor) * 10 + number[++idx] - '0'; 
    } 
   // cout<<ans<<endl;
    if (ans.length() == 0) 
        return "0"; 
    return ans; 
} 
string s1="";
void fn(string str){
   int n=str.length();
   int x=str[n-1]-'0';
   if(x&1){ s1+='1'; ;str[n-1]= str[n-1]-1;}
   else s1+='0';
   if((x==0 || x==1) && n==1){return;}
   string rec=div(str);
   fn(rec);
}

int main() 
{ 
    string s;
    cin>>s;
    cout<<s.length()<<endl;
    fn(s);
    reverse(s1.begin(),s1.end());    
    cout<<s1.length()<<endl; // binary string
    return 0; 
}
