class DSU{
public:
    vector<int>par;
    vector<int>sz;
    vector<pair<int,int>>vec;

    int numOfCom , szOfLargest;


    DSU(int n){
        par.resize(n+1);
        sz.resize(n+1);
        vec.resize(n+1);
        for(int i=1;i<=n;++i){
            par[i] = i;
            sz[i] = 1;
            vec[i] = {i,i};
        }
        numOfCom = n;
        szOfLargest = 1;
    }



    int _find(int a){
        while(par[a] != a){
            a = par[a];
        }
        return par[a] = a;
    }



    void _union(int a,int b){
        int pb = _find(a);
        int pa = _find(b);

        if(pb == pa){

             return ;
        }
        if(sz[pa] > sz[pb]){
            par[pb] = pa;
            sz[pa] += sz[pb];

            vec[pa].first = min(min(vec[pb].first,vec[pa].first),min(a,b));
            vec[pa].second = max(max(vec[pb].second,vec[pa].second),max(a,b));
        }else{
            par[pa] = pb;
            sz[pb] += sz[pa];

            vec[pb].first = min(min(vec[pb].first,vec[pa].first),min(a,b));
            vec[pb].second = max(max(vec[pb].second,vec[pa].second),max(a,b));
        }
        szOfLargest = max(szOfLargest,max(sz[pb],sz[pa]));
        numOfCom--;
    }

    int get_sz(int x){
        int ind = _find(x);
        return sz[ind];
    }

    int getmn(int x){
        int ind = _find(x);
        return vec[ind].first;
    }

    int getmx(int x){
        int ind = _find(x);
        return vec[ind].second;
    }
};
