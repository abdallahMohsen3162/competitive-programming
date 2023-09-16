
class Binary_search_tree{
private:
    multiset<int>ms;

public:
    Binary_search_tree(){}

    void push(int x){//~O(log(N))
        ms.insert(x);
    }

    bool pop(int x){//O(log(N))
        multiset<int>::iterator it;
        it = ms.find(x);
        if(it != ms.end()){
            ms.erase(it);
            return true;
        }
        return false;
    }

    int size(){//O(1)
        return ms.size();
    }

    void print(){
        for(auto i:ms) cout << i << " ";
        cout << "\n";
    }

};
