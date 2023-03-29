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

const int N = 2*1e5 + 5;

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
int n,m,k;
bool vis[505][505];
char Grid[505][505];

bool valid(int i,int j){
	return (i>=0 && i<n && j>=0 && j < m);
}

int D = 0;
int dx[] = {0,0, 1 ,-1};
int dy[] = {1,-1,0, 0};


void dfs(int i,int j){
	if(k == 0) return;
	vis[i][j] = 1;
	for(int c =0;c<4;++c){
		if(valid(i+dx[c],j+dy[c]) && !vis[i+dx[c]][j+dy[c]]){
			if(Grid[i+dx[c]][j+dy[c]] == '.'){
				dfs(i+dx[c], j+dy[c]);
			}
			
		}
	}
	if(k == 0) return;
	Grid[i][j] = 'X';
	k--;
	

	

}


void solve(){
	cin >> n >>m >> k;
	memset(vis,0,sizeof(vis));
	fi(n){
		fj(m){
			cin >> Grid[i][j];
		}
	}

	fi(n){
		fj(m){
			if(k == 0){
				break;
			}
			if(Grid[i][j] == '.'){
				dfs(i,j);
			}
		}
		if(k == 0){
			break;
		}
	}
	
	fi(n){
		fj(m){
			cout <<Grid[i][j];
		}
		pr("");
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