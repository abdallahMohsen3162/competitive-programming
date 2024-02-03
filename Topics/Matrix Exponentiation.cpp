/*
*
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
#define Matrix vector<vector<int>>
using namespace std;
using namespace __gnu_pbds;

void fio(){
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  cout.tie(nullptr);
}

template<typename T>
  
std::ostream& operator<<(std::ostream& os, const std::vector<T>& vec) {
    os << "[ ";
    for (const auto& i : vec) {
        os << i << " ";
    }
    os << "]";
    return os;
}

// find_by_order, order_of_key
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set; 
#define int long long
const int N = 1001;
const int mod = 1000000007;

vector<vector<int>> matmul(vector<vector<int>>A, vector<vector<int>>B){
  int n = A.size() , m = A[0].size() , p = B.size();
  vector<vector<int>>res(n, vector<int>(m, 0));
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; ++j){
      for(int k = 0; k < p; k++){
        res[i][j] += A[i][k] * B[k][j];
      }
    }
  }
  return res;
}


vector<vector<int>> mat_power(vector<vector<int>> x, int p) {
    vector<vector<int>>res(x.size(), vector<int>(x[0].size(), 0));
    for(int i = 0; i < x.size(); i++){
      res[i][i] = 1;
    }

    while (p) {
        if (p & 1) res = matmul(res , x);
        x = matmul(x , x);
        p >>= 1;
    }
    return res;
}

 
int fibonacci(int n) {
 
    vector<vector<int>> base = {
      {0,1,1,1},
      {1,0,1,1},
      {1,1,0,1},
      {1,1,1,0}
    };
    vector<vector<int>> result;
    vector<vector<int>> X = {
      {0},
      {0},
      {0},
      {1}
    };
    result = mat_power(base, n);
    result = matmul(result, X);


    return result[3][0] % mod;
}

void tc(){
  int n;
  cin >> n;
  cout << fibonacci(n) << "\n";
}


int32_t main(){
 
  // fio();
  
  int tt = 1; 
  // cin >> tt;
  while(tt--)tc();
  return 0;
}
