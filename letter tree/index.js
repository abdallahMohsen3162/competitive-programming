class Trie {
   constructor() {
       this.root = new Node();
   }

   insert(key, val) {
       let temp = this.root;
       for (let i = 0; i < key.length; i++) {
           let c = key[i];
           if (!temp.mp.has(c)) {
               temp.mp.set(c, new Node());
           }
           temp = temp.mp.get(c);
           temp.pref++;
       }
       temp.leaf.add(val);
   }

   search(key) {
       let temp = this.root;
       for (let i = 0; i < key.length; i++) {
           temp = temp.mp.get(key[i]);
           if (!temp) {
               return new Set();
           }
       }
       return temp.leaf;
   }
}

class Node {
   constructor() {
       this.mp = new Map();
       this.leaf = new Set();
       this.pref = 0;
   }
}