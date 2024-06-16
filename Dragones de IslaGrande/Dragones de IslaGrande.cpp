//Encontrará la descripción del problema en el siguente enlace: 
//https://dmoj.uclv.edu.cu/problem/dragones

//!----LIBRERIAS---------------------------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <algorithm>
//#include <math.h>
//#include <memory.h>
#include <set>
#include <unordered_map>
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

vvii G(801);
int dis[801];
unordered_map<int,int> dis2[801];
int d[800+1] = {};

//!----FUNCIONES---------------------------------------------------------------------------------------

void dijkstra(int node, int stamina){
	set<ii> kit;
	kit.insert(mk(0,node));
	dis[node] = 0;
	while(!kit.empty()){
		auto top = *kit.begin();
		int u = top.se;
		kit.erase(kit.begin());
		for(auto it: G[u]){
			node = it.se;
			int val = it.fi;
			if(val > stamina)
				continue;
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

void dijkstra2(int node, int stamina){
	set<pair<ii,int>> kit;
	kit.insert(mk(mk(0,node), stamina));
	dis2[node][stamina] = 0;
	while(!kit.empty()){
		auto top = *kit.begin();
		int u = top.fi.se; 
		stamina = max(d[top.fi.se], top.se);
		kit.erase(kit.begin());
		for(auto it: G[u]){
			node = it.se;
			int val = it.fi;
			if(val > stamina)
				continue;
			if(dis2[node][stamina] == 0)
				dis2[node][stamina] = mod;
			if(dis2[node][stamina] > dis2[u][top.se] + val){
				if(dis2[node][stamina] != mod){
						kit.erase(kit.find(mk(mk(dis2[node][stamina], node),stamina)));
				}
				kit.insert(mk(mk(dis2[u][top.se] + val, node), stamina));
				dis2[node][stamina] = dis2[u][top.se] + val;
			}
		}
	}
}


//!----MAIN--------------------------------------------------------------------------------------------
int main(){
IOS_B;

	int p;
	cin>>p;
	int n,m;
	cin>>n>>m;
	
	for(int i = 1; i<=n; ++i){
		cin>>d[i];	
	}

	for(int i = 0; i<m; ++i){
		int a,b,c;
		cin>>a>>b>>c;
		
		G[a].pb(mk(c,b));
		G[b].pb(mk(c,a));
	}
	
	if(p == 1){
		for(int i = 0; i<801; ++i)
			dis[i] = mod;
		
		dijkstra(1, d[1]);
		int ans = 0;
	
		for(int i = 1; i<=n; ++i){
			if(dis[i] != mod)
				ans = max(ans, d[i]);
		}
		
		cout<<ans<<"\n";
	}
	
	else{
		dijkstra2(1, d[1]);
		int ans = mod;
	
		for(auto it: dis2[n]){
			ans = min(it.se,ans);
		}
		cout<<ans<<"\n";
	}
return 0;
}


