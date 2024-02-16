#ifndef SYMBOLS_TABLE_HPP
#define SYMBOLS_TABLE_HPP

#include <iostream>
#include <list>
#include <string>
#include <functional>
#define TABLE_SIZE 149

using namespace std;

// Definição da estrutura do nó
struct Node {
    int type;
    string name;
    void* value;

    Node(int t, const string& n, void* v);
};

// Definição da classe HashTable
class HashTable {
private:

    list<Node> table[TABLE_SIZE];

    int hashFunction(int key);

public:
    HashTable();
    void insert(int key, const string& name, void* value);
    void* search(int key);
    void remove(int key);
};

#endif
