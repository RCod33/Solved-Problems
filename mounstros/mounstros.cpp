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


//!----MACROS------------------------------------------------------------------------------------------
#define loop(i,a,b) for(int i=a;i<b;i++)
#define rloop(k,a,b) for(int k=a;k>b;k--)
#define vvi vector<vector<pair<int,int>>>
#define vi vector <int>
#define ii pair <int,int>
#define pb(a) push_back(a)
#define mk(a,b) make_pair(a,b)
#define all(x) x.begin(),x.end()
#define sz(x) ((x).size())
#define sza(x) sizeof(x)/sizeof(x[0])
#define fi first
#define se second
#define mset(a,b) memset(a,b,sizeof(a))
#define IOS_B ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
const int mod = 1e9 + 7;

using namespace std;
//!----Globales----------------------------------------------------------------------------------------

int c=1;
int const MAXN = 10e5 + 5;
long long dp[MAXN];

//!----FUNCIONES---------------------------------------------------------------------------------------



//!----MAIN--------------------------------------------------------------------------------------------
int main(){
IOS_B;
	
	int n;
	cin>>n;
	vi vec(n);
	
	loop(i,0,n)
		cin>>vec[i];
	
	sort(all(vec));
	
	dp[0] = vec[0];
	
	loop(i,1,n)
		dp [i] = dp[i-1] + vec[i];
		
	for(int i=n-2;i>=0;--i){
		if(dp[i]*2>=vec[i+1]){
			c++;
		}
		else
			break;	
	}

	cout<<c<<"\n";
				
return 0;
}

