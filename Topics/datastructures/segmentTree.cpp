class SegmentTree{
 
 
private:
 
 
  int sz;
  vector<int> Seg;
  vector<int> arr;
  void build(int l, int r, int node){
    if(l == r){
      if(l < arr.size()){
        Seg[node] = arr[l];
      }
      return;
    }
 
    int L = 2 * node + 1 , R = 2 * node + 2;
    int mid = (l + r) >> 1;
    // Left
    build(l, mid, L);
 
    // Right
    build(mid+1, r, R);
 
    Seg[node] = Seg[L] + Seg[R];
  }
 
  void update(int l, int r, int node, int idx, int val){
    if(l == r){
      Seg[node] = val;
      return;
    }
 
    int L = 2 * node + 1 , R = 2 * node + 2;
    int mid = (l + r) >> 1;
    
    if(mid < idx){
      update(mid+1, r, R, idx, val);
    } else {
      update(l, mid, L, idx, val);
    }
    Seg[node] = Seg[L] + Seg[R];
  }
 
  int query(int l, int r, int ql, int qr, int node){
    if(r < ql || l > qr){
      return 0;
    }
 
    if(l >= ql && r <= qr){
      return Seg[node];
    }
    int L = 2 * node + 1 , R = 2 * node + 2;
    int mid = (l + r) >> 1;
 
    int x = query(l, mid, ql, qr, L);
    int y = query(mid+1, r, ql, qr, R);
    return x + y;
  }
 
public:
  SegmentTree(vector<int> &vec){
    sz = 1;
    arr = vec;
    while(sz < vec.size()){
      sz += sz;
    }
    Seg.resize(sz*2-1, 0);
    
    build(0, sz-1, 0);
  }
 
  void update(int idx, int val){ //int l, int r, int node, int idx, int val
    update(0, sz - 1, 0, idx, val);
  }
 
  int query(int l, int r){ //int l, int r, int ql, int qr, int node
    return query(0, sz-1, l, r, 0);
  }
 
  void dbg(){
    for(int i = 0; i < Seg.size(); i++){
      cout << i << " : " << Seg[i] << "\n";
    }
  }
 
 
};
