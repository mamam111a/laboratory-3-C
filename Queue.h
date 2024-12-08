#pragma once
#include "header.h"
#include <iostream>
#include <fstream>

using namespace std;

class Queue {
private:
    SingleNode* head = nullptr;
    SingleNode* tail = nullptr;
public:
    ~Queue() {
        Clear();
    }
    int Size(){
        int count = 0;
        SingleNode* current = head;
        while (current != nullptr) {
            count++;
            current = current->next;
        }
        return count;
    }
    void Clear() {
        while (head != nullptr) {
            SingleNode* temp = head;
            head = head->next;
            delete temp;
        }
        tail = nullptr;
    }

    void QPUSH(string& cell) {
        SingleNode* node = new SingleNode;
        node->cell = cell;
        node->next = nullptr;

        if (head == nullptr) {
            head = node;
            tail = node;
        }
        else {
            tail->next = node;
            tail = node;
        }
    }
    void QPOP() {
        SingleNode* node = head;
        head = head->next;
        delete node;
        if (head == nullptr) {
            tail = nullptr;
        }
    }
    void QREAD() {
        SingleNode* current = head;
        cout << endl;
        while (current != nullptr) {
            cout << current->cell << " ";
            current = current->next;
        }
        cout << endl;
    }

    void WritingFromFileToStructure(string& filename) {
        ifstream FileRead(filename);
        string tempValue;

        while (getline(FileRead, tempValue)) {
            stringstream ss(tempValue);
            string element;
            while (ss >> element) {
                QPUSH(element);
            }
        }
        FileRead.close();
    }

    void WritingFromStructureToFile( string& filename) { 
        ofstream FileWrite(filename);
        SingleNode* current = head;
        while (current != nullptr) {
            FileWrite << current->cell << " ";
            current = current->next;
        }
        FileWrite.close();
    }
    
    void BinarySerialization(string& filename) {
        ofstream FileWrite(filename, ios::binary);

        SingleNode* current = head;

        while (current != nullptr) {
            int len = current->cell.size();
            FileWrite.write(reinterpret_cast<char*>(&len), sizeof(len)); 
            FileWrite.write(current->cell.c_str(), len); 

            current = current->next;
        }
        FileWrite.close();
    }

    void BinaryDEserialization(string& filename) {
        ifstream fileRead(filename, ios::binary); 

        while (fileRead) {
            int len;
            fileRead.read(reinterpret_cast<char*>(&len), sizeof(len)); 

            if (fileRead.eof()) 
                break;  

            char* buffer = new char[len + 1];
            fileRead.read(buffer, len); 
            buffer[len] = '\0'; 

            string text(buffer);
            
            QPUSH(text);
            delete buffer;
        }
        fileRead.close();
    }


};