//!----LIBRERIAS---------------------------------------------------------------------------------------
#include <iostream>
#include <vector>
//#include <algorithm>
//#include <math.h>
//#include <memory.h>
#include <set>
//#include <map>
#include <queue>
//#include <stack>
//#include <string>

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
const long long mod = 1e18 + 7;


using namespace std;
//!----Globales----------------------------------------------------------------------------------------

vvii G(200001);
vvi GM(200001);
bool vis[200001] = {}, vis2[200001] = {};
vector<long long> dis(200001, mod);
vi tin(200001, -1), low(200001, -1);
int timer, ans;

//!----FUNCIONES---------------------------------------------------------------------------------------

void dijkstra(int node){
	set<ii> kit;
	kit.insert(mk(0, node));
	dis[node] = 0;
	while(!kit.empty()){
		auto top = *kit.begin();
		kit.erase(kit.begin());
		int u = top.se;
		for(auto it: G[u]){
			node = it.se;
			long long val = it.fi;
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

void path(int node){
	queue<int> q;
	q.push(node);
	vis2[node] = 1;	
	while(!q.empty()){
		node = q.front();
		q.pop();
		for(auto it: G[node]){
			int u = it.se;
			long long v = it.fi;
			if(dis[u] == dis[node] - v){
				if(vis2[u] == 0)
					q.push(u);
				vis2[u] = 1;
				GM[node].pb(u);
				GM[u].pb(node);
			}
		}
	}
}

void bridges(int node, int p){
	timer++;
	tin[node] = low[node] = timer;
	vis[node] = 1;
	for(auto to: GM[node]){
		if(to == p)
			continue;
		if(vis[to] == 1)
			low[node] = min(low[node], tin[to]);
		else{
			bridges(to, node);
			low[node] = min(low[node], low[to]);
			if(low[to] > tin[node]){
				ans++;
			}
		}
	}
}

//!----MAIN--------------------------------------------------------------------------------------------
int main(){
IOS_B;

	int n,m;
	cin>>n>>m;
	int x,y;
	cin>>x>>y;
	
	for(int i = 0; i<m; ++i){
		long long a,b,c;
		cin>>a>>b>>c;
		G[a].pb(mk(c,b));
		G[b].pb(mk(c,a));
	}

	dijkstra(x);
	path(y);
	bridges(x, -1);
	
	cout<<ans<<"\n";

	
return 0;
}


