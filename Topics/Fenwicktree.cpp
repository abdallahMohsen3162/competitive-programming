class Fenwicktree{
    int n;
    vector<ll>BIT;
public:
    Fenwicktree(int sz){
        n = sz;
        BIT.resize(sz, 0);
    }

    ll get_acc_sum(ll x){
        ll sum = 0;
        while(x){
            sum += BIT[x];
            // cout << x << "\n";
            x = remove_last_bit(x);
        }
        return sum;
    }


    void add(ll idx ,ll val){ 
        while (idx < n){
            BIT[idx] += val; 
            // cout << idx << " ";
            // print(idx);
            // cout << "\n";
            idx += (idx & -idx);
        }
    }


};
