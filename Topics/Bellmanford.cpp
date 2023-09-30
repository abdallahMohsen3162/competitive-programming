#include<bits/stdc++.h>
using namespace std;
#define ll long long


vector<int> bellman_ford(int n, int src, vector<vector<int>>&edges){
	//init all nodes as infinity dist
	int oo = 1e9;
	vector<int>dist(n+1, oo);
	dist[src] = 0;
	//relax all edges
	for(int i=0;i<n-1;i++){
		for(auto edge:edges){
			int u = edge[0];
			int v = edge[1];
			int w = edge[2];
			if(dist[u] + w < dist[v] && dist[u] != oo){
				dist[v] = w + dist[u];
			}
		}
	}
	//negative weight cycle
	bool negative_cycle = false;
	for(auto edge:edges){
		int u = edge[0];
		int v = edge[1];
		int w = edge[2];
		if(dist[u] + w < dist[v] && dist[u] < oo){
			cout << "Negative weight cycle\n";
			negative_cycle = true;
			break;
		}

	}
	return dist;
}

void tc(){
	int n, m;
	cin >> n >> m;

	vector<vector<int>> edges;//edge list [u ,v , w]

	for(int i=0;i<n;i++){
		int u,v,w;
		cin >> u >> v >> w;
		edges.push_back({u, v, w});
	}
	//call algorithm function
	vector<int>dist = bellman_ford(n, 1, edges);


	for(int i=1;i<=n;i++){
		cout << i << " => " << dist[i] << "\n";
	}
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt = 1; 
    // cin >> tt;
    while(tt--)tc();
    return 0;
}

/*

3 3
1 2 3
2 3 4
3 1 -10

*/