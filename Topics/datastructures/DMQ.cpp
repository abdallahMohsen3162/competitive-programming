const int N = 2e5 + 10 , SQ = 448;
vector<vector<int>> b(SQ);
vector<int>blk(SQ, 1e10);
vector<int> arr;
 
void preprocess(int n)
{
  for(int i = 0; i < n; i++){
    b[i/SQ].push_back(arr[i]);
    blk[i/SQ] = min(arr[i], blk[i/SQ]);
  }
}
 
void update(int idx, int val){
  int blk_idx = idx / SQ, idx_in_blk = idx % SQ;
  arr[idx] = val;
  b[blk_idx][idx_in_blk] = val;
  blk[blk_idx] = *min_element(all(b[blk_idx]));
}
 
int query(int l, int r){
  int ret = 1e10;
  while(l <= r){
    if(l % SQ == 0 && l + SQ <= r){
      ret = min(blk[l / SQ], ret);
      l += SQ;
    } else {
      ret = min(arr[l], ret);
      l++;
    }
  }
  return ret;
}
