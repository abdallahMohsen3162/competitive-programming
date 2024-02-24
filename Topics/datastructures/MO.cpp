const int N = 2e5 + 1 , SQ = 448;




struct Query{
  int l, r, q_idx, blk_idx;
  Query(){}
  Query(int _l, int _r, int _q_idx){
    l = _l, r = _r, q_idx = _q_idx;
    blk_idx = _l / SQ;
  }

  bool operator<(const Query&Q)const{
    if(blk_idx != Q.blk_idx)
      return blk_idx < Q.blk_idx;
    
    return r < Q.r;
  }

};

int n, q, arr[N], L = 0, R = 0, vis[N], ans[N]; 
int res = 0;
Query qu[N];

void add(int idx){
  if(!vis[arr[idx]]){
    res++;
  }
  vis[arr[idx]]++;
}


void remove(int idx){
  vis[arr[idx]]--;
  if(!vis[arr[idx]]) res--;
}

void preprocess(){
  sort(qu, qu + q);
  int l = 1, r = 0;
  for(int i = 0; i < q; i++){
    while(l < qu[i].l) remove(l++);
    while(l > qu[i].l) add(--l);
    while(r < qu[i].r) add(++r);
    while(r > qu[i].r) remove(r--);
    ans[qu[i].q_idx] = res;
  }
}
