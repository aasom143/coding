#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define mod 1000000007
#define int long long int
main()
{
		int q;
      int block=500; // size of block
      int last=200; // no of block
		// i/blcok == i ka block no
      map<int,int> m[last+5];
      for(int i=0;i<15;i++)
      {
         m[i/block][515]++;
      }
      while(q--)
      {
			int l,r;
			cin>>l>>r;
         int l_b=l/block; // block no of l
         int r_b=r/block; // block no of r
			int l_i=l_b*block; // no of elements before l_b th block
			int r_i=r_b*block; // no of elements before r_b th block
         if(l_b!=r_b){ // if l and r exits more than 1 block
            for(int i=l_i;i<block+l_i;i++)
            {
               // all elements of l_b th block
					if(i>=l&&i<=r){
						// here some elements of l_bth block
					}
            }
            for(int i=l_b+1;i<=r_b-1;i++)
            {
               // all block in range of l to r
					// except l_b th anfd r_b th blocks
            }
            for(int i=r_i;i<=block+r_i;i++)
            {
               if(i>=l&&i<=r){

					}
            }
         }
         else{ // if l and r exits in only one block
				for(int i=l_i;i<block+l_i;i++)
            {
					if(i>=l&&i<=r){

					}
            }
         }
      }
	return 0;
}
