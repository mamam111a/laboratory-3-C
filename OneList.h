#pragma once
#include "header.h"
#include <iostream>
#include <fstream>

using namespace std;

class OneList {
private:

    SingleNode* head = nullptr;
    SingleNode* tail = nullptr;
    SingleNode* predTail = nullptr; //добавили ссылку на пред хвост, чтобы убрать while 
public:

    ~OneList() {
        Clear();
    }
    int SearchForTest(string& value) {
        SingleNode* node = head;
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
    void LONEPUSHhead(string& cell) {

        SingleNode* node = new SingleNode;
        node->cell = cell;
        node->next = nullptr;

        if (head == nullptr) {
            head = tail = node;
            predTail = nullptr;/////////////
        }
        else {
            node->next = head;
            head = node;
            predTail = head->next;
        }
    }

    void LONEPUSHtail(string& cell) {

        SingleNode* node = new SingleNode;
        node->cell = cell;
        node->next = nullptr;
        if (tail == nullptr) {
            head = tail = node;
            predTail = nullptr;//////
        }
        else {
            tail->next = node;
            predTail = tail; ////////
            tail = node;

        }

    }

    void LONEDELhead() {
        if (head == nullptr) {
            //cout << "\nThe list is empty!" << endl;
            return;
        }
        SingleNode* node = head;
        head = head->next;
        delete node;
        if (head == nullptr) {
            tail = nullptr;
            predTail = nullptr;///////////////////
        }

    }
    void LONEDELtail() {
        if (head == nullptr) {
            //cout << "\nThe list is empty!" << endl;
            return;
        }
        if (head == tail) {
            delete head;
            head = tail = nullptr;
            predTail = nullptr;////////////////////
            return;
        }
        
        SingleNode* current = predTail; /////убрали while
        predTail->next = tail->next;
        delete tail;
        tail = current;
        tail->next = nullptr;
    }

    void LONEDELvalue(string& value) {

        if (head == nullptr) {
            //cout << "\nThe list is empty!" << endl;
            return;
        }

        SingleNode* node = head;
        if (head->cell == value) {
            LONEDELhead();
            return;
        }
        while (node != nullptr && node->next != nullptr && node->next->cell != value) {
            if (node == nullptr) {
                //cout << "\nNo value found!" << endl;
                return;
            }
            node = node->next;
        }

        SingleNode* toDelete = node->next;
        node->next = toDelete->next;
        if (toDelete == tail) {
            tail = toDelete;
            predTail->next = tail->next;/////////////
        }
        delete toDelete;
        tail = predTail;

    }

    void LONESEARCH(string& value) {
        SingleNode* node = head;
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
    void LONEREAD() {
        SingleNode* node = head;
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

    void WritingFromFileToStructure(string& filename) {
        ifstream FileRead(filename);
        string tempValue;

        while (getline(FileRead, tempValue)) {
            stringstream ss(tempValue);
            string element;
            while (ss >> element) {
                LONEPUSHtail(element);
            }
        }
        FileRead.close();
    }

    void WritingFromStructureToFile(string& filename) {
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
            FileWrite.write(reinterpret_cast<char*>(&len), sizeof(len)); //сначала записываем длины строк
            FileWrite.write(current->cell.c_str(), len); //затем записываем данные с начала туда до /0

            current = current->next;
        }
        FileWrite.close();
    }

    void BinaryDEserialization(string& filename) {
        ifstream fileRead(filename, ios::binary);

        while (fileRead) {
            int len;
            fileRead.read(reinterpret_cast<char*>(&len), sizeof(len)); //чтение длины строки

            if (fileRead.eof())
                break;

            char* buffer = new char[len + 1];
            fileRead.read(buffer, len);
            buffer[len] = '\0';

            string text(buffer);

            LONEPUSHtail(text);
            delete buffer;
        }
        fileRead.close();
    }
};


