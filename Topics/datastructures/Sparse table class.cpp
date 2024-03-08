const int N = 2e5 + 1;

int dpPow[N];
class SparseTable{
private:
  vector<int> arr;
  vector<vector<int>> T;
  int n, LOG;
  int merge(int x, int y){
    return min(x, y);
  }
public:

  void build(){
    
    for(int i = 0; i < n; i++){
      T[i][0] = arr[i];
    }

    for(int pw = 1; (1 << pw) <= n; pw++){
      for(int i = 0; i + (1 << pw) <= n; i++){
        T[i][pw] = merge(T[i][pw - 1], T[i+(1<<(pw-1))][pw - 1]);
      }
    }
  }

  SparseTable(vector<int>&v){
    arr = v;
    n = arr.size();
    LOG = __lg(n) + 1;
    T.resize(n + 1, vector<int>(LOG, 1e9));
  }

  int query(int l, int r) {
    int sz = r - l + 1;
    int ret = 1e9;
    for(int i = 21; i >= 0; i--){
      if((sz >> i) & 1){
        ret = merge(ret, T[l][i]);
        l += (1 << i);
      }
    }
    return ret;
  }
  int fastQuery(int l, int r){ // Require dpPow , do (dpPow[i] = dpPow[i >> 1] + 1)
    int sz = r - l + 1;
    int pw = dpPow[sz];
    return merge(T[l][pw], T[r - (1 << pw) + 1][pw]);
  }

  void dbg(){
    for(int i = 0; i < n; i++){
      for(int j = 0; j < LOG; j++){
        cout << T[i][j] << ' ';
      }
      cout<<"\n";
    }
  }

};
