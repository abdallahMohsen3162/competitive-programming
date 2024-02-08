vector<int> arr;
const int N = 2e5 + 10;
int T[N][22];
int n ;

int merge(int x, int y){
  return min(x, y);
}

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

int query(int l, int r){
  int sz = r - l + 1;
  int ret = LLONG_MAX;
  for(int i = 21; i >= 0; i--){
    if((sz >> i) & 1){
      ret = merge(ret, T[l][i]);
      l += (1 << i);
    }
  }
  return ret;
}


