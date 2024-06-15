//!----LIBRERIAS---------------------------------------------------------------------------------------
#include <iostream>
#include <vector>
//#include <algorithm>
//#include <math.h>
//#include <memory.h>
//#include <set>
//#include <map>
//#include <queue>
//#include <stack>


//!----MACROS------------------------------------------------------------------------------------------
#define loop(i,a,b) for(int i=a;i<b;i++)
#define rloop(k,a,b) for(int k=a;k>b;k--)
#define vvi vector<vector<pair<int,int>>>
#define vi vector <int>
#define ii pair <int,int>
#define pb(a) push_back(a)
#define mk(a,b) make_pair(a,b)
#define all(x) x.begin(),x.end()
#define sz(x) ((x).size())
#define sza(x) sizeof(x)/sizeof(x[0])
#define fi first
#define se second
#define mset(a,b) memset(a,b,sizeof(a))
#define IOS_B ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
const int mod = 1e9 + 7;

using namespace std;
//!----Globales----------------------------------------------------------------------------------------



//!----FUNCIONES---------------------------------------------------------------------------------------



//!----MAIN--------------------------------------------------------------------------------------------
int main(){
IOS_B;

int x,y,m;
cin>>x>>y>>m;
vi vec(2);
vi dp(m+1,0);

vec[0] = x;
vec[1] = y;
	
	for(auto it:vec)
		for(int i=it;i<=m;++i){
			dp[i] = max(dp[i],dp[i-it]+it);	
		}
	for(int i=m;i>0;i--)
		if(dp[i]==i){
			cout<<i;
			break;
		}
				
return 0;
}

