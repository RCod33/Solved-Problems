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
#include <climits>

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
const long long MAX = LONG_LONG_MAX;


using namespace std;
//!----Globales----------------------------------------------------------------------------------------

vector<vector<pair<long long,long long>>> G(200000+2);
long long dis[200000+2];

//!----FUNCIONES---------------------------------------------------------------------------------------

void dijkstra(long long node){
	set <pair<long long, long long>> kit;
	dis[node] = 0;
	kit.insert(mk(0,node));
	while(!kit.empty()){
		pair<long long, long long> top = *kit.begin();
		kit.erase(kit.begin());
		long long u = top.se;
		for(auto it: G[u]){
			node = it.se;
			long long cost = it.fi;
			if(dis[node] > dis[u] + cost){
				if(dis[node] != MAX){
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

	int n,m;
	cin>>n>>m;
	
	while(m--){
		long long a,b,c;
		cin>>a>>b>>c;
		G[a].pb(mk(c*2,b));
		G[b].pb(mk(c*2,a));
	}
	
	loop(i,1,n+1){
		long long a;
		cin>>a;
		G[i].pb(mk(a,200000+1)); 
		G[200000+1].pb(mk(a, i)); 
	}
	
	for(int i = 0; i<=200000+1; ++i)
		dis[i] = MAX;
	
	dijkstra(200000+1);
	
	for(int i = 1; i<=n; ++i)
		cout<<dis[i]<<" ";

				
return 0;
}

