//Encontrará la descripción del problema en el siguente enlace: 
//https://dmoj.uclv.edu.cu/problem/rub


//!----LIBRERIAS---------------------------------------------------------------------------------------
#include <iostream>
#include <vector>
//#include <algorithm>
//#include <math.h>
//#include <memory.h>
#include <set>
//#include <map>
//#include <queue>
//#include <stack>
//#include <string>

//!----MACROS------------------------------------------------------------------------------------------
#define vi vector <int>
#define vvi vector<vector<int>>
#define vii vector<vector<pair<int,int>>>
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

vii G(10001);
vi dis(10001);

//!----FUNCIONES---------------------------------------------------------------------------------------

void dijkstra(int node, int si){
	set<ii> kit;
	kit.insert(mk(si,node));
	dis[node] = si;
	while(!kit.empty()){
		auto top = *kit.begin();
		kit.erase(kit.begin());
		int u = top.se;
		for(auto it: G[u]){
			node = it.se;
			int val = it.fi;
			if(dis[node] > dis[u] + val){
				if(dis[node] != mod){
					kit.erase(kit.find(mk(dis[node], node)));
				}
				kit.insert(mk(dis[u] + val, node));
				dis[node] = dis[u] + val;
			}
		}
	}
}

//!----MAIN--------------------------------------------------------------------------------------------
int main(){
IOS_B;

	int n,m;
	cin>>n>>m;
	ii mx[n][m];
	
	int nodo = 1;
	for(int i = 0; i<n; ++i){
		for(int k = 0; k<m; ++k){
			int a;
			cin>>a;
			mx[i][k] = mk(a,nodo);
			nodo++;
		}
	}
	
	for(int i = 0; i<n; ++i){
		for(int k = 0; k<m; ++k){
			if(k != m-1)
				G[mx[i][k].se].pb(mk(mx[i][k+1].fi, mx[i][k+1].se));
			if(k != 0)
				G[mx[i][k].se].pb(mk(mx[i][k-1].fi, mx[i][k-1].se));
			if(i != n-1)
				G[mx[i][k].se].pb(mk(mx[i+1][k].fi, mx[i+1][k].se));
			if(i != 0)
				G[mx[i][k].se].pb(mk(mx[i-1][k].fi, mx[i-1][k].se));
		}
	}
	
	int ans = mod;
	for(int i = 0; i<n; ++i){
		for(int k = 0; k<dis.size(); ++k){
			dis[k] = mod;
		}
		dijkstra(mx[i][0].se, mx[i][0].fi);
		for(int k = 0; k<n; k++){
			ans = min(ans, dis[mx[k][m-1].se]);
		}
	}

	cout<<ans<<"\n";

return 0;
}


