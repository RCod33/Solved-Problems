//!----LIBRERIAS---------------------------------------------------------------------------------------
//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <math.h>
//#include <memory.h>
//#include <set>
//#include <map>
//#include <queue>
//#include <stack>
#include <bits/stdc++.h>

//!----MACROS------------------------------------------------------------------------------------------
#define loop(i,a,b) for(int i=a;i<b;i++)
#define rloop(k,a,b) for(int k=a;k>b;k--)
#define vvi vector<vector<long long>>
#define vii vector<vector<pair<long long,long long>>>
#define vi vector <long long>
#define ii pair <long long, long long>
#define pb(a) push_back(a)
#define mk(a,b) make_pair(a,b)
#define all(x) x.begin(),x.end()
#define sz(x) ((x).size())
#define sza(x) sizeof(x)/sizeof(x[0])
#define fi first
#define se second
#define mid (l+r)/2
#define left node*2,l,mid
#define right node*2+1,mid+1,r
#define mset(a,b) memset(a,b,sizeof(a))
#define IOS_B ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
const int mod = 1e8 + 7;

using namespace std;
//!----Globales----------------------------------------------------------------------------------------



//!----FUNCIONES---------------------------------------------------------------------------------------

vvi mult(vvi& a, vvi& b){
	vvi c(4, vi(4, 0));
	
	for(int i = 0; i<2; ++i){
		for(int j = 0; j<2; ++j){
			for(int k = 0; k<2; ++k){
				c[i][j] = ((c[i][j]%mod) + ((a[i][k]%mod)*(b[k][j]%mod)))%mod;
			}
		}
	}
	
	return c;
}

vvi binpow(vvi& mx, long long m){
	if(m == 1)
		return mx;
	
	vvi half = binpow(mx, m/2);
	
	if(m%2 == 0)
		return mult(half, half);
	else{
		vvi si = mult(half, half);
		return mult(si, mx);
	}
}


//!----MAIN--------------------------------------------------------------------------------------------
int main(){
IOS_B;

	int t;
	cin>>t;
	
	while(t--){
		long long n;
		cin>>n;
		
		vvi fibo = {{1,1}, {1,0}};
		
		fibo = binpow(fibo, n);
		
		cout<<fibo[0][0]<<"\n";
	}	
	
				
return 0;
}