//!----LIBRERIAS---------------------------------------------------------------------------------------
#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <math.h>
//#include <memory.h>
//#include <set>
//#include <map>
//#include <queue>
//#include <stack>
//#include <string>

//!----MACROS------------------------------------------------------------------------------------------
#define loop(i,a,b) for(int i=a;i<b;i++)
#define rloop(k,a,b) for(int k=a;k>b;k--)
#define vvi vector<vector<int>>
#define vii vector<vector<pair<int,int>>>
#define vi vector <int>
#define ii pair <int,int>
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
const int mod = 1e9 + 7;


using namespace std;
//!----Globales----------------------------------------------------------------------------------------



//!----FUNCIONES---------------------------------------------------------------------------------------


	

//!----MAIN--------------------------------------------------------------------------------------------
int main(){
IOS_B;

	long long n, m;
	cin>>n>>m;
	long long mx[n+1][m+1] = {}, dp[n+1][m+1] = {}, ans[n+1][m+1] = {};
	
	for(int i = 0; i<n; ++i){
		for(int k = 0; k<m; ++k){
			cin>>mx[i][k];
		}
	}
	
	for(int i = n-1; i>=0; --i){
		for(int k = m-1; k>=0; --k){
			ans[i][k] = max(dp[i+1][k+1] + mx[i][k], max(dp[i][k+1] + mx[i][k], dp[i+1][k] + mx[i][k]));		
			dp[i][k] = max(max(ans[i][k], dp[i+1][k+1]), max(dp[i+1][k], dp[i][k+1]));		
		}
	}
	
	long long sum = 0;
	
	for(int i = n-1; i>=0; --i){
		for(int k = m-1; k>=0; --k){
			sum += ans[i][k];
		}
	}
	
	cout<<sum<<"\n";
	
return 0;
}

