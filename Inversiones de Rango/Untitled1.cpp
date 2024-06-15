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
	
	int n;
	cin>>n;
	int array[n+1] = {}; 
	int mx[n+1][n+1] = {};
	
	for(int i = 1; i<=n; ++i){
		cin>>array[i];
	}
	
	for(int i=1; i<=n; ++i){
		for(int k=i+1; k<=n; ++k){
			if(array[k]<array[i])
				mx[i][k] = 1;
		}
	}
	
	for(int i=1; i<=n; ++i){
		for(int k=1; k<=n; ++k){
			mx[i][k] = mx[i-1][k] + mx[i][k-1] - mx[i-1][k-1] + mx[i][k];
		}
	}
	int q;
	cin>>q;
	while(q--){
		int a,b,c,d;
		cin>>a>>b>>c>>d;
		
		cout<<mx[b][d]-mx[b][c-1]-mx[a-1][d]+mx[a-1][c-1]<<"\n";
	}
				
return 0;
}

