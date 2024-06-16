//Encontrará la descripción del problema en el siguente enlace: 
//https://dmoj.uclv.edu.cu/problem/copa2023p2

//!----LIBRERIAS---------------------------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <algorithm>
//#include <math.h>
//#include <memory.h>
//#include <set>
//#include <map>
//#include <queue>
//#include <stack>
//#include <string>

//!----MACROS------------------------------------------------------------------------------------------
#define int long long
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
const int mod = 2e18 + 7;


using namespace std;
//!----Globales----------------------------------------------------------------------------------------



//!----FUNCIONES---------------------------------------------------------------------------------------



//!----MAIN--------------------------------------------------------------------------------------------
main(){
IOS_B;

	int x , y, r, g, c;
	cin>>x>>y>>r>>g>>c;
	int ans = 0;
	vi red(r), green(g), col(c);
	vi dpr(x+1), dpg(y+1);
	
	dpr[x] = mod;
	dpg[y] = mod;
	
	for(int i = 0; i<r; ++i){
		cin>>red[i];
	
	}
	for(int i = 0; i<g; ++i){
		cin>>green[i];
	}
	
	for(int i = 0; i<c; ++i){
		cin>>col[i];
	}
	
	sort(all(red));	
	sort(all(green));	
	sort(all(col));	
	
	int k = red.size()-1;
	
	for(int i = x-1; i>=0; --i){
		dpr[i] = red[k];
		ans += dpr[i]; 
		k--;
	}
	
	k = green.size()-1;
	
	for(int i = y-1; i>=0; --i){
		dpg[i] = green[k];
		ans += dpg[i];
		k--;
	}
	
	int j = 0;
	k = 0;
	
	for(int i = c-1; i>=0; --i){
		int a = min(dpr[j], dpg[k]);
		if(col[i] > a)
			ans = (ans - a) + col[i];
		else
			break;
		
		if(dpr[j] > dpg[k]){
			if(k <= dpg.size())
				k++;
		}
		else{
			if(j <= dpr.size())
				j++;
		}
	}
	
	cout<<ans<<"\n";
	
return 0;
}


