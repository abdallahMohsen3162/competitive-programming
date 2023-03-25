#include<iostream>
#include<map>
#include<algorithm>
#include<cmath>
#include<string>
#include<iomanip>
#include<vector>
#include<stack>
#include<queue>
#include <set>
using namespace std;
#define ll long long 
#define yes cout<<"YES\n";
#define no cout<<"NO\n";
#define fi(n) for(int i=0;i<n;i++)
#define fj(n) for(int j=0;j<n;j++)
#define pb push_back

template <class T>
void p(vector<T>vec){
	for(int i=0;i<vec.size();i++){
		cout<<vec[i]<<' ';
	}
	cout<<"\n";
}
template <class T>
void p(T arr[],int n){
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<"\n";
}
template <class T>
void p(T x){
	cout << x << endl;
}

ll UNIQUE_SEGMENTS_OF_STRING(string STRING){
	return unique(STRING.begin(),STRING.end()) - STRING.begin();
}

vector<vector<int>> PREFIX2D(vector<vector<int>>arr){
	int m = arr[0].size();
	int n = arr.size();
	vector<vector<int>>res(n+1);

	for(int i=0;i<=n;i++){
		for(int j=0;j<=m;j++){
			res[i].pb(0);
		}
	}

	 // the segments bounded by r1,r2,c1,c2 = res[r2][c2] - res[r1][c2] - res[r2][c1] + res[r1][c1];
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			res[i][j] = arr[i-1][j-1] + res[i][j-1] + res[i-1][j] - res[i-1][j-1];
		}
	}
	return res;
}
struct oper{
	ll l,r,val;
};
const int N = 2*1e5 + 5;
bool testCases = 0;

void solve(){

	ll n , m , k; cin >> n >> m >> k;
	ll arr[n];
	ll prefix[n+1];
	prefix[0] = 0;
	for(ll i = 0;i<=n;i++){
		prefix[i]  = 0;
	}
	for(ll i = 0;i<n;i++){
		cin>>arr[i];
	}
	vector<oper>v(m);
	fi(m){
		oper o;
		cin >> o.l;
		cin >> o.r;
		cin >> o.val;
		o.l--;
		o.r--;
		v[i]=o;
	}
	ll exec[m+1];
	fi(m+1){
		exec[i] = 0;
	}
	fi(k){
		ll st,en; cin>>st>>en;
		st--;
		en--;
		exec[st]++;
		exec[en+1]--; 
		
	}
	for(ll i = 1;i<m;i++){
		exec[i] += exec[i-1];
	}
	for(ll i = 0;i<m;i++){
		ll freq = exec[i];
		ll val = v[i].val * freq;
		prefix[v[i].l] += val;
		prefix[v[i].r+1] -= val;
	}


	ll sum = 0;
	for(ll i=0;i<n;i++){
		sum += prefix[i];
		cout << arr[i] + sum << " ";
	}
	p("");
} 
int main()
{
	

    int tt = 1;
	if(testCases)
        cin>>tt;
    
	while(tt--){
		solve();
	}
	


	
	return 0;
}

