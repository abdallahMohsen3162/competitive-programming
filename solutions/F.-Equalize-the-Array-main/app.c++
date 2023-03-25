#include<iostream>
#include<map>
#include<algorithm>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include <set>
using namespace std;
#define ll long long 
#define yes cout<<"YES\n"
#define no cout<<"NO\n"

bool testCases = 1;

void bruteForce(set<int>cs,map<int,int>mp){
	int ans = 1e9;
	int sum = 0;
	for(auto c:cs){
		for(auto i:mp){
			if(i.second < c){
				sum += i.second;
			}else{
				sum += abs(i.second - c);
			}
		}
		ans = min(ans,sum);
		sum = 0;
	}
	cout<<ans<<endl;
}

void solve(){
	int n;
	cin>>n;
	map<int,int>mp;
	set<int>cs;
	while(n--){
		int x;
		cin>>x;
		mp[x]++;
	}
	for(auto i:mp){
		cs.insert(i.second);
	}
	bruteForce(cs,mp);

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

1 1 1 1 3

1->4
3->1



*/
