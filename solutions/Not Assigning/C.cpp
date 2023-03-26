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


/*

vector<int>adj[N];
bool vis[N];

int counter = 0;

void dfs(int i){
   vis[i] = 1;
   for(int a:adj[i]){
      if(vis[a])continue;
      dfs(a);
   }
};


int conectedComponents(int){
   int cnt = 0;
   for(int i = 1;i<=n;++i){
      if(!vis[i]){
         cnt++;
         dfs(i);
      }
   }
   return cnt;
}
*/

const int N = 1e5 + 5;
int n;
vector<vector<int>>adj;
vector<bool>vis;
map<pair<int,int>,int>ans;
vector<pair<int,int>>edges;

void dfs(int i,bool even){
   vis[i] = 1;
   for(int a:adj[i]){
      if(!vis[a]){
         int x;
         if(even){
            x = 2;
         }else{
            x = 3;
         }
         pair<int,int>p = {i,a};
         pair<int,int>pp = {a,i};
         ans[p] = x;
         ans[pp] = x;
         dfs(a,!even);

      }
   }

}







void SSS(){
   cin >> n;

   
   vis = vector<bool>(N,0);
   adj = vector<vector<int>>(n+1);
   edges.clear();


   fi(n-1){
      int v , u; 
      cin >> v >> u;
      adj[v].pb(u);
      adj[u].pb(v);
      edges.pb({v,u});
   }

   for(int i = 1;i<=n;++i){
      if(adj[i].size() > 2){
         // cout << "i= "<< i<<"\n";
         pr(-1);
         return;
      }
   }
   int start = 1;
   for(int i=1;i<=n;++i){
      if(adj[i].size() == 1){
         start = i;
         break;
      }
   }



   

   dfs(start,0);

   for(auto i:edges){
      cout << ans[i]<<' ';
   }
   cout<<"\n";


  
   
}

int main()
{

   int t = 1; 
   cin>>t;
   while(t--){
        SSS();
   }

    
	return 0;
}