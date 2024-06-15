//!----LIBRERIAS---------------------------------------------------------------------------------------
#include <iostream>
#include <vector>
//#include <algorithm>
//#include <math.h>
//#include <memory.h>
//#include <set>
#include <map>
#include <queue>
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

	int n, x, c = 0;
	cin>>n>>x;
	long long array[n],dp[x+1] = {};
	map<int,int> mp;
	vi vec;
	
	for(int i = 0; i<n; i++){
		cin>>array[i];
	}
	
	for(int i = 0; i<n; ++i){
		for(int k = x; k>0; --k){
			if(dp[k]!=0)
				if(k+array[i] <= x)
					dp[k+array[i]]+=dp[k];	
			if(k == array[i])
				dp[k]++;
		}
	}
	
	cout<<dp[x]<<"\n";
	
	/*for(int i = 0; i<n; ++i){
		int k = array[i];
		for(int i = vec.size()-1; i>=0 ;i--){
			int c = mp[vec[i]], y = vec[i];
			if(mp[y+k] == 0)
				vec.pb(y+k);
			mp[k+y] += c;
		}
		if(mp[k] == 0)
			vec.pb(k);
		mp[array[i]]++;
	}
	
	cout<<mp[x]<<"\n";
	*/
				
return 0;
}