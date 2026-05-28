#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Node {
public:
    unordered_map<char, Node*> children;
    bool endofWord;
    int freq;

    Node() {
        endofWord = false;
    }
};

class Trie {
    Node* root;
public:
    Trie() {
        root = new Node();
        root->freq = -1;
    }

    void insert(string key) {
        Node* temp = root;

        for (int i = 0; i < key.size(); i++) {
            // Check if the character is already present
            if (temp->children.count(key[i]) == 0) {
                temp->children[key[i]] = new Node();
                temp->children[key[i]]->freq = 1;
            }else{
                temp->children[key[i]]->freq++;

            }
            temp = temp->children[key[i]];
        }
        temp->endofWord = true;
    }

    bool search(string key) {
        Node* temp = root;
        for (int i = 0; i < key.size(); i++) {
            if (temp->children.count(key[i])) {
                temp = temp->children[key[i]];
            } else {
                return false;
            }
        }
        return temp->endofWord; // Return true only if it's the end of a word
    }
};

bool helper(Trie &trie, string key){
    for(int i=0; i<key.size(); i++){
        string first = key.substr(0, i+1);
        string second = key.substr(i+1);
        if(trie.search(first) && helper(trie,second)){
            return true;
        }
        return false;

    }   
}


bool wordBreak(vector<string> dict, string key){
    Trie trie;

    for(int i=0; i<dict.size(); i++){
        trie.insert(dict[i]);
    }
}

int main() {
    vector<string> dict = {"the", "a", "there", "their", "any", "thee"};
    string key = "samsung";
    Trie trie;

    wordBreak(dict, key);

    return 0;
}
