const int N = 2e5 + 1 , SQ = 448;
vector<vector<int>> b(SQ);
vector<int>blk(SQ, 0);
vector<int> arr;
void preprocess(int n)
{
  for(int i = 0; i < n; i++){
    b[i/SQ].push_back(arr[i]);
    blk[i/SQ] += arr[i];
  }
}
 
void update(int idx, int val){
  int bidx = idx / SQ, arridx = idx % SQ;
  blk[bidx] -= arr[idx];
  blk[bidx] += val;
  arr[idx] = val;
  b[bidx][arridx] = val;
}
 
int query(int l, int r){
  int ret = 0;
  while(l <= r){
    if(l % SQ == 0 && l + SQ <= r){
      ret += blk[l / SQ];
      l += SQ;
    } else {
      ret += arr[l++];
    }
  }
  return ret;
}
