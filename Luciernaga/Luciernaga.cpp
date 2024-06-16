//Encontrará la descripción del problema en el siguente enlace: 
//https://dmoj.uclv.edu.cu/problem/firefly

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

	int n,m;
	cin>>n>>m;
	int array[m+1] = {};
	
	for(int i = 0; i<n; ++i){
		if(i%2 == 0){
			int a;
			cin>>a;
			array[1]++;
			array[a+1]--;
		}
		else{
			int a;
			cin>>a;
			array[m-a+1]++;
		}
	}
	
	int MIN = mod,c = 0;
	int dp[m+1] = {};
	for(int i = 1; i<=m; ++i){
		dp[i] = array[i] + dp[i-1];
		MIN = min(MIN,dp[i]);
	}
	
	for(int i = 1; i<=m; ++i){
		if(dp[i] == MIN)
			c++;
	}
	
	cout<<MIN<<" "<<c<<"\n";
	

				
return 0;
}

