#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int key;
    int val;
    Node *next;
    Node *prev;
    Node(int val, int key) : val(val), key(key), next(nullptr), prev(nullptr) {}
};

class LRUCache
{
public:
    unordered_map<int, Node *> cache;
    int max_cap;
    Node *head = nullptr;
    Node *tail = nullptr;

    LRUCache(int capacity)
    {
        max_cap = capacity;
    }

    void moveToTail(Node* node) {
        if (node == tail) return; 

        if (node == head) {
            head = node->next;
            if (head) head->prev = nullptr;
        } else {
            if (node->prev) node->prev->next = node->next;
            if (node->next) node->next->prev = node->prev;
        }

        node->prev = tail;
        node->next = nullptr;

        if (tail) tail->next = node;
        tail = node;
    }

    int get(int key)
    {
        if (cache.find(key) == cache.end()) return -1;

        Node* node = cache[key];
        moveToTail(node);

        return node->val;
    }

    void put(int key, int value)
    {
        if (cache.find(key) != cache.end()) {
            Node* node = cache[key];
            node->val = value;
            moveToTail(node);
            return;
        }

        Node *new_node = new Node(value, key);
        if (cache.size() >= max_cap) {
            cache.erase(head->key);
            Node* old_head = head;
            head = head->next;
            if (head) head->prev = nullptr;
            delete old_head;
        }

        cache[key] = new_node;

        if (!head) {
            head = tail = new_node;
        } else {
            tail->next = new_node;
            new_node->prev = tail;
            tail = new_node;
        }
    }
};
