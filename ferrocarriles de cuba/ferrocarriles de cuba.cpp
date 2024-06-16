//Encontrará la descripción del problema en el siguente enlace: 
//https://dmoj.uclv.edu.cu/problem/jumping

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



//!----FUNCIONES---------------------------------------------------------------------------------------



//!----MAIN--------------------------------------------------------------------------------------------
int main(){
IOS_B;

	int n,x;
	cin>>n>>x;
	int MAX = 0,MIN = 0;
	pair<int,int> array[n];
	queue <int> dif;
	bool difsum[10005] = {};
	
	for(int i=0; i<n; i++){
		int a,b;
		cin>>a>>b;
		array[i].first = a;
		array[i].second = b;
		MIN += a;
		MAX += b;
		dif.push(b-a);
	}
	
	int need = x-MIN;
	
	if(MAX < x || MIN > x){
		cout<<"No\n";
	}
	
	else{
		while(!dif.empty()){
			int a = dif.front();
			dif.pop();
			for(int i = 10000; i>=0; --i){
				if(difsum[i] == 1)
					difsum[i+a] = 1;
				
				else if(i == a)
					difsum[a] = 1;
			}
		}
	
		if(difsum[need] == 1 || need == 0)
			cout<<"Yes\n";
		
		else
			cout<<"No\n";
	}
	
	
				
return 0;
}

