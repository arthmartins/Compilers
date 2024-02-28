#include "hash.hpp"

//Node::Node(int t, string n, float num) : type(t), name(n), valorFloat(num) {//

//Node::Node(int t, string n, vector<vector<float>>& value) : type(t), name(n), matriz(value) {}


int HashTable::calculateKey(string str) {
    int sum = 0;
    for (char c : str) {
        sum += static_cast<int>(c);
    }
    return sum % TABLE_SIZE;
}

void HashTable::insert(string name, float value) {
    int tipo = getType(name);
    if(tipo == -1){
        int index = calculateKey(name);
        table[index].push_back(Node(0, name, value)); // type == 0 para valorFloat
    }else{
        update(name,value);
    }
}

void HashTable::insert(string name, std::vector<std::vector<float>>*  value) {
    
    int tipo = getType(name);
    if(tipo == -1){
    int index = calculateKey(name);
    table[index].push_back(Node(1, name, value, 0)); // type == 1 para matriz
    }else{
        update(name,value);
    }
}

void* HashTable::search(string name) {
    int index = calculateKey(name);
    for (auto& node : table[index]) {
        if (node.name == name) {
            if (node.type == 0) {
                return &(node.valorFloat);
            } else if (node.type == 1) {
                return (node.matriz_hash);
            }
        }
    }
    return nullptr; // Retorna nullptr se não encontrar o elemento
}


void HashTable::remove(string name) {
    int index = calculateKey(name);
    table[index].remove_if([&name](const Node& node) { return node.name == name; });
}


void HashTable::printAll() {
    printf("\n");
    for (int i = 0; i < TABLE_SIZE; ++i) {
        for (const auto& node : table[i]) {
            cout << node.name << " - ";
            if (node.type == 0) {
                cout << "FLOAT" <<  endl;
            }else if(node.type == 1){
                cout << "MATRIX [" << (*node.matriz_hash).size() << "] [" << node.matriz_hash[0].size() << "]" << endl;
            }
        }
    }
    printf("\n");
}

int HashTable::getType(string name){
    
    int index = calculateKey(name.c_str());
    for (auto& node : table[index]) {
        if (node.name == name.c_str()) {
            return node.type;
        }
    }
    return -1;
}

void HashTable::update(string name, float value) {
    int index = calculateKey(name);
    for (auto& node : table[index]) {
        if (node.name == name) {
            node.valorFloat = value;
            node.type = 0;
            return; // Elemento encontrado e atualizado, podemos sair da função
        }
    }
    
}

void HashTable::update(string name, std::vector<std::vector<float>>*  value) {
    int index = calculateKey(name);
    for (auto& node : table[index]) {
        if (node.name == name) {
            node.matriz_hash = value;
            node.type =1;
            return; // Elemento encontrado e atualizado, podemos sair da função
        }
    }
    
}