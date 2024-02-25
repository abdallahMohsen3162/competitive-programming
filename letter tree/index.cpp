#include<bits/stdc++.h>

using namespace std;

class Trie{
class Node{
public:
    map<char, Node*>mp;
    unordered_set<string> leaf;
    int pref;
    Node(){
        pref = 0;
    }
};
public:
    
    Node *root;
    Trie(){ 
        root = new Node();
    }
    void insert(string key, string val){
        Node* temp = root;
        for(int i=0;i<key.size();i++){

            char c = key[i];
            if(temp->mp.find(c) == temp->mp.end()){
                temp->mp[c] = new Node();
            }
            temp = temp->mp[c];
            temp->pref++;
        }
        temp->leaf.insert(val);
    }

    unordered_set<string> search(string key){
        Node*temp = root;
        for(int i=0;i<key.size();i++){
            temp = temp->mp[key[i]];

            if(!temp){
                return {};
            }
        }
        return temp->leaf;
    }

};


int main(){
   Trie tree;
   tree.insert("abdul@gmail.com", "socketID1");
   tree.insert("abdul@gmail.com", "socketID1");
   tree.insert("abdul@gmail.com", "socketID2");
   tree.insert("abdul@gmail.com", "socketID3");
   tree.insert("abdul@gmail.com", "socketID4");
   tree.insert("abdul@gmail.com", "socketID5");
   unordered_set<string> socket = tree.search("abdul@gmail.com");
   for(string str: socket){
      cout << str << " "; //socketID1 socketID4 socketID2 socketID5 socketID3
   }
}