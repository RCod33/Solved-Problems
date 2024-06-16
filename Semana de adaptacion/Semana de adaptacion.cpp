//Encontrará la descripción del problema en el siguente enlace: 
//https://dmoj.uclv.edu.cu/problem/frosh

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

long long st[1000000*4];

//!----FUNCIONES---------------------------------------------------------------------------------------

void update(int node, int l, int r, int pos){
	if(l == r)
		st[node]++;
	else{
		if(pos<=mid)
			update(left, pos);
		else
			update(right, pos);
		st[node] = st[node*2] + st[node*2+1];
	}
}

long long query(int node, int l, int r, int x, int y){
	if(x>y)
		return 0;
	if(l == x && r == y)
		return st[node];
	
	return query(left, x, min(y,mid)) + query(right, max(x,mid+1), y) ;
		
}

//!----MAIN--------------------------------------------------------------------------------------------
int main(){
IOS_B;

	long long n, MAXN = -1;
	cin>>n;
	vector<long long> array(n);
	
	for(int i = 0; i<n; ++i){
		cin>>array[i];
	}
	
	vector<long long> temp = array;
	
	sort(all(temp));
	
	for(int i = 0; i<n; i++){
		array[i] = lower_bound(all(temp), array[i]) - temp.begin();
		MAXN = max(MAXN, array[i]);
	}
	
	long long c = 0;
	for(int i = 0; i<n; ++i){
		c += query(1, 0, MAXN, array[i], MAXN);
		update(1, 0, MAXN, array[i]);
	}
	
	cout<<c<<"\n";
		
return 0;
}