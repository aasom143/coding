// https://www.hackerearth.com/challenges/college/code-warz-prosang-mnnit/algorithm/bohot-easy-problem/submission/25223547/

#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <string>
#include <vector>
 
#define FileIn(file) freopen(file".inp", "r", stdin)
#define FileOut(file) freopen(file".out", "w", stdout)
#define FOR(i, a, b) for (int i=a; i<=b; i++)
#define REP(i, n) for (int i=0; i<n; i++)
#define Fill(ar, val) memset(ar, val, sizeof(ar))
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long
#define all(ar) ar.begin(), ar.end()
#define pb push_back
#define bit(n) (1<<(n))
#define Last(i) ( i & -i )
#define INF 500000000
#define maxN 10001
using namespace std;
 
int n, deg[maxN];
int sum, left_sum[maxN];
bool valid;
int deg1[1001];
bool cmp(int a, int b) { return a > b; }
 
int search(int L, int R, int k) {
    int rs = L - 1;
    while (L <= R) {
        int mid = (L + R) >> 1;
        if (deg[mid] >= k) {
            rs = mid;
            L = mid + 1;
        }
        else R = mid - 1;
    }
    return rs;
}
 
bool solve() {
    if (!valid) return false;
    if (sum & 1) return false;
    sort(deg + 1, deg + n + 1, cmp);
    left_sum[n + 1] = 0;
    for (int i = n; i >= 1; i--)
        left_sum[i] = left_sum[i + 1] + deg[i];
    int left = 0, right;
    FOR (k, 1, n) {
        int p = search(k + 1, n, k);
        left += deg[k];
        right = k * (p - 1) + left_sum[p + 1];
        if (left > right) return false;
    }
    return true;
}
 
main() {
 //   FileIn("test"); FileOut("test");
    cin>>n;
    for(int i=1;i<=n+1;i++){
        cin>>deg1[i];
    }
    vector<int> v;
    for(int i=1;i<=n+1;i++){
        valid = true;
        sum = 0;
        int k=1;
        for(int j=1;j<=n+1;j++){
            if(j!=i){
                deg[k++]=deg1[j];
            if (!valid) continue;
            if (deg1[j] >= n || deg1[j] < 0) valid = false;
                sum += deg1[j];
            }
        }
        if(solve()){
            v.pb(i);
        }
    }
    cout<<v.size()<<endl;
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<endl;
    }
}
