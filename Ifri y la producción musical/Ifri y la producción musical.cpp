//!----LIBRERIAS---------------------------------------------------------------------------------------
#include <iostream>
//#include <vector>
//#include <algorithm>
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

ii st[1000000*4];

//!----FUNCIONES---------------------------------------------------------------------------------------

void build(int a[], int node, int l, int r){
	if(l == r){
		st[node].fi = a[l];
		st[node].se = a[l];
	} else{
		build(a,left);
		build(a,right);
		st[node].fi = min(st[node*2].fi,st[node*2+1].fi);
		st[node].se = max(st[node*2].se,st[node*2+1].se);
	}
}

ii query(int node, int l, int r, int x, int y){
	if(x > y) return mk(mod,0);
	if(x == l && y == r){
		return mk(st[node].fi,st[node].se);
	}
	int m = (r+l)/2;
	ii q1 = query(node*2,l,m,x,min(y,m));
	ii q2 = query(node*2+1,m+1,r,max(x,m+1),y);
	return mk(min(q1.fi,q2.fi),max(q1.se,q2.se));
}

/*void querymin(int node, int l, int r, int x, int y){
	if(x > y) return mod;
	if(x == l && y == r){
		return st[node].fi;
	}
	int m = (r+l)/2;
	return min(querymin(node*2,l,m,x,min(y,m)), querymin(node*2+1,m+1,r,max(x,m+1),y));
}*/


//!----MAIN--------------------------------------------------------------------------------------------
int main(){
IOS_B;

	int n,m,c;
	cin>>n>>m>>c;
	int array[n];
	
	for(int i = 0; i<n; i++)
		cin>>array[i];
	
	build(array,1,0,n-1);
	
	bool f = 0;
	for(int i = 0;i<n-m+1; ++i){
		ii a = query(1,0,n-1,i,i+m-1);
		
		if(a.se-a.fi <= c){
			f = 1;
			cout<<i+1<<"\n";
		}
	}
	
	if(f == 0)
		cout<<"NONE\n";

				
return 0;
}

