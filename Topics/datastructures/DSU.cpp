class DSU{
public:
    vector<int>par;
    vector<int>sz;

    DSU(int n){
        par.resize(n+1);
        sz.resize(n+1);
        for(int i=1;i<=n;++i){
            par[i] = i;
            sz[i] = 1;
        }
    }

    int _find(int a){
        if(par[a] == a) return a;
        return _find(par[a]);
    }

    void _union(int a,int b){
        a = _find(a);
        b = _find(b);

        if(a == b) return;
        if(sz[a] > sz[b]){
            par[b] = a;
            sz[a] += sz[b];
        }else{
            par[a] = b;
            sz[b] += sz[a];
        }
    }
};
