#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define ALPHABET_SIZE 26

// Trie node structure
typedef struct TrieNode {
    struct TrieNode* children[ALPHABET_SIZE];
    bool isEnd;
} TrieNode;

// Create a new trie node
TrieNode* createNode() {
    TrieNode* node = (TrieNode*)malloc(sizeof(TrieNode));
    node->isEnd = false;
    for (int i = 0; i < ALPHABET_SIZE; i++)
        node->children[i] = NULL;
    return node;
}

// Insert a word into the trie
void insert(TrieNode* root, const char* word) {
    TrieNode* current = root;
    for (int i = 0; word[i]; i++) {
        int index = word[i] - 'a';
        if (!current->children[index])
            current->children[index] = createNode();
        current = current->children[index];
    }
    current->isEnd = true;
}

// Search for a word in the trie
bool search(TrieNode* root, const char* word) {
    TrieNode* current = root;
    for (int i = 0; word[i]; i++) {
        int index = word[i] - 'a';
        if (!current->children[index])
            return false;
        current = current->children[index];
    }
    return current && current->isEnd;
}

// Check if a node has any children
bool hasChildren(TrieNode* node) {
    for (int i = 0; i < ALPHABET_SIZE; i++)
        if (node->children[i])
            return true;
    return false;
}

// Recursive function to delete a word from the trie
bool delete(TrieNode* root, const char* word, int depth) {
    if (!root)
        return false;

    // End of word
    if (word[depth] == '\0') {
        if (!root->isEnd)
            return false;
        root->isEnd = false;

        // If node has no children, it can be deleted
        return !hasChildren(root);
    }

    int index = word[depth] - 'a';
    if (!delete(root->children[index], word, depth + 1))
        return false;

    free(root->children[index]);
    root->children[index] = NULL;

    // Return true if current node is now unnecessary
    return !root->isEnd && !hasChildren(root);
}

// Wrapper function for deletion
void deleteWord(TrieNode* root, const char* word) {
    delete(root, word, 0);
}

// Main function
int main() {
    TrieNode* root = createNode();

    // Insert words
    insert(root, "cat");
    insert(root, "car");
    insert(root, "cart");
    insert(root, "apple");
    insert(root, "elephant");

    // Search words
    printf("Search 'car': %s\n", search(root, "car") ? "Found" : "Not Found");
    printf("Search 'care': %s\n", search(root, "care") ? "Found" : "Not Found");
    printf("Search 'apple': %s\n", search(root, "apple") ? "Found" : "Not Found");

    // Delete 'car' and 'apple'
    deleteWord(root, "car");
    deleteWord(root, "apple");

    // Re-search after deletion
    printf("After deletion:\n");
    printf("Search 'car': %s\n", search(root, "car") ? "Found" : "Not Found");
    printf("Search 'cart': %s\n", search(root, "cart") ? "Found" : "Not Found");
    printf("Search 'apple': %s\n", search(root, "apple") ? "Found" : "Not Found");

    return 0;
}
