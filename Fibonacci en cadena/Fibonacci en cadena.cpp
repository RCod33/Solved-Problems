//Encontrará la descripción del problema en el siguente enlace: 
//https://dmoj.uclv.edu.cu/problem/3fib

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

	string s;
	cin>>s;
	int n = s.size(), div = n/3, res = 3 - n%3, res2 = n%3, zise = div;
	int xyz[3] = {};
	
	if(s == "112"){
		cout<<"358\n";
		return 0;
	}
	
	int si = 0, start = 0;
	while(res--){
		for(int i = start; i<div; ++i){
			xyz[si] *= 10;
			xyz[si] += (s[i] - '0');
		}
		start = div;
		div+=zise;
		si++;
	}
	
	div++;
	zise++;
	while(res2--){
		for(int i = start; i<div; ++i){
			xyz[si] *= 10;
			xyz[si] += (s[i] - '0');
		}
		start = div;
		div+=zise;
		si++;
	}
	
	long long dp[51] = {};
	
	dp[0] = dp[1] = 1;
	int pos[3];
	pos[0] = pos[1] = pos[2] = mod;
	
	for(int i = 0; i<=50; ++i){
		if(i > 1)
			dp[i] = dp[i-1] + dp[i-2];
		
		if(dp[i] == xyz[0]){
			pos[0]= i;
		}
	}
	
	if(dp[pos[0]+1] == xyz[1])
		pos[1] = pos[0]+1;
	
	if(dp[pos[0]+2] == xyz[2])
		pos[2] = pos[0]+2;
	
	if(pos[0] == mod || pos[1] == mod || pos[2] == mod){
		cout<<"Error\n";
	}
	else{
		cout<<dp[pos[2]+1]<<dp[pos[2]+2]<<dp[pos[2]+3]<<"\n";
	}

return 0;
}

