//!----LIBRERIAS---------------------------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <algorithm>
//#include <math.h>
//#include <memory.h>
//#include <set>
#include <map>
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



//!----FUNCIONES---------------------------------------------------------------------------------------



//!----MAIN--------------------------------------------------------------------------------------------
int main(){
IOS_B;

	int n,r;
	cin>>n>>r;
	vi dp[4];
	
	while(r--){
		int x;
		cin>>x;
		if(x == 1){
			int y;
			cin>>y;
			dp[1].pb(y);
		}
		if(x == 2){
			int y;
			cin>>y;
			dp[2].pb(y);
		}
		if(x == 3){
			int y,z;
			cin>>y>>z;
			
			dp[3].pb(y+z);
		}
	}
	
	
	sort(all(dp[1]));
	sort(all(dp[2]));
	sort(all(dp[3]));
	
	int q;
	cin>>q;
	while(q--){
		int a,b;
		cin>>a>>b;
		int sum = 0;
		
		int	x = upper_bound(all(dp[1]), a) - dp[1].begin();
		
		sum += x;
		
		x = upper_bound(all(dp[2]), b) - dp[2].begin();
		
		sum += x;
		
		x = upper_bound(all(dp[3]), a+b) - dp[3].begin();
		
		sum += x; 
		
		if(a%2 == b%2){
			if(sum%2 == 0)
				cout<<1<<" ";
			else
				cout<<0<<" ";
		}
		else{
			if(sum%2 == 1)
				cout<<1<<" ";
			else
				cout<<0<<" ";
		}
	}
	
return 0;
}