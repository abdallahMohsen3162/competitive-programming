#include<bits/stdc++.h>
using namespace std;
#define int long long


class SegmentTree{
private:
  
  vector<int> Seg;
  vector<int> lazy;
  vector<int> arr;

  int combine(int x, int y){
    return max(x, y);
  }

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
 
    Seg[node] = combine(Seg[L], Seg[R]);
  }
public:
  int sz;

  void propagate(int node, int l, int r){
    if(lazy[node] != 0){
      Seg[node] = max(lazy[node], Seg[node]);
      if(l != r){
        lazy[2 * node + 1] = max(lazy[2 * node + 1], lazy[node]);
        lazy[2 * node + 2] = max(lazy[2 * node + 2], lazy[node]);
      }
    }
    lazy[node] = 0;
  }
  
  void update(int ql, int qr, int v, int node, int sl, int sr){
    propagate(node, sl, sr);
    if(ql <= sl && sr <= qr){
      lazy[node] = max({v, lazy[node]});
      propagate(node, sl, sr);
      return;
    }

    if(ql > sr || sl > qr){
      return;
    }
 
    int L = 2 * node + 1 , R = 2 * node + 2;
    int mid = (sl + sr) >> 1;
    
    update(ql, qr, v,L ,sl, mid);
    update(ql, qr, v, R,mid+1, sr);

    Seg[node] = combine(Seg[L], Seg[R]);
  }
 
  int query(int ql, int qr, int l, int r, int node){
    propagate(node, l, r);
    if(ql <= l && r <= qr){
      return Seg[node];
    }

    if(r < ql || l > qr){
      return 0;
    }
    int L = 2 * node + 1 , R = 2 * node + 2;
    int mid = (l + r) >> 1;
 
    int x = query(ql, qr, l, mid,  L);
    int y = query(ql, qr, mid+1, r, R);
    return combine(x, y);
  }

  
  

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
  
 
  void dbg(){
    for(int i = 0; i < Seg.size(); i++){
      cout << i << " : " << Seg[i]  << " : " << lazy[i] << "\n";
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
      tree.update(l, r, v, 0, 0, tree.sz - 1);
      // tree.dbg();
    }else{
      int i; cin>> i;
      cout << tree.query(i, i,0, tree.sz - 1, 0) << "\n";
    }
    // tree.dbg();
  }


}

int32_t main(){
  int tt = 1; 
  // cin >> tt;
  while(tt--)
    answerTc();
  return 0;
}
