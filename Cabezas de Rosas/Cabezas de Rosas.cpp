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

vvi G(1001);
bool vis[1001];
int mx[1001][1001];

//!----FUNCIONES---------------------------------------------------------------------------------------

int dfs(int node){
	vis[node] = 1;
	
	int sum = 0;
	for(auto it:G[node]){
		if(vis[it] == 0){
			int a = dfs(it);
			sum += min(mx[node][it], a);
		}
	}
	
	return (sum == 0) ? mod : sum;
}


//!----MAIN--------------------------------------------------------------------------------------------
int main(){
//IOS_B;
	
	int n;
	while(cin>>n){
		int x;
		cin>>x;
		
		for(int i = 0; i<1001; ++i){
			G[i].erase(all(G[i]));
			vis[i] = 0;
			for(int k = 0; k<1001; ++k){
				mx[i][k] = 0;
			}
		}
		
		for(int i = 0; i<n-1; ++i){
			int a,b,c;
			cin>>a>>b>>c;
			G[a].pb(b);
			G[b].pb(a);
			mx[a][b] = c;
			mx[b][a] = c;
		}
		
		cout<<dfs(x)<<"\n";
		
	}


return 0;
}


