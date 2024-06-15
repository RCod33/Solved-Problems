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



//!----FUNCIONES---------------------------------------------------------------------------------------



//!----MAIN--------------------------------------------------------------------------------------------
int main(){
IOS_B;

	int n;
	cin>>n;
	priority_queue<int> q;
	
	loop(i,0,n){
		int a;
		cin>>a;
		q.push(a);
	}
		
	int a, b, c = 0;
	
	while(!q.empty()){
		a = q.top();
		q.pop();
		if(q.empty()){
			c += a;
			break;
		}
		b = q.top();
		q.pop();
		
		c += b;
		
		if(a-b != 0)
			q.push(a-b); 
		
	}
			
	cout<<c<<"\n";
		
return 0;
}
/*
18
959 905 837 822 785 737 680 677 659 577 486 352 286 263 261 152 127 114
*/
