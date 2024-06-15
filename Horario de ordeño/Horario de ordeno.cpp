//!----LIBRERIAS---------------------------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <algorithm>
//#include <math.h>
//#include <memory.h>
//#include <set>
//#include <map>
//#include <queue>
//#include <stack>
//#include <string>

//!----MACROS------------------------------------------------------------------------------------------
#define vi vector <int>
#define vvi vector<vector<int>>
#define vvii vector<vector<pair<int,int>>>
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

int dp[10000];

//!----FUNCIONES---------------------------------------------------------------------------------------



//!----MAIN--------------------------------------------------------------------------------------------
int main(){
IOS_B;

	int n;
	cin>>n;
	vector<ii> vec(n);
	
	for(int i = 0; i<n; ++i){
		int a,b;
		cin>>a>>b;
		vec[i] = mk(b,a);
	}
	
	sort(all(vec));
	
	for(auto it: vec){
		for(int i = it.fi; i >= 0; --i){
			if(dp[i] != 0 && i != it.fi){
				dp[i+1] = max(dp[i] + it.se, dp[i+1]);
			}
			if(i == 0)
				dp[i+1] = max(dp[i+1], it.se);
		}
	}
	
	int ans = 0;
	for(int i = 0; i<10000; ++i){
		ans = max(ans, dp[i]);
	}
	
	cout<<ans<<"\n";

return 0;
}


