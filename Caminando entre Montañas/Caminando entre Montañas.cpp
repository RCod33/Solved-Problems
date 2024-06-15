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

int dp[20][20];
int mx[20][20];


//!----FUNCIONES---------------------------------------------------------------------------------------

/*void grid(int n, int m, int k){
	if(n>k)
		return;
	if(m>k)
		return;
	
	dp[n][m] += min(dp[n][m],min((mx[n-1][m] >= mx[n][m]) ? (dp[n-1][m]) : 
		(abs(mx[n][m-1] - mx[n][m])+dp[n][m-1]),(mx[n][m-1] >= mx[n][m]) ? (dp[n][m-1]) : 
		(abs(mx[n][m-1] - mx[n][m])+dp[n][m-1])));
	
	grid(n+1,m,k);
	grid(n,m+1,k);
}*/

/*int grid(int n, int m){
	if(n == 1 && m == 1)
		return dp[1][1];
	if(dp[n][m] != mod)
		return dp[n][m];
	
	grid(n-1,m);
	grid(n,m-1);
			
	return dp[n][m] += min((mx[n-1][m] > mx[n][m]) ? dp[n-1][m] : dp[n-1][m] 
	+ abs(mx[n-1][m] - mx[n][j]),(mx[n-1][m] > mx[n][m]) ? dp[n-1][m] : dp[n-1][m] 
	+ abs(mx[n-1][m] - mx[n][j]));
}*/


void grid(int n){
	
	for(int i = 2; i<=n; i++)
		for(int k = 2; k<=n; k++){
			dp[i][k] = min((mx[i-1][k] >= mx[i][k]) ? dp[i-1][k] : 
				dp[i-1][k] + abs(mx[i-1][k] - mx[i][k]),(mx[i][k-1] >= mx[i][k]) ? dp[i][k-1] : 
				dp[i][k-1] + abs(mx[i][k-1] - mx[i][k]));
		}
}

//!----MAIN--------------------------------------------------------------------------------------------
int main(){
IOS_B;

	int n;
	cin>>n;
	
	
	for(int i = 1;i<=n;i++)
		for(int j = 1;j<=n;j++){
			char ch;
			cin>>ch;
			mx[i][j] = (ch - '0');
		}
		
	for(int i = 2;i<=n;i++)
		for(int j = 2;j<=n;j++){
			dp[i][j] = mod;
		}

		for(int j = 2;j<=n;j++){
			dp[1][j] += (mx[1][j-1] >= mx[1][j]) ? dp[1][j-1] : abs(mx[1][j-1] - mx[1][j])+dp[1][j-1];
			dp[j][1] += (mx[j-1][1] >= mx[j][1]) ? dp[j-1][1] : abs(mx[j-1][1] - mx[j][1])+dp[j-1][1];
		}



	grid(n);
	
	int x,y;
	
	cin>>x>>y;
	
	cout<<dp[x][y];
				
return 0;
}

/*
10
9412364578
1234567891
2345678912
3456789123
4567891234
5678912345
6789123456
7891234567
8912345678
9123456789
*/

