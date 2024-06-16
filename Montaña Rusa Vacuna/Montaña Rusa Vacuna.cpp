//Encontrará la descripción del problema en el siguente enlace: 
//https://dmoj.uclv.edu.cu/problem/coaster

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

vector<map<int,int>> dp(1000);

//!----FUNCIONES---------------------------------------------------------------------------------------



//!----MAIN--------------------------------------------------------------------------------------------
int main(){
IOS_B;

	int n,k,d;
	cin>>n>>k>>d;
	vector<pair<ii, ii>> vec(k);
	
	for(int i = 0; i<k; ++i){
		int a,b,c,d;
		cin>>a>>b>>c>>d;
		vec[i] = mk(mk(a,b),mk(c,d));
	}
	
	sort(all(vec));
	dp[0][0] = 0;
	
	for(auto it: vec){
		int one = it.fi.fi, two = it.fi.se, three = it.se.fi, four = it.se.se;
		for(auto it2: dp[one]){
			if(it2.fi + four <= d){
				if(dp[one+two][it2.fi + four] < dp[one][it2.fi] + three){
					dp[one+two][it2.fi + four] = dp[one][it2.fi] + three;
				}
			} 
		}
	}
	
	int ans = -1;
	for(auto it: dp[n]){
		ans = max(ans, it.se);
	}
	
	cout<<ans<<"\n";
	
return 0;
}


