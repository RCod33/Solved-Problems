//Encontrará la descripción del problema en el siguente enlace: 
//https://dmoj.uclv.edu.cu/problem/oci2023day1a

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
#define mid (l+r)/2
#define left node*2,l,mid
#define right node*2+1,mid+1,r
#define mset(a,b) memset(a,b,sizeof(a))
#define IOS_B ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
const int mod = 1e9 + 7;


using namespace std;
//!----Globales----------------------------------------------------------------------------------------

long long dp[100000];

//!----FUNCIONES---------------------------------------------------------------------------------------

long long bar(int n){
	if(dp[n]!=0)
		return dp[n];
	if(n == 0)
		return 0;
	
	return dp[n] = (bar(n-2) + (bar(n-3)*2) + bar(n-4))%mod;
}

//!----MAIN--------------------------------------------------------------------------------------------
int main(){
IOS_B;

	int n;
	cin>>n;
	
	dp[1]=1;
	dp[2]=1;
	dp[3]=1;
	
	cout<<bar(n);
				
return 0;
}

