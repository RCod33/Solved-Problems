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

	int n;
	cin>>n;
	int array[n], seven[7] = {};
	
	for(int i =0; i<7; ++i)
		seven[i] = -1;
	
	for(int i = 0; i<n; ++i){
		cin>>array[i];
		array[i] %= 7;
	}

	
	for(int i = 1; i<n; ++i){
		array[i] = (array[i]+array[i-1])%7;
		seven[array[i]] = i;
	}
	
	int ans = 0;
	if(seven[0] != -1){
		ans = seven[0];
	}
	
	for(int i = 0; i<n; ++i){
		if(seven[array[i]] != -1 && seven[array[i]] > i){
			ans = max(seven[array[i]] - i, ans);
		}			
	}
	
	cout<<ans<<"\n";
	
return 0;
}


