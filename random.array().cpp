#include<bits/stdc++.h>
using namespace std;
#define pb push_back
int main()
{
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    mt19937_64 rng_64(chrono::steady_clock::now().time_since_epoch().count());
    uniform_int_distribution<int>(1, 1000*1000*1000)(rng);
    vector<int> permutation;
    shuffle(permutation.begin(), permutation.end(), rng);
	vector<int> ord;
	int n;
	cin>>n;
	for(int i=1; i<=n; i++) {
		ord.pb(i);
	}
	shuffle(ord.begin(), ord.end(), rng);
	for(int i=0;i<n;i++){
		cout<<ord[i]<<" ";
	}
	cout<<endl;
}
