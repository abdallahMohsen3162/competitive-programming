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


vector<int> divs(int x){
	vector<int>res;
	int i = 2;
	for(i = 2; i <= x/i ; ++i){
		if(x % i == 0){
			int a = x / i , b = i;
			res.pb(a);
			if( a != b)
				res.pb(b);
			
		}
	}
	return res;
}

bool is_prime(int x){
	if(x == 1){
		return 0;
	}
	for(int i = 2 ; i * i <= x ; ++i){
		if(x % i == 0) return 0;
	}
	return 1;
}

vector<pair<int,int>> factors(int n){
	vector<pair<int,int>>res;
	for(int i=2;i*i<=n;++i){
		int cnt = 0;
		while(n % i == 0){
			cout<<"i = " << i<<"\n";
			n /= i;
			cnt++;
		}
		res.pb({i,cnt});
	}
	
 	if(n>1)res.pb({n,1});
	return res;
}

vector<bool> sieve(int n){
	vector<bool>prime(n+1,1);
	//return 0 0 1 1 0 1 0 1 . . . (n+1)
	prime[0] = 0;
	prime[1] = 0;
	
	for(int i=2;i <= n;i++){
		if(prime[i] == 1){
			for(int j=i+i; j<=n ;j += i){
				prime[j] = 0;
			}
		}
	}
	return prime;
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



int gcd(int a,int b){
	pair<int,int>g = {max(a,b),min(a,b)};
	while(g.first != 0 && g.second != 0){
		g = {g.first - g.second,g.second};
		g = {max(g.first,g.second),min(g.first,g.second)};
	}
 
	if(g.second == 0){
		return g.first;
	}

	return g.second;
}


int nod(int x){
	if(x == 1){
		return 1;
	}
	int cnt = 2;

	for(int i=2;i*i<=x;i++){
		if(x % i == 0){
			int a = x / i;
			cnt++;
			if(a != i){
				cnt++;
			}
		}
	}
	return cnt;
}
ll lcm(ll a , ll b){
	return (a * b) / gcd(a,b);
}
ll power(ll a,ll b){
	ll res = 1;
	while (b)
	{
		if(b&1){
			res *= a;
		}
		a *= a;
		b = (b>>1);
	}
	return res;
}

ll n, q; 
const ll N = 2e5 + 5;
vector<ll>adj[N];
vector<ll>ans;
map<ll,ll>mp;
ll vert[N];

void dfs(ll cur){
	ans.pb(cur);
	for(ll a:adj[cur]){
		dfs(a);
	}
	vert[cur]++;
	for(ll a:adj[cur]){
		vert[cur] += vert[a];
	}
}



void solve(){
	// memset(vert,1,sizeof(vert));
	cin >> n >> q;
	for(ll i=0;i<n-1;i++){
		ll x; 
		cin >> x;
		adj[x].pb(i + 2);
	}

	dfs(1);
	
	for(ll i=0;i<ans.size();i++){
		mp[ans[i]] = i;
	}
	
	
	while(q--){
		ll u , v;
		cin >> u >> v;
		v--;
		ll ind = mp[u];
		if(v + 1 > vert[u]){
			pr(-1);
		}else{
			pr(ans[ind + v]);
		}
		
	}

		
}

int main()
{

    int tt = 1;

	// cin >> tt;

	while(tt--){
		solve();
	}
	return 0;
}