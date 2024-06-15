//!----LIBRERIAS---------------------------------------------------------------------------------------
//#include <bits/stdc++.h>
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

vi dis(100001);
vvi G;

//!----FUNCIONES---------------------------------------------------------------------------------------

int dfs(int node, int nv){
	if(dis[node] != 0)
		return dis[node];
	
	int ans = 0;
	for(int i=0;i<G[node].size();++i){
		ans = max(ans,dfs(G[node][i],nv+1)+1);
	}
	
	return dis[node] = ans;
}

//!----MAIN--------------------------------------------------------------------------------------------
int main(){
IOS_B;

	int n,m;
	cin>>n>>m;
	G.resize(n+1);
	
	loop(i,0,m){
		int a,b;
		cin>>a>>b;
		G[a].pb(b);
	}

	for(int i=1;i<=n;++i){
			dfs(i,0);
	}

	cout<<*max_element(all(dis))<<"\n";
				
return 0;
}

