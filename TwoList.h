#pragma once
#include "header.h"
#include <iostream>
#include <fstream>

using namespace std;

class TwoList {
private:
    
    DoubleNode* head = nullptr;
    DoubleNode* tail = nullptr;
public:

    ~TwoList() {
        Clear();
    }
    int SearchForTest(string& value) {
        DoubleNode* node = head;
        if (head == nullptr) {
            return -2;
        }
        int index = 0;
        if (head->cell == value) {
            return index;
        }
        while (node != nullptr && node->cell != value) {
            node = node->next;
            index++;
        }
        if (node == nullptr) {
            return -1;
        }
        return index;

    }
    int Size(){
        int count = 0;
        DoubleNode* current = head;
        while (current != nullptr) {
            count++;
            current = current->next;
        }
        return count;
    }
    void Clear() {/////
        while (head != nullptr) {
            DoubleNode* temp = head;
            head = head->next;
            delete temp;
        }
        tail = nullptr;
    }
    void LTWOPUSHhead(string& element) {
        DoubleNode* node = new DoubleNode;
        node->cell = element;
        node->next = nullptr;
        node->prev = nullptr;

        if (head == nullptr) {
            head = tail = node;
        }
        else {
            node->next = head;
            head->prev = node;
            head = node;
        }
    }
    void LTWOPUSHtail(string& element) {
        DoubleNode* node = new DoubleNode;
        node->cell = element;
        node->next = nullptr;
        node->prev = nullptr;
        if (tail == nullptr) {
            head = tail = node;
        }
        else {
            tail->next = node;
            node->prev = tail;
            tail = node;
        }
    }

    void LTWODELhead() {
        if (head == nullptr) {
            //cout << "\nThe list is empty!" << endl;
            return;
        }
        DoubleNode* node = head;
        head = head->next;
        delete node;
        if (head == nullptr) {
            tail = nullptr;
        }
    }
    void LTWODELtail() {
        if (head == nullptr) {
            //cout << "\nThe list is empty!" << endl;
            return;
        }
        if (head == tail) {
            delete head;
            head = tail = nullptr;
            return;
        }

        DoubleNode* current = tail->prev; //убрали while
        current->next = tail->next;
        delete tail;
        tail = current;
        tail->next = nullptr;
        tail->prev = current->prev;
    }

    void LTWODELvalue(string& value) {
        DoubleNode* node = head;
        if (head == nullptr) {
            //cout << "\nThe list is empty!" << endl;
            return;
        }
        if (head->cell == value) {
            LTWODELhead();
            return;
        }
        while (node != nullptr && node->cell != value) {
            node = node->next;
        }
        if (node == nullptr) {
            cout << "\nNo value found!" << endl;
            return;
        }
        if (node->prev) {
            node->prev->next = node->next;
        }
        else {
            head = node->prev;
        }
        if (node->next) {
            node->next->prev = node->prev;
        }
        else {
            tail = node->next;
        }

        delete node;

    }

    void LTWOSEARCH(string& value) {
        DoubleNode* node = head;
        if (head == nullptr) {
            cout << "\nThe list is empty!" << endl;
            return;
        }
        int index = 0;
        if (head->cell == value) {
            cout << "\nThe element is found! Index: " << index << endl;
            return;
        }
        while (node != nullptr && node->cell != value) {
            node = node->next;
            index++;
        }
        if (node == nullptr) {
            cout << "\nNo value found!" << endl;
            return;
        }
        cout << "\nThe element is found! Index: " << index << endl;

    }
    void LTWOREAD() {
        DoubleNode* node = head;
        if (head == nullptr) {
            cout << "\nThe list is empty!" << endl;
            return;
        }
        cout << endl;
        while (node != nullptr) {
            cout << node->cell << " ";
            node = node->next;
        }
        cout << endl;
    }
    void SaveToFile(string&name) {
        ofstream FileWrite(name);
        DoubleNode* current = head;
        while (current != nullptr) {
            FileWrite << current->cell << " ";
            current = current->next;
        }
        FileWrite.close();
    }

    void WritingFromFileToStructure(string& filename) {
        ifstream FileRead(filename);
        string tempValue;

        while (getline(FileRead, tempValue)) {
            stringstream ss(tempValue);
            string element;
            while (ss >> element) {
                LTWOPUSHtail(element);
            }
        }
        FileRead.close();
    }

    void BinarySerialization(string& filename) {
        ofstream FileWrite(filename, ios::binary);

        DoubleNode* current = head;

        while (current != nullptr) {
            int len = current->cell.size();
            FileWrite.write(reinterpret_cast<char*>(&len), sizeof(len)); //сначала записываем длины строк
            FileWrite.write(current->cell.c_str(), len); //затем записываем данные с начала туда до /0

            current = current->next;
        }
        FileWrite.close();
    }

    void BinaryDEserialization(string& filename) {
        ifstream fileRead(filename, ios::binary);

        DoubleNode* current = nullptr;
        DoubleNode* tail = nullptr;

        while (fileRead) {
            int len;
            fileRead.read(reinterpret_cast<char*>(&len), sizeof(len)); //чтение длины строки

            if (fileRead.eof())
                break;

            char* buffer = new char[len + 1];
            fileRead.read(buffer, len);
            buffer[len] = '\0';

            string text(buffer);

            LTWOPUSHtail(text);
            delete buffer;
        }
        fileRead.close();
    }

};

