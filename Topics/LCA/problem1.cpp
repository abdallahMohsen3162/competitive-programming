/*
*
* @author: Abdllah mohsen
*
*/
// https://cses.fi/problemset/task/1688

#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define F first
#define S second
#define pb push_back
#define pp pop_back
#define yes cout << "Yes\n";
#define no cout << "No\n";
#define all(stl) stl.begin(), stl.end()
#define mem(DATASTRUC, VAL) memset(DATASTRUC,  VAL, sizeof(DATASTRUC))
#define dbg(xx) cout << (#xx) << " = " << xx << endl;
#define ll long long
#define sprt cout << "--------------------\n";
#define pii pair<int, int>
using namespace std;
using namespace __gnu_pbds;

void fio(){
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  cout.tie(nullptr);
}
template<typename T>
  
std::ostream& operator<<(std::ostream& os, const std::vector<T>& vec) {
    os << "[ ";
    for (const auto& i : vec) {
        os << i << " ";
    }
    os << "]";
    return os;
}

// find_by_order, order_of_key
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set; 

 
const int N = 2e5 + 10;
const int LOG = 20;
int n , q;
int p[N], dp[N][LOG];
int dep[N];
 
vector<int> adj[N];

void con(){
	for(int pw = 0; pw < LOG; pw++){
		for(int i = 1; i <= n; i++){
			if(pw == 0){
				dp[i][pw] = p[i];
			}else{
				dp[i][pw] = dp[dp[i][pw-1]][pw-1];
			}
		}
	}
}
 
 
int query(int u, int up){
  for(int i = 30; i >= 0; i--){
  	if(up >= (1 << i)){
  		u = dp[u][i];
  		up -= (1 << i);
  	}
  }
  return u;
}

void dfs(int u, int depth){
	dep[u] = depth;
	// cout  << u << " : " << depth << "\n";
	for(int e: adj[u]){
		dfs(e, depth + 1);
	}
}

int LCA(int u, int v){
	if(dep[u] > dep[v]){
		swap(u, v);
	}
	v = query(v, abs(dep[u] - dep[v]));
	int ans = v;

	if(u == v){
		return u;
	}

	for(int mask = LOG - 1; mask >= 0; mask--){
		if(dp[u][mask] == dp[v][mask]){
			continue;
		}
		u = dp[u][mask];
		v = dp[v][mask];
		
	}
	return dp[v][0];
}
 
void tc(){  
	cin >> n >> q;
	for(int i = 2; i <= n; i++){
		cin >> p[i];
		adj[p[i]].pb(i);
	}


	dfs(1, 0);
	con();

	while(q--){
		int u, v;
		cin >> u >> v;
		cout << LCA(u, v) << "\n";
	}
}


int32_t main(){
 
  // fio();

  int tt = 1; 
  // cin >> tt;
  while(tt--)tc();
  return 0;
}
