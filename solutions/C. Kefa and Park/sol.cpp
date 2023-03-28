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

int n,m;
const int N = 1e5 + 5;
vector<int>adj[N];
vector<int> val;
bool vis[N];
int counter = 0;

void dfs(int i,int cats){
   vis[i] = 1;
   cats += val[i];
   if(val[i] == 0){
      cats = 0;
   }
   
   if(cats > m){
      return;
   }
   bool is_leaf = true;
   for(int a:adj[i]){
      if(vis[a]) continue;
      is_leaf = false;
      dfs(a,cats);

   }
   
   if(is_leaf)
      counter++;

}


void SSS(){
   cin >> n >> m;
   fi(n){
      int x; cin >> x;
      val.pb(x);
   }
   int u , v;
   fi(n-1){
      cin >> u >> v;
      u--;
      v--;
      adj[v].pb(u);
      adj[u].pb(v);
   }
   dfs(0,0);
   cout <<counter<<"\n";
   

   
}


int main()
{

   int t = 1; 
   // cin>>t;
   while(t--){
        SSS();
   }

    
	return 0;
}
 