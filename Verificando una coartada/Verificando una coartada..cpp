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

vii G(501);
int dis [501];

//!----FUNCIONES---------------------------------------------------------------------------------------

void dijkstra(int node){
	set <ii> kit;
	dis[node] = 0;
	kit.insert(mk(0,node));
	while(!kit.empty()){
		ii top = *kit.begin();
		kit.erase(kit.begin());
		int u = top.second;
		for(auto it: G[u]){
			node = it.second;
			int cost = it.first;
			if(dis[node] > dis[u] + cost){
				if(dis[node] != mod){
					kit.erase(kit.find(mk(dis[node], node)));
				}
				dis[node] = dis[u] + cost;
				kit.insert(mk(dis[node], node));		
			}
		} 
	}
}


//!----MAIN--------------------------------------------------------------------------------------------
int main(){
IOS_B;
	
	loop(i,0,501)
		dis[i] = mod;

	int n,m,cw,k;
	cin>>n>>m>>cw>>k;
	
	for(int i = 0; i<m; ++i){
		int a,b,c;
		cin>>a>>b>>c;
		
		G[a].pb(mk(c,b));
		G[b].pb(mk(c,a));
	}
	
	dijkstra(1);
	
	int c = 0;
	vi vec;
	loop(i,1,cw+1){
		int a;
		cin>>a;
		if(dis[a] <= k){
			c++;
			vec.pb(i);	
		}
	}
	
	cout<<c<<"\n";
	
	loop(i,0,vec.size())
		cout<<vec[i]<<"\n";
				
return 0;
}

