#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define F first
#define S second
#define yes cout << "YES\n";
#define no cout << "NO\n";
#define all(v) v.begin(), v.end()

const int N = 2e5 + 1;
int n , a , b;
vector<int>adj[N];
int par[N];
bool vis[N];
int from = -1 , to = -1;
void dfs(int i, int p){
    vis[i] = 1;
    par[i] = p;
    for(int a:adj[i]){
        if(a != p){
            if(!vis[a]){

                dfs(a, i);
            }
            else{
                if(from == -1){
                    from = i,to = a;
                }
            }
        }
    }
}

void bfs(int start, vector<int>&dis){
    queue<pair<int, int>>q;
    int cur = start;
    dis[cur] = 0;
    q.push({cur, 0});
    while(!q.empty()){
        cur = q.front().F;
        int d = q.front().S;
        q.pop();
        if(dis[cur] == -1){
            dis[cur] = d;
        }
        for(int a:adj[cur]){
            if(dis[a] == -1){
                q.push({a,d+1});
            }
        }
    }
}

void Clear(int n){
    for(int i=0;i<n;i++){
        adj[i].clear();
        vis[i] = false;
        par[i] = -1;
    }
    from = -1 ;
    to = -1;
}
 
void tc(){  
    
    cin >> n >> a >> b;
    Clear(n);
    a--;
    b--;
    int u , v;
    for(int i=0;i<n;i++){
        cin >> u >> v;
        --u;v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int st = -1;
    for(int i=0;i<n;i++){
        if(adj[i].size() == 1) st = i;
    }
    if(a == b){
        no return;
    }
    
    if(st == -1){
        yes return;
    }
    

    dfs(st, st);

    vector<int>cycle;
    cycle.push_back(to);
    while(from != to){
        cycle.push_back(from);
        from = par[from];
    }
    // for(int a:cycle){
    //     cout << a + 1<< " ";
    // }
    // cout << "\n";
    vector<int>va(n+1, -1) , vb(n+1, -1);
    bfs(a, va);
    bfs(b, vb);
    for(int node:cycle){

        if(va[node] > vb[node]){
            // cout << va[node] << " "
            // << vb[node] << "\n";
            // cout << "node = " << node + 1 << "\n";
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while(t--) tc();
    return 0;
}