#include <iostream>
using namespace std;

// Each Trie node
class TrieNode {
public:
    TrieNode* children[26];
    bool isEndOfWord;

    TrieNode() {
        isEndOfWord = false;
        for(int i = 0; i < 26; ++i)
            children[i] = nullptr;
    }
};

class Trie {
private:
    TrieNode* root;

    // Helper function for deleting a word
    bool deleteHelper(TrieNode* node, const string& word, int depth) {
        if (!node) return false;

        if (depth == word.length()) {
            if (!node->isEndOfWord) return false;

            node->isEndOfWord = false;

            // If node has no children, it can be deleted
            for (int i = 0; i < 26; ++i)
                if (node->children[i]) return false;

            return true;
        }

        int index = word[depth] - 'a';
        if (deleteHelper(node->children[index], word, depth + 1)) {
            delete node->children[index];
            node->children[index] = nullptr;

            // If current node is not end of another word and has no other children
            return !node->isEndOfWord && noChildren(node);
        }

        return false;
    }

    bool noChildren(TrieNode* node) {
        for (int i = 0; i < 26; ++i)
            if (node->children[i]) return false;
        return true;
    }

public:
    Trie() {
        root = new TrieNode();
    }

    // Insert a word into the Trie
    void insert(const string& word) {
        TrieNode* curr = root;
        for (char ch : word) {
            int index = ch - 'a';
            if (!curr->children[index])
                curr->children[index] = new TrieNode();
            curr = curr->children[index];
        }
        curr->isEndOfWord = true;
    }

    // Search a word in the Trie
    bool search(const string& word) {
        TrieNode* curr = root;
        for (char ch : word) {
            int index = ch - 'a';
            if (!curr->children[index])
                return false;
            curr = curr->children[index];
        }
        return curr->isEndOfWord;
    }

    // Delete a word from the Trie
    void remove(const string& word) {
        deleteHelper(root, word, 0);
    }
};

int main() {
    Trie trie;

    trie.insert("hello");
    trie.insert("hell");
    trie.insert("help");

    cout << "Search 'hello': " << (trie.search("hello") ? "Found" : "Not Found") << endl;
    cout << "Search 'hel': " << (trie.search("hel") ? "Found" : "Not Found") << endl;

    trie.remove("hello");
    cout << "After deleting 'hello'\n";
    cout << "Search 'hello': " << (trie.search("hello") ? "Found" : "Not Found") << endl;
    cout << "Search 'hell': " << (trie.search("hell") ? "Found" : "Not Found") << endl;

    return 0;
}
