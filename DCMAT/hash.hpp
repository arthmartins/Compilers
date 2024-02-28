#ifndef HASH_HPP
#define HASH_HPP

#include <iostream>
#include <string>
#include <vector>
#include <list>

using namespace std;

struct Node {
    int type;
    string name;
    float valorFloat;
    std::vector<std::vector<float>>* matriz_hash;  

    
    Node(int t, string n, float num) : type(t), name(n), valorFloat(num), matriz_hash(NULL) {}

    
    Node(int t, string n, std::vector<std::vector<float>>*  value, float v) : type(t), name(n), matriz_hash(value), valorFloat(v) {}
};

class HashTable {
private:
    static const int TABLE_SIZE = 100;
    list<Node> table[TABLE_SIZE];

    int calculateKey(string str);
    
public:
    void insert(string name, float value);
    void insert(string name, std::vector<std::vector<float>>* value);
    void* search(string name);
    void remove(string name);
    void printAll();
    int getType(string name);
    void update(string name, float value);
    void update(string name, std::vector<std::vector<float>>*  value);
};

#endif