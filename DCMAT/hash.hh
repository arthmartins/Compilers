#ifndef HASH_HH
#define HASH_HH

#include <iostream>
#include <string>
#include <vector>
#include <list>

using namespace std;

struct Node {
    int type;
    string name;
    float valorFloat;
    vector<vector<float>> matriz;

    
    Node(int t, string n, float num) : type(t), name(n), valorFloat(num) {}

    
    Node(int t, string n, vector<vector<float>> value) : type(t), name(n), matriz(value) {}
};

class HashTable {
private:
    static const int TABLE_SIZE = 100;
    list<Node> table[TABLE_SIZE];

    int calculateKey(string str);
    
public:
    void insert(string name, float value);
    void insert(string name, vector<vector<float>> value);
    void* search(string name);
    void remove(string name);
    void printAll();
    int getType(string name);
};

#endif
