#pragma once
#include "header.h"
#include <iostream>
#include <fstream>

using namespace std;

class HashTable {

private:
    struct NodeHash {
        string key;
        string value;
        NodeHash* next;

        NodeHash(string& k, string& v) : key(k), value(v), next(nullptr) {}
    };

    NodeHash** table; // массив указателей на узлы хеш-таблицы
    int size;
    int count;

public:
    int Size() {
        return count;
    }
    HashTable() {
        size = 1000;  
        count = 0;
        table = new NodeHash * [size];
        for (int i = 0; i < size; i++) {
            table[i] = nullptr;
        }
    }
    ~HashTable() {
        for (int i = 0; i < size; i++) {
            HDestroyTable(table[i]);
        }
        delete[] table;
    }
    void HDestroyTable(NodeHash* node) {
        while (node != nullptr) {
            NodeHash* temp = node;
            node = node->next;
            delete temp;
        }
    }
    HashTable(int initialSize) {
        size = initialSize;
        count = 0;
        table = new NodeHash * [size];
        for (int i = 0; i < size; i++) {
            table[i] = nullptr;
        }
    }

    int HashFunc(string& str) {
        int hash = 0;
        for (char c : str) {
            hash += c;  //ASCII
        }
        return hash % size;
    }

    void HPUSH(string& key, string& value) {
        int index = HashFunc(key);
        NodeHash* current = table[index];

        while (current != nullptr) {
            if (current->key == key) {
                current->value = value;
                return;
            }
            current = current->next;
        }

        NodeHash* newNode = new  NodeHash(key, value);  // создание нового узла
        newNode->next = table[index];  // новый узел указывает на текущий узел по индексу
        table[index] = newNode;  // новый узел становится текущим узлом по индексу
        count++;

    }

    void HDEL(string& key) {
        int index = HashFunc(key);
        NodeHash* current = table[index];
        NodeHash* prev = nullptr;

        while (current != nullptr) {
            if (current->key == key) {
                if (prev == nullptr) {  // если это первый узел в списке
                    table[index] = current->next;  // следующий узел становится текущим
                }
                else {
                    prev->next = current->next;  // предыдущий узел указывает на следующий узел
                }
                delete current;
                count--;
                return;
            }
            prev = current;  // переход к следующему узлу
            current = current->next;
        }
    }

    string HGET(string& key) {
        int index = HashFunc(key);
        NodeHash* current = table[index];

        while (current != nullptr) {
            if (current->key == key) {  // если ключ найден
                return current->value;
            }
            current = current->next;
        }

        return "\n\nThe key was not found\n\n";
    }

    void HREAD() {
        for (int i = 0; i < size; i++) {
            cout << "[" << i << "]: ";
            NodeHash* current = table[i];
            if (current == nullptr) {
                cout << "empty" << endl;
                continue;
            }
            while (current != nullptr) {
                cout << "(" << current->key << ", " << current->value << ") ";
                current = current->next;
            }
            cout << endl;
        }
    }
    void SaveToFile(string &filename){
        ofstream FileWrite(filename);
            if (FileWrite.is_open()) {
                for (int i = 0; i < size; i++) {
                    NodeHash* current = table[i];
                    while (current != nullptr) {
                        FileWrite << current->key << " " << current->value << endl;
                        current = current->next;
                    }
                }
                FileWrite.close();
            }
    }
    void WriteFromFile(string& filename) {
        ifstream FileRead(filename);
        if (FileRead.is_open()) {
            string key, value;
            while (FileRead >> key >> value) {
                HPUSH(key, value);
            }
            FileRead.close();
        }
    }


    void BinarySerialization(string& filename) {

        ofstream FileWrite(filename, ios::binary);
        if (!FileWrite.is_open()) return;

        for (int i = 0; i < size; i++) {
            NodeHash* current = table[i];

            while (current != nullptr) {

                int keyLen = current->key.size();
                int valueLen = current->value.size();

                FileWrite.write(reinterpret_cast<char*>(&keyLen), sizeof(keyLen));
                FileWrite.write(current->key.c_str(), keyLen);

                FileWrite.write(reinterpret_cast<char*>(&valueLen), sizeof(valueLen));
                FileWrite.write(current->value.c_str(), valueLen);

                current = current->next;
            }
        }

        FileWrite.close();
    }

    void BinaryDEserialization(const string& filename) {

        ifstream fileRead(filename, ios::binary);

        while (fileRead) {
            int keyLen, valueLen;

            fileRead.read(reinterpret_cast<char*>(&keyLen), sizeof(keyLen));

            if (fileRead.eof()) break; 

            char* keyBuffer = new char[keyLen + 1];
            fileRead.read(keyBuffer, keyLen);
            keyBuffer[keyLen] = '\0';
            string key(keyBuffer);

            fileRead.read(reinterpret_cast<char*>(&valueLen), sizeof(valueLen));

            char* valueBuffer = new char[valueLen + 1];
            fileRead.read(valueBuffer, valueLen);
            valueBuffer[valueLen] = '\0';
            string value(valueBuffer);

            HPUSH(key, value);

            delete valueBuffer;
            delete keyBuffer;
        }

        fileRead.close();
    }
};