#include<bits/stdc++.h>
using namespace std;
#define int long long


class SegmentTree{
private:
  int sz;
  vector<int> Seg;
  vector<int> lazy;
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

  void update_lazy(int ql, int qr, int v, int node, int sl, int sr){
    propagate(node, sl, sr);
    if(ql <= sl && sr <= qr){
      lazy[node] = v;
      propagate(node, sl, sr);
      return;
    }

    if(ql > sr || sl > qr){
      return;
    }
 
    int L = 2 * node + 1 , R = 2 * node + 2;
    int mid = (sl + sr) >> 1;
    
    update_lazy(ql, qr, v,L ,sl, mid);
    update_lazy(ql, qr, v, R,mid+1, sr);

    Seg[node] = (Seg[L] + Seg[R]);
  }
 
  int query(int l, int r, int ql, int qr, int node){
    propagate(node, l, r);
    if(ql <= l && r <= qr){
      return Seg[node];
    }
    if(r < ql || l > qr){
      return 0;
    }
    int L = 2 * node + 1 , R = 2 * node + 2;
    int mid = (l + r) >> 1;
 
    int x = query(l, mid, ql, qr, L);
    int y = query(mid+1, r, ql, qr, R);
    return x + y;
  }
  void propagate(int node, int l, int r){
    if(lazy[node] != 0){
      Seg[node] += lazy[node] * (r - l + 1);
      if(l != r){
        lazy[2*node+1] += lazy[node];
        lazy[2*node+2] += lazy[node];
      }
    }
    lazy[node] = 0;
  }
  
public:
  SegmentTree(vector<int> &vec){
    sz = 1;
    arr = vec;
    while(sz < vec.size()){
      sz += sz;
    }
    Seg.resize(sz*2-1, 0);
    lazy.resize(sz*2-1, 0);
    build(0, sz-1, 0);
  }
  
  void update(int idx, int val){ //int l, int r, int node, int idx, int val
    update(0, sz - 1, 0, idx, val);
  }

  void update_lazy(int l, int r, int val){ //int l, int r, int node, int idx, int val
    update_lazy(l, r, val, 0, 0, sz - 1);
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


void answerTc(){
  int n ,q ;
  cin >> n >> q;
  vector<int> arr(n, 0);
  SegmentTree tree(arr);

  while(q--){
    int t; cin >> t;
    if(t == 1){
      int l, r, v; cin >> l >> r >> v;
      --r;
      tree.update_lazy(l, r, v);
      // tree.dbg();
    }else{
      int i; cin>> i;
      cout << tree.query(i, i) << "\n";
    }
  }


}

int32_t main(){
  int tt = 1; 
  // cin >> tt;
  while(tt--)
    answerTc();
  return 0;
}
