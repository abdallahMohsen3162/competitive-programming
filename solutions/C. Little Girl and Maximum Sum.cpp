/*
* @author: Abdllah mohsen
*
*/


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
#define debug(xx) cout << (#xx) << " = " << xx << endl;
#define ll long long
#define sprt cout << "--------------------\n";
using namespace std;
using namespace __gnu_pbds;
void fio(){
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  cout.tie(nullptr);
}
// find_by_order, order_of_key
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set; 
const int N = 3e5 + 1;
int n;
vector<vector<int>>adj;
string s;

int dp[N];

int slv(int i){
  if(adj[i][0] == -1 && adj[i][1] == -1){
    return 0;
  }
  int ret = 1e9;
  if(dp[i] != -1){
    return dp[i];
  }
  if(adj[i][0] != -1){
    ret = min(ret,  (s[i] != 'L') +  slv(adj[i][0]));
  }

  if(adj[i][1] != -1){
    ret = min(ret,  (s[i] != 'R') +  slv(adj[i][1]));
  }

  return dp[i] = ret;
}

void tc() {
  
  cin >> n;
  adj.resize(n+1, vector<int>(2, 0));
  cin >> s;
  for(int i = 0; i < n; i++){
    int u , v;
    cin >> u >> v;
    u--;
    v--;
    adj[i][0] = u;
    adj[i][1] = v;
    dp[i] = -1;
  }
  cout << slv(0) << "\n";


} 
 

int32_t main(){
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int tt = 1; 
  cin >> tt;
  while(tt--)tc();
  return 0;
}


/*
MesloLGS NF
*/
