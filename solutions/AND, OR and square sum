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

const int N = 2*1e5 + 5;
bool testCases = 0;

void solve(){
	int n; cin>>n;
	vector<int>v(25);
	fi(n){
		int x;
		cin>>x;
		fj(20){
			if(((x>>j)&1)){
				v[j]++;
			}
		}
	}
	ll res = 0;
	for(int i=0;i<n;i++){
		ll cur = 0;
		for(int j=0;j<20;j++){
			if(v[j] != 0){
				v[j]--;
				cur += pow(2,j);
			}
		}
		res += cur * cur;
		// cout << cur <<' ';
	}
	

	p(res);
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
 
