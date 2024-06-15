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

	int n, k;
	cin>>n>>k;
	int array[n+1] = {};
	int dp[n+1][k+1][3] = {};
	
	for(int i = 0; i<n; ++i){
		char a;
		cin>>a;
		if(a == 'P')
			array[i] = 0; 
		if(a == 'H')
			array[i] = 1;
		if(a == 'S')
			array[i] = 2; 
	}
	
	dp[0][0][array[0]] = 1;
	int ans = 0 ;
	
	for(int i = 1; i<n; ++i){
		int a = array[i];
		for(int j = 0; j<=k; ++j){
			for(int h = 0; h<3; h++){
				if(a == h){
					if(j == 0)
						dp[i][j][h] += dp[i-1][j][h]+1;
					else 
						dp[i][j][h] += max(max(dp[i-1][j-1][(h+1)%3], //down
							dp[i-1][j-1][(h+2)%3]), dp[i-1][j][h])+1;
				}
				else{
					dp[i][j][h] =  dp[i-1][j][h];
				}
				ans = max(ans, dp[i][j][h]);
			}
		}
	}
	
	cout<<ans<<"\n";
	
return 0;
}