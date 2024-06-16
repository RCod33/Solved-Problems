//Encontrará la descripción del problema en el siguente enlace: 
//https://dmoj.uclv.edu.cu/problem/froma2b

//!----LIBRERIAS---------------------------------------------------------------------------------------
#include <iostream>
//#include <vector>
#include <algorithm>
//#include <math.h>
//#include <memory.h>
//#include <set>
//#include <map>
//#include <queue>
#include <stack>
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

stack<int> sk;

//!----FUNCIONES---------------------------------------------------------------------------------------

bool check(int b, int a){
	if(b<a)
		return 0;
	sk.push(b);
	if(b == a)
		return 1;
	if(b%2 == 0)
		return check(b/2,a);
	if(b%10 == 1)
		return check((b-1)/10,a);
	return 0;
}


//!----MAIN--------------------------------------------------------------------------------------------
int main(){
IOS_B;

	int a,b;
	cin>>a>>b;
	
	if(check(b,a) == 0){
		cout<<"NO\n";
	}
	else{
		cout<<"YES\n";
		cout<<sk.size()<<"\n";
		while(!sk.empty()){
			int x = sk.top();
			sk.pop();
			cout<<x<<" ";
			}
		cout<<"\n";
	}

	

				
return 0;
}

