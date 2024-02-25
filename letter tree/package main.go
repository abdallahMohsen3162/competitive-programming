package main

import (
	"fmt"
)

type Trie struct {
	root *Node
}

type Node struct {
	mp   map[rune]*Node
	leaf map[string]bool
	pref int
}

func NewTrie() *Trie {
	return &Trie{root: &Node{mp: make(map[rune]*Node), leaf: make(map[string]bool)}}
}

func (t *Trie) Insert(key string, val string) {
	temp := t.root
	for _, c := range key {
		if _, ok := temp.mp[c]; !ok {
			temp.mp[c] = &Node{mp: make(map[rune]*Node), leaf: make(map[string]bool)}
		}
		temp = temp.mp[c]
		temp.pref++
	}
	temp.leaf[val] = true
}

func (t *Trie) Search(key string) []string {
	temp := t.root
	for _, c := range key {
		if _, ok := temp.mp[c]; !ok {
			return []string{}
		}
		temp = temp.mp[c]
	}
	result := make([]string, 0, len(temp.leaf))
	for k := range temp.leaf {
		result = append(result, k)
	}
	return result
}

func main() {
	trie := NewTrie()
	trie.Insert("email", "go1")
	trie.Insert("email", "go2")
	fmt.Println(trie.Search("email")) // [go1 go2]
}
