//Encontrara la descripción del problema en el siguente enlace: 
//https://codeforces.com/problemset/problem/1883/B
//!----LIBRERIAS---------------------------------------------------------------------------------------
#include <iostream>
//#include <vector>
//#include <algorithm>
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

	int t;
	cin>>t;
	
	while(t--){
		int n,k;
		cin>>n>>k;
		string s;
		cin>>s;
		map<char,int> mp;
		
		for(int i = 0; i<s.size(); ++i){
			mp[s[i]]++;
		}
		
		int c = 0;
		for(auto it: mp){
			if(it.se%2 == 1)
				c++;
		}
		
		if(c-1<=k)
			cout<<"YES\n";
		else
			cout<<"NO\n";
	}


return 0;
}


