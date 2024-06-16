//Encontrará la descripción del problema en el siguente enlace: 
//https://dmoj.uclv.edu.cu/problem/apple

//!----LIBRERIAS---------------------------------------------------------------------------------------
#include <iostream>
#include <vector>
//#include <algorithm>
//#include <math.h>
#include <memory.h>
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

vii G(100000+5);
long long dis[100000+5];

//!----FUNCIONES---------------------------------------------------------------------------------------

void dijikistra(int node){
	for(int i = 0; i<100000+5; ++i)
		dis[i] = mod;
	
	int u,v;
	set <pair<int,int>> q;
	dis[node] = 0;
	q.insert(mk(0,node));
	while(!q.empty()){
		ii top = *q.begin();
		q.erase(q.begin());
		u = top.first;
		v = top.second;
		for(auto it: G[v]){
			if(dis[it.first] > dis[v] + it.se){
				if(dis[it.first] != mod){
					q.erase(q.find(mk(dis[it.fi],it.fi)));
				}
				dis[it.fi] = dis[v] + it.se;
				q.insert(mk(dis[it.fi],it.fi));	
			}
		}	
	}		
}

//!----MAIN--------------------------------------------------------------------------------------------
int main(){
IOS_B;

	int m,n,p,x,y;
	cin>>m>>n>>p>>x>>y;
	
	for(int i=0; i<m; i++){
		int a,b,c;
		cin>>a>>b>>c;
		G[a].pb(mk(b,c));
		G[b].pb(mk(a,c));
	}
	
	dijikistra(p);
	
	int ans = min(dis[x],dis[y]);
	
	if(dis[x] < dis[y]){
		dijikistra(x);
		ans += dis[y];
	}
	else{
		dijikistra(y);
		ans += dis[x];
	}
	
	cout<<ans<<"\n";
	
				
return 0;
}

