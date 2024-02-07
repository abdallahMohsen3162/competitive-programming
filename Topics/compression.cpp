vector<int> compression(vector<int> arr){
  int n = arr.size();
  vector<int> v = arr ;
  vector<int> ret(n) ;
  sort(all(v));
  v.erase(unique(all(v)), v.end());
  for(int i = 0; i < n; i++){
    ret[i] = lower_bound(all(v), arr[i]) - v.begin();
  }
  return ret;
}
