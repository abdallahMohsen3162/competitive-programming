#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 600;
 
const ll oo = 1e15;
vector<vector<ll>>G;
 
void floydWarshall()
{
    int v = G.size();
    for(int k=0;k<v;k++){
 
        for(int i=0;i<v;i++){
 
            for(int j=0;j<v;j++){
                G[i][j] = min(G[i][j], G[i][k] + G[k][j]);
            }
 
        }
 
    }
    
}
 
void tc(){
    int n , m , q;
    cin >> n >> m >> q;
    G.resize(n, vector<ll>(n, oo));
    for(int i=0;i<n;i++){
        G[i][i] = 0;
    }
    for(int i=0;i<m;i++){
        ll u , v , w;
        cin >> u >> v >> w;
        v--;
        u--;
        G[u][v] = min(w,G[u][v]);
        G[v][u] = min(w,G[v][u]);
    }
 
    floydWarshall();
 
    while(q--){
        int u , v;
        cin >> u >> v;
        u--;
        v--;
        if(G[u][v] == oo)
            cout << -1 << "\n";
        else
            cout << G[u][v] << "\n";
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
