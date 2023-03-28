#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define yes cout<<"YES\n";
#define no cout<<"NO\n";
#define fi(n) for(int i=0;i<n;i++)
#define fj(n) for(int j=0;j<n;j++)
#define pb push_back
#define pp pop_back

template <class T> void pr(vector<T>vec){for(int i=0;i<vec.size();i++){cout<<vec[i]<<' ';}cout<<"\n";}
template <class T> void pr(T arr[],int n){for(int i=0;i<n;i++){cout<<arr[i]<<" ";}cout<<"\n";}
template <class T> void pr(T x){cout << x << endl;}
ll n , m;
const ll N = 1e5 + 5;
vector<ll>adj[N];
vector<bool> vis;
vector<ll>val;

ll ans = 0;
ll mn = LLONG_MAX;

void dfs(ll cur){
	if(vis[cur]) return;
	if(val[cur] < mn){
		mn = val[cur];
	}

	vis[cur] = 1;

	for(ll a:adj[cur]){
		if(vis[a]){
			continue;
		}//int
		dfs(a);
	}

	
}


void SSS(){
	cin >> n >> m;
	vis = vector<bool>(n,0);
	fi(n){
		ll c ; cin >> c;
		val.pb(c);
	}
	ll u , v;

	fi(m){
		cin >> u >> v;
		u--;
		v--;
		
		adj[v].pb(u);
		adj[u].pb(v);
	}

	

	for(ll i=0;i<n;i++){
		if(!vis[i]){
			dfs(i);
			ans += mn;
			mn = LLONG_MAX;
		}
	}
	pr(ans);
   	
}


int main()
{

   int t = 1; 
   // cin>>t;
   while(t--){
        SSS();
   }

    
	return 0;
}