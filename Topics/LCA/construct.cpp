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

void dfs(int u, int depth, int par){
	dep[u] = depth;
	p[u] = par;

	for(int e: adj[u]){
		if(e == par) continue;
		dfs(e, depth + 1, u);
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







