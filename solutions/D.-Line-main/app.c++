#include<iostream>
#include<map>
#include<algorithm>
#include<cmath>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include <set>
using namespace std;
#define ll long long 
#define yes cout<<"YES\n"
#define no cout<<"NO\n"
#define fi(n) for(int i=0;i<n;i++)
#define fj(n) for(int j=0;j<n;j++)
#define pb push_back
#define p(n) cout << n << endl
const int N = 2*1e5 + 5;
bool testCases = 1;

bool gt(pair<int,int> a,pair<int,int> b){
	return a.first > b.first;
}

void solve(){
	int n; cin>>n;
	string s;
	cin>>s;
	vector<int>pre;
	vector<pair<int,int>>opt;
	int i = 0;
	ll sum = 0;
	for(char c:s){
		if(c == 'L'){
			sum += i;
			pre.pb(i);
		}else{
			sum += (n-i-1);
			pre.pb(n-i-1);
		}
		++i;
	}

	fi(n){
		int mx = max(i,n-i-1);
		if(pre[i] != mx){
			opt.pb({mx,i});
		}
	}
	
	sort(opt.begin(),opt.end(),gt);
	int k = 0;
	fi(opt.size()){
		sum -= pre[opt[i].second];
		sum += opt[i].first;
		cout<<sum<<' ';
		k++;
	}
	while(k<n){
		cout<<sum<<' ';
		k++;
	}
	cout<<endl;

	
}; 



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



/*
a="abc"  b = "abcd"

abcabcd
   i 



*/