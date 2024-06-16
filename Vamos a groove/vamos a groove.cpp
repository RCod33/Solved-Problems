//Encontrará la descripción del problema en el siguente enlace: 
//https://dmoj.uclv.edu.cu/problem/22psn3a

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
#define pi pair <int,int>
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



//!----MAIN--------------------------------------------------------------------------------------------
int main(){
IOS_B;

int t;
cin>>t;
	
	while(t--){
		int n;
		cin>>n;
		int array[n+5];		
		
		loop(i,0,n)
			cin>>array[i];
			
		int l=0,r=n/2;
		while(l<r){
			int m=(l+r+1)/2;
			int c=1,i=0;
			bool f=0,ex=0;
			
			while(i<n){
				if(array[i]==m && m==c && f==0)
					f=1;
				else if(array[i]==c && f==0)
					c++;
				else if(array[i]==c && f==1)
					c--;
				if(f==1 && c==0)
					ex=1;
					
					i++;
				}
				if(ex==1){
					l=m;
				}
				else	
					r=m-1;
			
		}
		
		cout<<l<<"\n";
		
	}


				
return 0;
}

