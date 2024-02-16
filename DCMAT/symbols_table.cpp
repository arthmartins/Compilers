#include "symbols_table.hpp"


int HashTable::hashFunction(int key) {
    return key % TABLE_SIZE;
}

void HashTable::insert(int key, const string& name, void* value) {
    int index = hashFunction(key);
    table[index].push_back(Node(key, name, value));
}

void* HashTable::search(int key) {
    int index = hashFunction(key);
    for (auto& node : table[index]) {
        if (node.type == key) {
            return node.value;
        }
    }
    return nullptr;
}

void HashTable::remove(int key) {
    int index = hashFunction(key);
    table[index].remove_if([key](const Node& node) { return node.type == key; });
}
