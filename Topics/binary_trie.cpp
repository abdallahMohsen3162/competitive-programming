class Trie{
private:
  class Node{
    public:
      int cnt;
      vector<Node*> mp;
    
      Node(){
        mp.resize(2, nullptr);
        cnt = 0;
      }
    
  };

public:
  Node*root;
  Trie(){
    this->root = new Node();
  }
  void insert(int x){
    Node*temp=root;
    for(int i = 31; i >= 0; i--){
      int bit = (x >> i)&1;
      if(!temp->mp[bit]){
        temp->mp[bit] = new Node();
      }
      temp->mp[bit]->cnt++;
      temp = temp->mp[bit];
    }
    temp->cnt++;
  }


   void deletee(int x){
    Node*temp = root;
    for(int i = 31; i >= 0; i--){
      int b = (x >> i) & 1;
      temp->mp[b]->cnt--;
      temp = temp->mp[b];
    }
    temp->cnt--;
  }

};
