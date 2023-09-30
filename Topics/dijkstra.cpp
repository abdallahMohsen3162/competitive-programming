#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5 + 10;

ll n, m;
vector<vector<pair<ll, ll>>>adj;
ll oo = 1e17;
vector<ll>dist;

int par[1000000];
void Dijkstra(int starting_point){
    for(int i=0;i<=n;i++){
        dist[i] = oo;
    }
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>>pq;
    dist[starting_point] = 0;
    pq.push({0, starting_point});
    while(!pq.empty()){
        ll u = pq.top().second;
        ll d = pq.top().first;
        pq.pop();
        if(dist[u] < d) continue;
        for(auto e:adj[u]){
            ll v = e.second;
            ll c = e.first;
            if(dist[v] <= c+d) continue;
            if(dist[v] > c + d || dist[v] == oo){
                dist[v] = c+d;
                pq.push({dist[v], v});
                par[v] = u;
            }
        }
    }
}



void tc(){
    cin >> n >> m;
    dist.resize(n+1);
    adj.resize(n+1);
    memset(par, -1, sizeof par);

    ll u, v, w;
    for(int i=0;i<m;i++){
        cin >> u >> v >> w;
        adj[u].push_back({w, v});
        adj[v].push_back({w, u});
    }

    Dijkstra(1);
    if(dist[n] == oo){
        cout << "-1\n";
        return;
    }
    //path
    vector<int>path;
    int ending_point = n;
    int starting_point = 1;
    int i = ending_point;
    while(i != starting_point){
        path.push_back(i);
        i = par[i];
    }
    path.push_back(starting_point);
    reverse(path.begin(), path.end());
    for(int i=0;i<path.size();i++)
        cout << path[i] << ' ';
    
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