#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define ALPHABET_SIZE 26

typedef struct TrieNode {
    struct TrieNode* children[ALPHABET_SIZE];
    bool isEndOfWord;
} TrieNode;

typedef struct {
    TrieNode* root;
} Trie;

TrieNode* createNode() {
    TrieNode* node = (TrieNode*)malloc(sizeof(TrieNode));
    node->isEndOfWord = false;
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        node->children[i] = NULL;
    }
    return node;
}

Trie* trieCreate() {
    Trie* trie = (Trie*)malloc(sizeof(Trie));
    trie->root = createNode();
    return trie;
}

void trieInsert(Trie* obj, char* word) {
    TrieNode* curr = obj->root;
    for (int i = 0; word[i] != '\0'; i++) {
        int index = word[i] - 'a';
        if (curr->children[index] == NULL) {
            curr->children[index] = createNode();
        }
        curr = curr->children[index];
    }
    curr->isEndOfWord = true;
}

bool trieSearch(Trie* obj, char* word) {
    TrieNode* curr = obj->root;
    for (int i = 0; word[i] != '\0'; i++) {
        int index = word[i] - 'a';
        if (curr->children[index] == NULL) {
            return false;
        }
        curr = curr->children[index];
    }
    return curr->isEndOfWord;
}

bool trieStartsWith(Trie* obj, char* prefix) {
    TrieNode* curr = obj->root;
    for (int i = 0; prefix[i] != '\0'; i++) {
        int index = prefix[i] - 'a';
        if (curr->children[index] == NULL) {
            return false;
        }
        curr = curr->children[index];
    }
    return true;
}

void freeNode(TrieNode* node) {
    if (node == NULL) {
        return;
    }
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        freeNode(node->children[i]);
    }
    free(node);
}

void trieFree(Trie* obj) {
    freeNode(obj->root);
    free(obj);
}

void printTrieUtil(TrieNode* node, char* buffer, int depth) {
    if (node == NULL) {
        return;
    }

    if (node->isEndOfWord) {
        buffer[depth] = '\0';
        printf("%s\n", buffer);
    }

    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (node->children[i] != NULL) {
            buffer[depth] = 'a' + i;
            printTrieUtil(node->children[i], buffer, depth + 1);
        }
    }
}

void printTrie(Trie* obj) {
    TrieNode* root = obj->root;
    char buffer[100];
    printTrieUtil(root, buffer, 0);
}

int main() {
    Trie* trie = trieCreate();

    trieInsert(trie, "apple");
    trieInsert(trie, "banana");
    trieInsert(trie, "cherry");

    printf("Trie Contents:\n");
    printTrie(trie);

    trieFree(trie);

    return 0;
}
