//Encontrará la descripción del problema en el siguente enlace: 
//https://dmoj.uclv.edu.cu/problem/inversions

//!----LIBRERIAS---------------------------------------------------------------------------------------
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

long long st[100001*4], st2[100001*4];

//!----FUNCIONES---------------------------------------------------------------------------------------
void update2(int node, int l, int r, int pos){
	if(l == r)
		st2[node]++;
	else{
		if(pos <= mid)
			update2(left,pos);
		else
			update2(right,pos);
		
		st2[node] = st2[node*2] + st2[node*2+1];
	}
}

long long query2(int node, int l, int r, int x, int y){
	if(l == x && r == y)
		return st2[node];
	if(x>y)
		return 0;
	
	return query2(left, x, min(y,mid)) + query2(right, max(x, mid+1), y);
}

void update(int node, int l, int r, int pos, int val){
	if(l == r)
		st[node] += val;
	else{
		if(pos <= mid)
			update(left,pos,val);
		else
			update(right,pos,val);
		
		st[node] = st[node*2] + st[node*2+1];
	}
}


long long query(int node, int l, int r, int x, int y){
	if(l == x && r == y)
		return st[node];
	if(x>y)
		return 0;
	
	return query(left, x, min(y,mid)) + query(right, max(x, mid+1), y);
}


//!----MAIN--------------------------------------------------------------------------------------------
int main(){
IOS_B;

	int t;
	cin>>t;
	
	while(t--){
		int n;
		cin>>n;
		vector<long long> vec(n), aux(n);
		
		for(int i = 0; i<n; ++i){
			cin>>vec[i];
		}
		
		aux = vec;
		
		sort(all(aux));
		
		for(int i = 0; i<n; ++i){
			vec[i] = lower_bound(all(aux), vec[i]) - aux.begin();
		}
		
		long long ans = 0;
		
		for(int i = 0; i<n; ++i){
			ans += query(1, 0, n-1, vec[i] + 1, n-1);
		 	long long a = query2(1, 0, n-1, vec[i] + 1, n-1);
		 	update(1, 0, n-1, vec[i], a);
		 	update2(1, 0, n-1, vec[i]);
		}
	
		cout<<ans<<"\n";
		
		for(int i = 0; i<100001*4; ++i){
			st[i] = st2[i] = 0;
		}
	}


return 0;
}


