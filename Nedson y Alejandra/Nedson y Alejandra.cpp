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


//!----FUNCIONES---------------------------------------------------------------------------------------

long long count(string& X, string& Y, int m, int n,long long dp[][5]){
	

    if (m == 1 && n == 1) {
        return (X[0] == Y[0]);
    }
 
    
    if (m == 0) {
        return 0;
    }
 
    
    if (n == 0) {
        return 1;
    }
 
    
    if (n > m) {
        return 0;
    }
    
    if(dp[m][n] != -1)
		return dp[m][n];
 
    return dp [m][n] = ((X[m - 1] == Y[n - 1]) ? count(X, Y, m - 1, n - 1,dp) : 0) +
        count(X, Y, m - 1, n,dp);
}
 
int main(){
	int n;
	cin>>n;
    string s; 
	cin>> s;  
    string sub = "papa";           

	long long dp [n+5][5];
	
	loop(i,1,n+5)
		loop(k,1,5)
			dp[i][k] = -1;
 			 		
    cout << count(s, sub, s.size(), sub.size(),dp);
 
    return 0;
}