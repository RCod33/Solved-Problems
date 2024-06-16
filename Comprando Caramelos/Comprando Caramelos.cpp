//Encontrará la descripción del problema en el siguente enlace: 
//https://dmoj.uclv.edu.cu/problem/candies

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

	int n,p;
	cin>>n>>p;
	
	vector<pair<long long,long long>> vec(n);
	
	loop(i,0,n){
		cin>>vec[i].second;
	}
	
	loop(i,0,n){
		cin>>vec[i].first;
	}

	long long dp[p+1] = {};
	
	for(auto it: vec){
		int a = it.first, b = it.second;
		for(int i=p; i>0;--i){	
			if(dp[i] != 0){
				int mult = dp[i];
				for(int k = 1;k<=b; ++k){
					if(i+k*a<=p)
						dp[i+k*a]+= 1*mult;	
				}
			}
			if(i == a){
				for(int k = 1;k<=b; ++k){
					if(k*a<=p)
						dp[k*a]++;	
				}
			}
		}
	}
	cout<<dp[p]<<"\n";
	
return 0;
}

