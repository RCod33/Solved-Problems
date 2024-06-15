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
#include <string>
#include <bits/stdc++.h>
 
 
//!----MACROS------------------------------------------------------------------------------------------
#define int long long
#define vi vector <int>
#define vvi vector<vector<int>>
#define vvii vector<vector<pair<int,int>>>
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
const long long mod = (2e18 + 7);
 
 
using namespace std;
//!----Globales----------------------------------------------------------------------------------------
 
vector<long long> st(4*200000, mod), lazy(4*200000, 0);
 
//!----FUNCIONES---------------------------------------------------------------------------------------
 
void build(vector<long long>& a, int node, int l, int r){
	if(l == r)
		st[node] = a[l];
	else{
		build(a, left);
		build(a, right);
		
		st[node] = min(st[node*2], st[node*2+1]);
	}
}
 
void update(int node, int l, int r, int x, int y, long long val){
	
	if(lazy[node] != 0){
		st[node] += lazy[node];
		
		if(l != r){
			lazy[node*2] += lazy[node];
			lazy[node*2+1] += lazy[node];
		}
		
		lazy[node] = 0;
	}
	if(l>r || l>x || r < y || x>y)
		return;
	if(l == x && r == y){
		st[node] = st[node] + val;
		
		if(l != r){
			lazy[node*2] += val;
			lazy[node*2+1] += val;
		}
		
		return;
	}
	
	update(left, x, min(y, mid), val);
	update(right, max(mid+1, x), y, val);
	
	st[node] = min(st[node*2], st[node*2+1]);
}
 
long long query(int node, int l, int r, int x, int y){
	if(lazy[node] != 0){
		st[node] += lazy[node];
		
		if(l != r){
			lazy[node*2] += lazy[node];
			lazy[node*2+1] += lazy[node];
		}
		
		lazy[node] = 0;
	}
	if(l>r || l>x || r < y || x>y)
		return mod;
	if(l == x && r == y){
		return st[node];
	}
	
	return min(query(left, x, min(y, mid)), query(right, max(mid+1, x), y));
}
 
 
//!----MAIN--------------------------------------------------------------------------------------------
main(){
IOS_B;
 
	long long n;
	cin>>n;
	vector<long long> vec(n);
	
	for(int i = 0; i<n; ++i){
		cin>>vec[i];
	}
 
	build(vec, 1, 0, n-1);
 
	long long m;
	cin>>m;
	string h;
	getline(cin, h);
	
	while(m--){
		string s;
		getline(cin, s);
		istringstream ss(s);
		long long w = 0;
		int num;
		while(ss >> num)
			w++;
	
		if(w == 2){
			long long array[2] = {};
			long long k = 0;
			long long i = 0;
			while(w>0){
				for(i; i<s.size(); ++i){
					if(s[i] != ' '){
						array[k] *= 10;
						array[k] += (s[i]-'0');
					}
					else
						break;
				}
				i++;
				k++;
				w--;
			}
			
			if(array[0] <= array[1]){
				cout<<query(1, 0, n-1, array[0], array[1])<<"\n";
			}
			else{
				long long a  = query(1, 0, n-1, array[0], n-1);
				long long b = query(1, 0, n-1, 0, array[1]);
				cout<<min(a,b)<<"\n";
			}
		}
		else{
			long long array[3] = {};
			long long k = 0;
			long long i = 0;
			while(w>0){
				bool f = 0;
				for(i; i<s.size(); ++i){
					if(s[i] != ' '){
						if(s[i] == '-'){
							f = 1;
							continue;
						}
						array[k] *= 10;
						array[k] += (s[i]-'0');
					}
					else
						break;
				}
				if(f == 1)
					array[k] *= (-1);
				i++;
				k++;
				w--;
			}
			
			if(array[0] <= array[1]){
				update(1, 0, n-1, array[0], array[1], array[2]);
			}
			else{
				update(1, 0, n-1, array[0], n-1, array[2]);
				update(1, 0, n-1, 0, array[1], array[2]);			
			}
		}
	}
	
return 0;
}