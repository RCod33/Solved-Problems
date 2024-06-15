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
		int n;
		cin>>n;
		string s;
		cin>>s;
		
		int a = 0, b = 0;
		vi vec;
		for(int i = 0; i<n; ++i){
			if(s[i] == 'A'){
				if(b != 0)
					vec.pb(b);
				b = 0;
				a++;
			}
			if(s[i] == 'B')
				b++;
		}
		
		if(b != 0)
			vec.pb(b);
		
		if(a%2 == 0)
			cout<<-1<<"\n";
		else{
			int a = 0;
			for(int i = 0; i<vec.size(); ++i){
				a = a^vec[i];
			}
			a = __builtin_popcount(a);
			if(a != 0)
				cout<<"F\n";
			else
				cout<<"R\n";	
		}
	}


return 0;
}


