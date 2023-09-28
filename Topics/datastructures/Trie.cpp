#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second
#define yes cout << "YES\n";
#define no cout << "NO\n";
#define ln cout << "\n";
#define all(v) v.begin(), v.end()
#define pr(x) cout << x;
const int N = 1e5 + 10;



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
    string mx_pref;
    Trie(){ 
        root = new Node();
        mx_pref = "";
    }
    void insert(string str){
        Node* temp = root;
        for(int i=0;i<str.size();i++){

            char c = str[i];
            if(temp->mp.find(c) == temp->mp.end()){
                temp->mp[c] = new Node();
            }

            temp = temp->mp[c];
            temp->pref++;
        }
        temp->leaf = true;
    }

    bool search(string str){
        Node*temp = root;
        for(int i=0;i<str.size();i++){
            temp = temp->mp[str[i]];

            if(!temp){
                return false;
            }
        }
        return temp->leaf == true;
    }

    void maxPref(Node*temp, string cur_str, int sz){
        if(cur_str.size() > mx_pref.size()){
            mx_pref = cur_str;
        }
        if(temp == nullptr) return;
         for(char c='a';c<='z';c++){
            if(temp->mp[c]){
                if(temp->mp[c]->pref == sz){
                    maxPref(temp->mp[c], cur_str + c, sz);
                }
            }
         }
    }

};


void tc(){
    Trie tr;
    tr.insert("abdu");
    tr.insert("abdul");
    // cout << tr.search("asd");
    char c;
    tr.maxPref(tr.root,"", 2);
    cout << tr.mx_pref;
}

int32_t main()
{

    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin>>t;
    while(t--) tc();
    return 0;
}