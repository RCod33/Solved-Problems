//Encontrará la descripción del problema en el siguente enlace: 
//https://dmoj.uclv.edu.cu/problem/intercastelar

//!----LIBRERIAS---------------------------------------------------------------------------------------
#include <iostream>
//#include <vector>
#include <algorithm>
//#include <math.h>
//#include <memory.h>
//#include <set>
//#include <map>
//#include <queue>
//#include <stack>
//#include <string>
#include<bits/stdc++.h>

//!----MACROS------------------------------------------------------------------------------------------
#define vi vector <int>
#define vvi vector<vector<int>>
#define vvii vector<vector<pair<long long,long long>>>
#define ii pair <long long,long long>
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

	long long n;
	cin>>n;
	long long array[n];	
	vector<ii> dp;
	
	for(int i = 0; i<n; ++i)
		cin>>array[i];
	
	long long k = 1;
	for(int i = 0; i<n; i++){
		if(array[i]%2 == 0){
			long long a = array[i];
			long long c = 0;
			while(a%2 == 0){
				c++;
				a/=2;
			}
			dp.pb(mk(k, a));
			k += (long long)pow(2,c);
		}
		else{
			dp.pb(mk(k, array[i]));
			k++;
		}
	}
	
	
	int q;
	cin>>q;
	
	while(q--){
		long long x;
		cin>>x;
		long long a = upper_bound(all(dp), mk(x, (long long)99999999999)) - dp.begin();
		cout<<dp[a-1].se<<"\n";		
	}

return 0;
}


