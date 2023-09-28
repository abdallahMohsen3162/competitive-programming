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
void dfs(int i = 1, int p = 1){
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
 
void tc(){  
    
    cin >> n;

    int u , v;
    for(int i=0;i<n;i++){
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    

    dfs();

    vector<int>cycle;
    cycle.push_back(to);
    while(from != to){
        cycle.push_back(from);
        from = par[from];
    }
    for(int a:cycle){
        cout << a << " ";
    }
    cout << "\n";

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