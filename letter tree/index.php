<?php

class Trie {
    private $root;

    public function __construct() {
        $this->root = new Node();
    }

    public function insert($key, $val) {
        $temp = $this->root;
        for ($i = 0; $i < strlen($key); $i++) {
            $c = $key[$i];
            if (!isset($temp->mp[$c])) {
                $temp->mp[$c] = new Node();
            }
            $temp = $temp->mp[$c];
            $temp->pref++;
        }
        $temp->leaf[] = $val;
    }

    public function search($key) {
        $temp = $this->root;
        for ($i = 0; $i < strlen($key); $i++) {
            if (!isset($temp->mp[$key[$i]])) {
                return [];
            }
            $temp = $temp->mp[$key[$i]];
        }
        return $temp->leaf;
    }
}

class Node {
    public $mp;
    public $leaf;
    public $pref;

    public function __construct() {
        $this->mp = [];
        $this->leaf = [];
        $this->pref = 0;
    }
}

?>
