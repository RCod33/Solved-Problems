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

vvi G(3001);
int vis[3001];
int check;

//!----FUNCIONES---------------------------------------------------------------------------------------

void dfs(int u){
	check++;
	vis[u] = 1;
	for(int i = 0; i<G[u].size();++i){
		if(vis[G[u][i]] == 0)
			dfs(G[u][i]);
	}
}

//!----MAIN--------------------------------------------------------------------------------------------
int main(){
//IOS_B;

	int n,m;
	cin>>n>>m;
	set <int> kit;
		
	while(m--){
		int a,b;
		cin>>a>>b;
		
		G[a].pb(b);
		G[b].pb(a);
	}
	
	for(int i = 1; i<=n; ++i){
		kit.insert(i);
	}
	
	int t = n;
	
	while(t--){
		int a;
		cin>>a;
		check = 0;
		for(int i = 1; i<=n; ++i){
			if(vis[i] != -1)
				vis[i] = 0;
		}
		int v = *kit.begin();
		dfs(v);
		vis[a] = -1;
		kit.erase(kit.find(a));
		if(check == t+1)
			cout<<"YES\n";
		else
			cout<<"NO\n";
	}

				
return 0;
}

