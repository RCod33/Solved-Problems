//Encontrará la descripción del problema en el siguente enlace: 
//https://dmoj.uclv.edu.cu/problem/2023orcop10c

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



//!----FUNCIONES---------------------------------------------------------------------------------------



//!----MAIN--------------------------------------------------------------------------------------------
int main(){
IOS_B;

	long long n, c = 0;
	cin>>n;
	string s = to_string(n);
	
	while(n%3 != 0){
		c++;
		int x = n%3, pos = -1;
		bool f = 0;
		
		if(s.size() == 1){
			cout<<-1<<"\n";
			return 0;
		}
		
		for(int i = 0; i<s.size(); ++i){
			if(s[i]%3 == x){
				f = 1;
			}
		}
		if(f == 1){
			cout<<c<<"\n";
			return 0;
		}
		else{
			n -= (n%10);
			n /= 10;
			s = to_string(n);
		}
	}
	
	cout<<0<<"\n";

				
return 0;
}

