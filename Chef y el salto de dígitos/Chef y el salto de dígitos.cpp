//!----LIBRERIAS---------------------------------------------------------------------------------------
#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <math.h>
//#include <memory.h>
//#include <set>
//#include <map>
#include <queue>
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

vvi vec(10);
int dis[101];

//!----FUNCIONES---------------------------------------------------------------------------------------

void bfs(int node, vvi G){
	int u,v;
	queue<int> q;
	q.push(node);
	dis[node] = 0;
	while(!q.empty()){
		u = q.front();
		q.pop();
		for(int i = 0; i<G[u].size(); ++i){
			v = G[u][i];
			if(!dis[v]){
				q.push(v);
				dis[v] = dis[u]+1;
			}
		}
	}
}


//!----MAIN--------------------------------------------------------------------------------------------
int main(){
IOS_B;

	string s;
	cin>>s;
	int n = s.size();
	vvi G(n);
	
	for(int i = 0; i<n; ++i){
		int a = s[i] - '0';
		if(i){
			G[i].pb(i-1);		 
			G[i-1].pb(i);
		}
		for(int k = 0; k<vec[a].size(); k++){
			G[vec[a][k]].pb(i);
			G[i].pb(vec[a][k]);
			
		}		 
		vec[a].pb(i);
	}	

	bfs(0,G);	
	
	cout<<dis[n-1];

				
return 0;
}

