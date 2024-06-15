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

int st[8*100000];

//!----FUNCIONES---------------------------------------------------------------------------------------

void build(int a[], int node, int l, int r){
	if(l == r)
		st[node] = a[l];
	else{
		build(a,left);
		build(a,right);
		st[node] = max(st[node*2], st[node*2+1]);
	}
}

void query(int node, int l, int r, int val){
	if(l == r){
		st[node] -= val;
		cout<<l+1<<" "; 
	}
	else{
		if(st[node*2] >= val)
			query(left,val); 
		else
			query(right,val);
		st[node] = max(st[node*2], st[node*2+1]);
	}
}


//!----MAIN--------------------------------------------------------------------------------------------
int main(){
IOS_B;

	int n,m;
	cin>>n>>m;
	int array[n];
	
	loop(i,0,n)
		cin>>array[i];
	
	build(array,1,0,n-1);
	
	while(m--){
		int a;
		cin>>a;
		if(st[1]< a) 
			cout<<0<<" "; 
		else 
			query(1,0,n-1,a);
	}
				
return 0;
}

