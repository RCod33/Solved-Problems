//Encontrará la descripción del problema en el siguente enlace: 
//https://dmoj.uclv.edu.cu/problem/pack

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
	vi Pan(n), dpan(100000+1, mod);
	
	loop(i,0,n)
		cin>>Pan[i];
	
	int m;
	cin>>m;
	vi Perr(m), dperr(100000+1, mod);
	
	loop(i,0,m)
		cin>>Perr[i];

	for(auto it: Pan){
		for(int i = 100000; i>=1; --i){
			if(dpan[i] != mod)
				dpan[i+it] = min(dpan[i] + 1, dpan[i+it]);
			if(i == it)
				dpan[i] = 1;
		}
	}
	
	for(auto it: Perr){
		for(int i = 100000; i>=1; --i){
			if(dperr[i] != 0)
				dperr[i+it] = min(dperr[i] + 1, dperr[i+it]);
			if(i == it)
				dperr[i] = 1;
		}
	}
	
	int ans = mod;
	for(int i = 1; i < dpan.size(); i++)
		if(dpan[i] != mod && dperr[i] != mod)
			ans = min(ans, dpan[i] + dperr[i]);
	
	if(ans == mod)
		cout<<"imposible\n";
	else
		cout<<ans<<"\n";
	
return 0;
}

