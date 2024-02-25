
class NODE {
   mp: Map<string, NODE>;
   leaf: Set<string>;
   pref: number;

   constructor() {
       this.mp = new Map();
       this.leaf = new Set();
       this.pref = 0;
   }
}

class Trie {
   root: NODE;

   constructor() {
       this.root = new NODE();
   }

   insert(key: string, val: string) {
       let temp: NODE = this.root;
       for (let i = 0; i < key.length; i++) {
           const c: string = key[i];
           if (!temp.mp.has(c)) {
               temp.mp.set(c, new NODE());
           }
           temp = temp.mp.get(c)!;
           temp.pref++;
       }
       temp.leaf.add(val);
   }

   search(key: string): string[] {
       let temp: NODE = this.root;
       for (let i = 0; i < key.length; i++) {
           temp = temp.mp.get(key[i])!;
           if (!temp) {
               return [];
           }
       }
       return Array.from(temp.leaf);
   }
}

let tree = new Trie();
tree.insert("abdul@gmail.com", "socketID1");
tree.insert("abdul@gmail.com", "socketID1");
tree.insert("abdul@gmail.com", "socketID2");
tree.insert("abdul@gmail.com", "socketID3");
tree.insert("abdul@gmail.com", "socketID4");
tree.insert("abdul@gmail.com", "socketID5");


console.log(tree.search("abdul@gmail.com")) //["socketID1", "socketID2", "socketID3", "socketID4", "socketID5"] 