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
	int array[n];
	
	for(int i = 0; i<n; ++i)
		cin>>array[i];

	int pos = -1;
	
	for(int i = 0; i<n; ++i){
		for(int k = i; k<n; ++k){
			if(array[k] < array[i]){
				pos = i;
				break;
			}
		}
		if(pos != -1)
			break;
	}
	
	if(pos == -1)
		cout<<0<<"\n";
	else{
		for(int i = n-1; i>pos; --i){
			if(array[i] < array[pos]){
				swap(array[i], array[pos]);
				break;
			}
		}
		bool f = 0;
		for(int i = 0; i<n; ++i){
			for(int k = i; k<n; ++k){
				if(array[k] < array[i]){
					f = 1;
				}
			}
		}
		
		if(f == 0)
			cout<<1<<"\n";
		else
			cout<<-1<<"\n";
	}		
	
	
return 0;
}


