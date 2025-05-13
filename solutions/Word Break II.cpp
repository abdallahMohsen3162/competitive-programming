// https://leetcode.com/problems/word-break-ii/description/
class Trie{
class Node{
public:
    map<char, Node*>mp;
    bool leaf;
    int pref;
    Node(){
        leaf = false;
        pref = 0;
    }
};
public:
    
    Node *root;
    Trie(){ 
        root = new Node();
    }
    void insert(string key){
        Node* temp = root;
        for(int i=0;i<key.size();i++){

            char c = key[i];
            if(temp->mp.find(c) == temp->mp.end()){
                temp->mp[c] = new Node();
            }
            temp = temp->mp[c];
            temp->pref++;
        }
        temp->leaf = true;
    }


    bool search(string s){
        Node *temp = root;
        for(int i = 0; i < s.size(); i++){
            char c = s[i];
            if(temp->mp.find(c) != temp->mp.end()){
                temp = temp->mp[c];
            }else{
                return false;
            }
        }
        return temp->leaf == true;
    }

};



  
  class Solution {
  public:
      Trie tree;
      vector<string> ans;
  
  
      vector<string> wordBreak(string s, vector<string>& wordDict) {
          for(string s: wordDict){
            tree.insert(s);
          }
          vector<string> v;
          dfs(0, v, s);
          return ans;    
      }
  
      void dfs(int st, vector<string>&cur, string&s){
        if(st >= s.size()){
          string newAns = "";
          for(int i = 0;i < cur.size();i++){
            newAns += cur[i] + " ";
          }
          newAns.pop_back();
          ans.push_back(newAns);
          return;
        }
        string curStr = "";
        for(int i = st;i <  s.size();i++){
            curStr += s[i];
            if(tree.search(curStr)){
              cur.push_back(curStr);
              dfs(i + 1, cur, s);
              cur.pop_back();
            }
        }
      }
  
  };
