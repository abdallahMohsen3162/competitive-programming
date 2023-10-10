class Fenwicktree{

public:
    int n;
    vector<ll>BIT;
    vector<ll>arr;

    Fenwicktree(int sz){
        n = sz;
        BIT.resize(sz, 0);
        arr.resize(sz, 0);
    }

    ll get_acc_sum(ll x){
        ll sum = 0;
        while(x){
            sum += BIT[x];
            x -= (x & -x); 
        }
        return sum;
    }

    void update(int i, int val) {
        int idx = i+1;
        while(idx < n) {
            BIT[idx] += (val - arr[i]);
            idx += idx&-idx;
        }
        arr[i] = val;
 }


    void add(int i, int x){
        for(; i < n; i += (i&-i))
            BIT[i] += x;
    }

};
