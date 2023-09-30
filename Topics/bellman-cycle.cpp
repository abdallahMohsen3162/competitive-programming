#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 600;
const ll oo = 1e12;
bool negative_cycle = false;
vector<int>relax;
vector<ll> bellman_ford(int n, int src, vector<vector<int>>&edges){
    //init all nodes as infinity dist
    vector<ll>dist(n+1, oo);
    dist[src] = 0;
    //relax all edges
    int x = -1;
    for(int i=0;i<n-1;i++){
        for(auto edge:edges){
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            if(dist[u] + w < dist[v]){
                relax[v] = u;
                dist[v] = w + dist[u];
                x = v;
            }
        }
    }
    //negative weight cycle
    for(auto edge:edges){
        int u = edge[0];
        int v = edge[1];
        int w = edge[2];
        if(dist[u] + w < dist[v]){
            negative_cycle = true;
            relax[v] = u;
            x = v;
            break;
        }
    }

    if(negative_cycle == false){
        cout << "NO\n";
    }else{
        
        for(int i = 1;i<=n;i++){
            x = relax[x];
        }

        vector<int>cycle;
        for(int v=x;;v=relax[v]){
            cycle.push_back(v);
            if(v == x &&cycle.size()>1)break;
        }
        reverse(cycle.begin(), cycle.end());

        cout << "YES" << endl;
        for(auto v: cycle)
        {
            cout << v << " ";
        }
    }

    return dist;
}


void tc(){
    int n , m ; cin >> n>> m;
    vector<vector<int>>edges;
    relax.resize(n+1, -1);
    for(int i=0;i<m;i++){
        int u , v , w;
        cin >> u>>v>>w;
        edges.push_back({u,v,w});
    }

    vector<ll>dist = bellman_ford(n, 1, edges);



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
