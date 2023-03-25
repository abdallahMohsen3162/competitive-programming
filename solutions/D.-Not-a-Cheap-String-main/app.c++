#include<iostream>
#include<algorithm>
#include<map>
#include<string>
#include<vector>
#include<stack>
using namespace std;
#define ll long long 
#define yes cout<<"YES\n"
#define no cout<<"NO\n"
/*97 -> 122*/

void solve(){
	
	string s;
	cin>>s;
	int p;
	cin>>p;
	int arr[27];
	for(int i=0;i<27;i++){
		arr[i] = 0;
	}

	int sum = 0;
	for(int i=0;i<s.length();i++){
		arr[(int)s[i] - 96]++;
		sum += (int)s[i] - 96;
	}

	if(sum < p){
		cout<<s<<endl;
		return;
	}

	int i = 26;
	while(sum > p){
		while(arr[i] > 0){
			sum -= i;
            arr[i]--;
            if(sum <= p) break;
		}
		i--;
		
	}

	for(int i = 0;i<s.length();i++){
		if(arr[(int)s[i] - 96] != 0){
			cout<<s[i];
			arr[(int)s[i] - 96]--;
		}
	}

	cout<<endl;
	 
}

int main()
{

	int t;
	cin>>t;
	
	while(t--){
		
		solve();
	}
	
	return 0;
}